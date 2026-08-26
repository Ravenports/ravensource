#!/raven/bin/python
"""
golang_port.py - Helper script for creating Go ports

Usage: python3 golang_port.py <distfile|URL> [--portname NAME] [--version VERSION]
"""

import sys
import os
import re
import subprocess
import urllib.request
import hashlib
import json as json_module
from pathlib import Path


# Constants
DEFAULT_TEMP_BASE = "/tmp/goport"
CACHE_DIR_NAME = "cache"
EXTRACT_DIR_NAME = "extract"

DOWNLOAD_GROUP_PREFIX = "md"

# Go toolchain path (must use /raven/bin/go on build systems)
GO_BIN = "/raven/bin/go"


def format_download_group(group_num):
    """Format a group number as mdYY or mdYYY.

    Args:
        group_num: Integer group number (1-based)

    Returns:
        String like "md01" or "md100"
    """
    if group_num < 100:
        return f"{DOWNLOAD_GROUP_PREFIX}{group_num:02d}"
    return f"{DOWNLOAD_GROUP_PREFIX}{group_num:03d}"


def format_df_index(indices):
    """Format DF_INDEX values with proper indentation.

    Args:
        indices: List of integer indices

    Returns:
        String with properly formatted DF_INDEX definition
    """
    # Group by 10 per line
    lines = []

    for i in range(0, len(indices), 10):
        chunk = indices[i:i+10]
        if i == 0:
            lines.append(f"DF_INDEX=\t\t{' '.join(str(n) for n in chunk)}")
        else:
            lines.append(f"\t\t\t{' '.join(str(n) for n in chunk)}")

    return "\n".join(lines)


def print_usage():
    """Print usage information and exit."""
    print("Usage: python3 golang_port.py <distfile|URL> [--portname NAME] [--version VERSION]")
    print("")
    print("Arguments:")
    print("  distfile|URL    Local tarball path or download URL (required)")
    print("  --portname NAME Override port name")
    print("  --version VER   Override version")
    sys.exit(1)


def parse_arguments(args):
    """Parse command line arguments."""
    if len(args) < 1:
        print_usage()
    
    positional = []
    portname_override = None
    version_override = None
    
    i = 0
    while i < len(args):
        arg = args[i]
        if arg == "--portname":
            if i + 1 >= len(args):
                print("Error: --portname requires a value")
                print_usage()
            portname_override = args[i + 1]
            i += 2
        elif arg == "--version":
            if i + 1 >= len(args):
                print("Error: --version requires a value")
                print_usage()
            version_override = args[i + 1]
            i += 2
        elif arg.startswith("-"):
            print(f"Error: Unknown argument '{arg}'")
            print_usage()
        else:
            positional.append(arg)
            i += 1
    
    if len(positional) != 1:
        print("Error: Exactly one positional argument required (distfile or URL)")
        print_usage()
    
    return positional[0], portname_override, version_override


def extract_name_version(distfile_path):
    """Extract port name and version from distfile filename."""
    basename = os.path.basename(distfile_path)

    if basename.endswith(".tar.gz"):
        basename = basename[:-7]
    elif basename.endswith(".tgz"):
        basename = basename[:-4]
    elif basename.endswith(".gz"):
        basename = basename[:-3]

    # Match pattern: name-version (e.g., ollama-0.32.15)
    match = re.match(r"^(.+?)-(.+)$", basename)
    if match:
        return match.group(1), match.group(2)

    # Alternative: file might be just a version (e.g., v0.32.15)
    # In this case, we can't determine the port name
    version_match = re.match(r"^v?\d+.*$", basename)
    if version_match:
        return None, basename

    return None, None


def parse_modules_txt(modules_txt_path):
    """Parse modules.txt and return list of (module_path, version) tuples."""
    dependencies = []
    
    with open(modules_txt_path, "r") as f:
        for line in f:
            line = line.strip()
            # Skip empty lines
            if not line:
                continue
            
            # Lines starting with # are comments: # module_path vX.Y.Z
            # These contain the version info we need
            match = re.match(r"^#\s*(\S+)\s+v(.+)$", line)
            if match:
                module_path = match.group(1)
                version = "v" + match.group(2)
                dependencies.append((module_path, version))
    
    return dependencies


def module_to_repo(module_path):
    """
    Convert a Go module path to a git repository URL.
    Handles special cases like gopkg.in, cloud.google.com, etc.
    Returns (repo_url, repo_type) where repo_type is 'github', 'gitlab', or 'generic'.
    """
    # Special case: golang.org/x/* modules are actually hosted on GitHub
    # The import path golang.org/x/foo maps to github.com/golang/foo
    if module_path.startswith("golang.org/x/"):
        repo_name = module_path[len("golang.org/x/"):]
        return f"https://github.com/golang/{repo_name}", "github"

    # Special case: google.golang.org/* modules are on GitHub
    if module_path.startswith("google.golang.org/"):
        remainder = module_path[len("google.golang.org/"):]
        parts = remainder.split("/")
        if len(parts) >= 1:
            repo_name = parts[0]
            # Map specific repos to their GitHub locations
            repo_map = {
                "protobuf": "protocolbuffers/protobuf-go",
                "appengine": "google/app-engine-go",  # or google/app-engine-package
                "genproto": "googleapis/go-genproto",
                "grpc": "grpc/grpc-go",
                "go": "google/rpc",
            }
            if repo_name in repo_map:
                return f"https://github.com/{repo_map[repo_name]}", "github"
            return f"https://github.com/google/{repo_name}", "github"

    # Handle gonum.org which is on GitHub at github.com/gonum/
    if module_path.startswith("gonum.org/"):
        remainder = module_path[len("gonum.org/"):]
        # Remove /v1, /v2, etc. suffix from remainder for GitHub repo path
        remainder = re.sub(r'^v\d+/', '', remainder)
        return f"https://github.com/gonum/{remainder}", "github"

    # Handle cloud.google.com which is on GitHub at googleapis repos
    if module_path.startswith("cloud.google.com/"):
        remainder = module_path[len("cloud.google.com/"):]
        parts = remainder.split("/")
        if len(parts) >= 1:
            repo_name = parts[0]
            # cloud.google.com/go -> github.com/googleapis/google-cloud-go
            if repo_name == "go":
                return f"https://github.com/googleapis/google-cloud-go", "github"
            return f"https://github.com/googleapis/{repo_name}", "github"

    # Handle go4.org which is hosted on GitHub but uses a different import path
    if module_path.startswith("go4.org/"):
        remainder = module_path[len("go4.org/"):]
        parts = remainder.split("/")
        if len(parts) >= 1:
            owner = "go4org"
            repo = "-".join(parts)
            return f"https://github.com/{owner}/{repo}", "github"

    # Handle gorgonia.org which is hosted on GitHub but uses a different import path
    if module_path.startswith("gorgonia.org/"):
        remainder = module_path[len("gorgonia.org/"):]
        parts = remainder.split("/")
        if len(parts) >= 1:
            owner = "gorgonia"
            repo = "-".join(parts)
            return f"https://github.com/{owner}/{repo}", "github"

    # gopkg.in is a hosted service that mirrors GitHub repos
    if module_path.startswith("gopkg.in/"):
        # Map known gopkg.in paths to GitHub owners and repos
        gopkg_map = {
            "yaml": ("go-yaml", "yaml"),
            "check": ("go-check", "check"),
            "mgo": ("go-mgo", "mgo"),  # deprecated, archived
            "nutsdb": ("gofrs", "nutsdb"),
            "relog": ("go-gcfg", "relog"),
        }

        remainder = module_path[len("gopkg.in/"):]
        repo_name = re.sub(r"\.v\d+$", "", remainder)

        if repo_name in gopkg_map:
            owner, repo = gopkg_map[repo_name]
            return f"https://github.com/{owner}/{repo}", "github"

        # Handle versions: gopkg.in/owner/repo.vN
        match = re.match(r"([^/]+)/(.+)\.v(\d+)$", remainder)
        if match:
            owner = match.group(1)
            repo = match.group(2)
            return f"https://github.com/{owner}/{repo}", "github"

        # Handle multi-segment paths like gopkg.in/owner/repo
        if "/" in remainder:
            parts = remainder.split("/")
            owner = parts[0]
            repo_version = parts[1] if len(parts) > 1 else ""
            repo = re.sub(r"\.v\d+$", "", repo_version)
            return f"https://github.com/{owner}/{repo}", "github"

        # Unknown gopkg.in path
        return None, None

    # GitHub patterns
    github_patterns = [
        r"github\.com/([^/]+)/([^/]+)",
        r"gopkg\.in/([^/]+)/(.+)\.v(\d+)$",
    ]

    for pattern in github_patterns:
        match = re.match(pattern, module_path)
        if match:
            if "gopkg.in" in pattern:
                # gopkg.in/owner/repo.vN -> github.com/owner/repo (tag N)
                owner = match.group(1)
                repo = match.group(2)
                return f"https://github.com/{owner}/{repo}", "github"
            else:
                # github.com/owner/repo
                owner = match.group(1)
                repo = match.group(2).removesuffix(".git")
                return f"https://github.com/{owner}/{repo}", "github"

    # Default: assume it's a git repository URL already or GitHub
    if module_path.startswith("https://") or module_path.startswith("git://"):
        return module_path, "generic"

    # Assume github for unknown paths (will fail but that's expected)
    parts = module_path.split("/")
    if len(parts) >= 2:
        owner = parts[0]
        repo = parts[1].removesuffix(".git")
        return f"https://{module_path}", "github"

    return None, None


def version_to_tag(version):
    """
    Convert Go version string to git tag.
    Examples:
        v0.32.5 -> v0.32.5
        v0.0.0-20180517000239-4f5cfb03fabf -> 4f5cfb03fabf (commit hash)
    """
    # Check if it's a pseudo-version (contains - with numbers after)
    match = re.match(r"v\d+\.\d+\.\d+-(\d{8})(\d{6})-([a-f0-9]+)$", version)
    if match:
        # Pseudo-version: use the commit hash
        return match.group(3)
    
    # Standard semver or pre-release tag
    return version


def generate_distfile_url(module_path, version):
    """
    Generate a download URL for a module's distfile.
    Returns URL for tar.gz (not zip) distfile.
    """
    repo_url, repo_type = module_to_repo(module_path)

    if not repo_url:
        return None

    tag = version_to_tag(version)

    # For GitHub/GitLab: use /archive/ or /releases/download/ URLs
    if repo_type == "github":
        # Use /archive/ for tags (works without releases being created)
        return f"{repo_url}/archive/refs/tags/{tag}.tar.gz"

    if repo_type in ("gitlab", "generic"):
        # For generic git repos, try standard patterns
        if "/_git/" in repo_url:
            # googlesource format
            return f"{repo_url}?format=tar.gz&h={tag}"
        # Fallback: releases download (requires release to exist)
        return f"{repo_url}/releases/download/{tag}/{os.path.basename(repo_url)}-{tag}.tar.gz"

    return None


def generate_distfiles(modules_txt_path):
    """
    Generate distfile URLs for all modules in modules.txt.
    Returns list of (module_path, version, url) tuples.
    """
    dependencies = parse_modules_txt(modules_txt_path)
    results = []

    for module_path, version in dependencies:
        url = generate_distfile_url(module_path, version)
        if url:
            results.append((module_path, version, url))

    return results


def generate_download_groups_block(num_distfiles, prefix="DOWNLOAD_GROUPS="):
    """Generate the DOWNLOAD_GROUPS definition block.

    Args:
        num_distfiles: Number of distfile URLs generated
        prefix: Line prefix (default: "DOWNLOAD_GROUPS=")

    Returns:
        String with properly formatted DOWNLOAD_GROUPS definition
    """
    # Build all groups
    groups = ["main"]
    for i in range(1, num_distfiles + 1):
        if i < 100:
            groups.append(f"{DOWNLOAD_GROUP_PREFIX}{i:02d}")
        else:
            groups.append(f"{DOWNLOAD_GROUP_PREFIX}{i:03d}")

    # Format in lines of 10
    lines = [f"{prefix} \\"]
    for i in range(0, len(groups), 10):
        chunk = groups[i:i+10]
        if i == 0:
            lines.append("\t\t" + " ".join(chunk))
        else:
            lines.append("\t\t\t" + " ".join(chunk))

    return "\n".join(lines) + "\n"


def download_file(url, dest_dir, dest_filename=None):
    """Download file from URL to destination directory."""
    Path(dest_dir).mkdir(parents=True, exist_ok=True)

    if dest_filename is None:
        # Extract filename from URL
        url_path = url.rstrip("/").split("/")[-1]
        # Remove query parameters
        url_path = url_path.split("?")[0]
        dest_filename = url_path

    dest_path = os.path.join(dest_dir, dest_filename)

    urllib.request.urlretrieve(url, dest_path)
    return dest_path


def extract_tarball(tarball_path, dest_dir):
    """Extract tarball to destination directory."""
    # Remove trailing slash if present
    dest_dir = dest_dir.rstrip("/")

    # Check if it's a gzip compressed tarball
    if tarball_path.endswith(".gz") or tarball_path.endswith(".tgz"):
        cmd = ["tar", "-xzf", tarball_path, "-C", dest_dir]
    else:
        cmd = ["tar", "-xf", tarball_path, "-C", dest_dir]

    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Error: Failed to extract tarball: {result.stderr}")
        sys.exit(1)


def download_distfile(url, dest_dir, cache_dir=None):
    """Download distfile from URL directly to cache directory.

    Args:
        url: The URL to download from (typically codeload.github.com)
        dest_dir: Not used in this version - downloads go to cache
        cache_dir: Directory where cached distfiles are stored

    Returns:
        Path to the downloaded file, and a boolean indicating if it was cached
    """
    # Extract filename from URL
    url_path = url.rstrip("/").split("/")[-1]
    # Remove query parameters
    url_path = url_path.split("?")[0]

    # Always use cache directory
    Path(cache_dir).mkdir(parents=True, exist_ok=True)
    dest_path = os.path.join(cache_dir, url_path)

    # Check if already cached
    if os.path.exists(dest_path):
        return dest_path, True

    print(f"Downloading {url} to cache")
    urllib.request.urlretrieve(url, dest_path)
    return dest_path, False


def extract_distfile(distfile_path, extract_dir, force_extract=False):
    """Extract a distfile to the extraction directory.

    Args:
        distfile_path: Path to the downloaded tarball
        extract_dir: Directory to extract to
        force_extract: If True, re-extract even if already extracted

    Returns:
        Path to the extracted directory (with version suffix removed) and a boolean indicating if it was cached
    """
    # Remove trailing slash if present
    extract_dir = extract_dir.rstrip("/")

    # Check if already extracted (cache hit)
    if not force_extract and os.path.exists(extract_dir):
        contents = list(Path(extract_dir).iterdir())
        dirs = [d for d in contents if d.is_dir()]
        if dirs:
            return str(dirs[0]), True

    # Clear extraction directory if it exists
    if os.path.exists(extract_dir):
        import shutil
        shutil.rmtree(extract_dir)

    Path(extract_dir).mkdir(parents=True, exist_ok=True)

    # Check if it's a gzip compressed tarball
    if distfile_path.endswith(".gz") or distfile_path.endswith(".tgz"):
        cmd = ["tar", "-xzf", distfile_path, "-C", extract_dir]
    elif distfile_path.endswith(".zip"):
        cmd = ["unzip", "-o", distfile_path, "-d", extract_dir]
    else:
        cmd = ["tar", "-xf", distfile_path, "-C", extract_dir]

    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Error: Failed to extract distfile: {result.stderr}")
        sys.exit(1)

    # List contents to find the extracted directory
    contents = list(Path(extract_dir).iterdir())

    # If exactly one directory exists, return that path
    dirs = [d for d in contents if d.is_dir()]
    if len(dirs) == 1:
        return str(dirs[0]), False

    # Otherwise return the extraction dir itself
    return extract_dir, False


def uses_subdirectory(module_dir, vendor_path):
    """Determine if a module uses subdirectories by checking vendor path structure.

    This function determines whether a Go module is stored in a nested directory
    structure. The key insight is that when a module like github.com/charmbracelet/x/ansi
    has its code actually in an `ansi` subdirectory, the extracted structure will be:
        vendor/github.com/charmbracelet/x/ansi/ansi/go.mod

    Instead of:
        vendor/github.com/charmbracelet/x/ansi/go.mod

    This is detected by checking if the last component of the vendor path (e.g., "ansi")
    exists as a subdirectory within module_dir and contains a go.mod file.

    Args:
        module_dir: Path to the extracted module directory
        vendor_path: The vendor path from SITES definition (e.g., "vendor/github.com/charmbracelet/x/ansi")

    Returns:
        Tuple of (uses_subdir, reason) where:
            - uses_subdir: True if subdirectories are used
            - reason: Description of what was detected
    """
    if not os.path.isdir(module_dir):
        return False, "Not a directory", None

    # Get the last component of the vendor path
    # e.g., "vendor/github.com/charmbracelet/x/ansi" -> "ansi"
    path_parts = vendor_path.split(os.sep)
    if not path_parts:
        return False, "Invalid vendor path", None

    last_component = path_parts[-1]

    # Check if module_dir contains a subdirectory named last_component with go.mod
    # Walk the tree to handle nested cases (e.g., arrow might be at go/arrow/)
    for root, dirs, files in os.walk(module_dir):
        # Skip hidden directories and common non-source directories
        rel_path = os.path.relpath(root, module_dir)
        path_parts_check = rel_path.split(os.sep)
        if any(p.startswith('.') or p in ('example', 'examples', 'doc', 'docs', 'fuzz', 'testdata') for p in path_parts_check):
            continue
        if root == module_dir:
            # At root level, check direct subdirectory with matching name
            subdir_path = os.path.join(module_dir, last_component)
            if os.path.isdir(subdir_path) and os.path.exists(os.path.join(subdir_path, "go.mod")):
                return True, f"Subdirectory '{last_component}' found with go.mod", last_component
        else:
            # At nested level, check if current dir has the matching name and go.mod
            basename = os.path.basename(root)
            if basename == last_component and os.path.exists(os.path.join(root, "go.mod")):
                rel_to_module = os.path.relpath(root, module_dir)
                return True, f"Subdirectory '{rel_to_module}/' contains go.mod", rel_to_module

    return False, "All content at root level (no matching subdirectory with go.mod)", None


def download_and_extract_distfile(url, temp_dir, cache_dir=None):
    """Download and extract a distfile from codeload.github.com.

    This function downloads the distfile from the given URL to a temporary
    directory, then extracts it. This is useful for inspecting the module
    structure before generating port specifications.

    Args:
        url: The download URL (e.g., https://codeload.github.com/owner/repo/tar.gz/v1.0.0)
        temp_dir: Not used - extraction goes to temp, downloads go to cache
        cache_dir: Directory where cached distfiles are stored

    Returns:
        Path to the extracted module directory and a boolean indicating if cached
    """
    # Download directly to cache
    distfile_path, was_cached = download_distfile(url, None, cache_dir)

    # Extract from cache
    extract_dir = os.path.join(temp_dir, "extracted")
    module_dir, extract_cached = extract_distfile(distfile_path, extract_dir, force_extract=False)

    return module_dir, was_cached or extract_cached


def sites_to_url(sites_def):
    """Convert a SITES definition to a download URL.

    The SITES definition format is:
        SITES[mdXX]=\t\tGITHUB/owner:repo:tag:vendor/path

    This function converts it to a codeload.github.com URL for downloading
    the distfile. The last field (vendor path) is disregarded.

    Args:
        sites_def: A SITES definition string (e.g., "SITES[md01]=\t\tGITHUB/klauspost:cpuid:v1.0.0:vendor/path")

    Returns:
        A valid download URL for codeload.github.com, or None if parsing fails
    """
    # The format is SITES[mdXX]=<tabs>GITHUB/owner:repo:tag:vendor/path
    # First, remove the "SITES[...]=" prefix and any leading whitespace/tabs
    
    # Split on first = to get the value part
    parts_equal = sites_def.split("=", 1)
    if len(parts_equal) != 2:
        print(f"Error: Invalid SITES definition (missing =): {sites_def}")
        return None
    
    # Remove leading tabs/whitespace from the value
    site_value = parts_equal[1].lstrip()
    
    # The GITHUB/ prefix followed by owner:repo:tag:vendor/path
    if not site_value.startswith("GITHUB/"):
        print(f"Error: SITES definition must use GITHUB/: {sites_def}")
        return None
    
    # Remove "GITHUB/" and split the rest by colon
    remainder = site_value[7:]  # Remove "GITHUB/"
    parts_colon = remainder.split(":")
    
    if len(parts_colon) < 3:
        print(f"Error: Invalid SITES definition (need owner:repo:tag): {sites_def}")
        return None

    # First field is owner, second is repo, third is tag
    owner = parts_colon[0]
    repo = parts_colon[1]
    tag = parts_colon[2]

    # Build the codeload.github.com URL with dummy parameter
    # The dummy parameter helps some tools infer the filename correctly
    url = f"https://codeload.github.com/{owner}/{repo}/tar.gz/{tag}?dummy=/{owner}-{repo}-{tag}.tar.gz"

    return url

def main():
    # Parse arguments
    distfile_arg, portname_override, version_override = parse_arguments(sys.argv[1:])
    
    # Check if it's a URL or local file
    is_url = distfile_arg.startswith("http://") or distfile_arg.startswith("https://")
    
    # Determine port name and version
    portname = None
    version = None

    if not is_url:
        # Local file - extract from filename
        if os.path.exists(distfile_arg):
            portname, version = extract_name_version(distfile_arg)
        else:
            print(f"Error: File not found: {distfile_arg}")
            sys.exit(1)

    # Apply overrides if provided
    if portname_override:
        portname = portname_override
    if version_override:
        version = version_override

    # Auto-extract version from GitHub archive URL if not provided
    if is_url and not version:
        version_match = re.search(r'/tags/([^/?]+)', distfile_arg)
        if version_match:
            version = version_match.group(1).removesuffix('.tar.gz').lstrip('v')
            print(f"Auto-detected version: {version}")

    # Auto-extract portname from GitHub URL if not provided
    if is_url and not portname:
        # Try to extract owner/repo from GitHub URLs
        gh_match = re.search(r'github\.com/([^/]+)/([^/]+)', distfile_arg)
        if gh_match:
            owner, repo = gh_match.groups()
            portname = repo.rstrip('.git')
            print(f"Auto-detected port name: {portname}")

    # Validate that both portname and version are set
    if not portname:
        print("Error: Could not extract port name from filename or URL")
        print("       Use --portname NAME to override")
        sys.exit(1)
    
    if not version:
        print("Error: Could not extract version from filename or URL")
        print("       Use --version VER to override")
        sys.exit(1)

    # Step 3: Create temp directory based on DEFAULT_TEMP_BASE constant
    goport_dir = DEFAULT_TEMP_BASE
    Path(goport_dir).mkdir(parents=True, exist_ok=True)
    
    # Cache directory for downloaded distfiles (persists between runs)
    # All downloads go directly to cache; extraction uses temp directories from there
    cache_dir = os.path.join(goport_dir, CACHE_DIR_NAME)
    Path(cache_dir).mkdir(parents=True, exist_ok=True)

    # Download if URL
    local_distfile = distfile_arg
    if is_url:
        print(f"Downloading {distfile_arg}...")
        try:
            local_distfile = download_file(distfile_arg, goport_dir)
            print("Download complete")
        except Exception as e:
            print(f"Error: Download failed: {e}")
            sys.exit(1)

    # Step 4: Ensure DEFAULT_TEMP_BASE/extract is empty
    extract_dir = os.path.join(goport_dir, EXTRACT_DIR_NAME)
    if os.path.exists(extract_dir):
        import shutil
        shutil.rmtree(extract_dir)
    Path(extract_dir).mkdir(parents=True)

    print(f"Extracting distfile...")
    # Extract the distfile
    extract_tarball(local_distfile, extract_dir)
    print("Extraction complete")

    # Step 5: Calculate bucket and validate port directory
    if portname:
        # Calculate SHA-1 hash of portname
        sha1_hash = hashlib.sha1(portname.encode()).hexdigest()[:2].upper()
        bucket = f"bucket_{sha1_hash}"

        # Port directory is in the ravensource repository (relative to script location)
        # Script is in ravensource/Scripts/assembler/, so go up 2 levels to get ravensource/
        import pathlib
        ravensource = pathlib.Path(__file__).resolve().parent.parent.parent
        port_dir = os.path.join(ravensource, bucket, portname)

        if not os.path.exists(port_dir):
            print(f"Error: Port directory does not exist: {port_dir}")
            sys.exit(1)

        # Ensure files subdirectory exists
        files_dir = os.path.join(port_dir, "files")
        if not os.path.isdir(files_dir):
            print(f"Error: Port missing 'files' subdirectory: {files_dir}")
            sys.exit(1)

        # Load spec_template for distfile counting
        spec_template = os.path.join(port_dir, "specification.template")

        # Count existing DISTFILE entries in template
        distfile_count = 0
        with open(spec_template, "r") as f:
            for line in f:
                if re.match(r"^DISTFILE\[\d+\]", line.strip()):
                    distfile_count += 1

    # Step 6: Call go mod vendor -v
    if portname and version:
        print(f"Running 'go mod vendor -v' for {portname}-{version}...")
        # Strip leading 'v' from version for directory path (extracted dirs don't include it)
        dir_version = version.lstrip('v')
        extract_subdir = os.path.join(extract_dir, f"{portname}-{dir_version}")

        # Run go mod vendor in the extracted directory
        result = subprocess.run(
            [GO_BIN, "mod", "vendor", "-v"],
            cwd=extract_subdir,
            capture_output=True,
            text=True
        )

        if result.returncode != 0:
            print(f"Error: 'go mod vendor' failed: {result.stderr}")
            sys.exit(1)

        print("Vendor directory created successfully")

        # Copy modules.txt to theport's files directory
        modules_txt = os.path.join(extract_subdir, "vendor", "modules.txt")
        dest_modules_txt = os.path.join(files_dir, "modules.txt")

        if os.path.exists(modules_txt):
            with open(modules_txt, "r") as src:
                content = src.read()
            with open(dest_modules_txt, "w") as dst:
                dst.write(content)
            print(f"Updated {dest_modules_txt}")
        else:
            print(f"Warning: modules.txt not found at {modules_txt}")

    # Step 9-11: Generate distfile URLs from modules.txt
    distfiles = []  # Initialize to empty list for error case handling

    if portname and version:
        # Strip leading 'v' from version for directory path
        dir_version = version.lstrip('v')
        extract_subdir = os.path.join(extract_dir, f"{portname}-{dir_version}")

        # Run go list -deps to get all dependencies
        # Force CGO_ENABLED=1 since we need to analyze all dependencies including those with cgo
        env = os.environ.copy()
        env["CGO_ENABLED"] = "1"
        result = subprocess.run(
            [GO_BIN, "list", "-deps", "./..."],
            cwd=extract_subdir,
            capture_output=True,
            text=True,
            env=env
        )

        if result.returncode != 0:
            sys.exit(1)

        modules_found = len(result.stdout.strip().split("\n"))
        print(f"Found {modules_found} modules")

        # Parse the output for module paths
        all_deps = set()
        for line in result.stdout.strip().split("\n"):
            line = line.strip()
            if line and not line.startswith("#"):
                all_deps.add(line)

        # Get versions from vendor/modules.txt
        modules_txt_path = os.path.join(extract_subdir, "vendor", "modules.txt")
        deps_versions = parse_modules_txt(modules_txt_path)

        # Generate distfile URLs
        print("Generating distfile URLs for dependencies...")
        distfiles = generate_distfiles(modules_txt_path)

        # Output results in format for specification template markers
        md_sites_entries = []
        md_distfiles_entries = []
        for i, (module_path, dep_version, url) in enumerate(distfiles):
            # Create distfile name: dist_0001, dist_0002, etc.
            distfile_name = f"dist_{i+1:04d}"

            # Determine download group based on module host
            host_parts = module_path.split("/")
            if len(host_parts) >= 2:
                host = host_parts[0]
            else:
                host = "unknown"

            # Assign to mdYY groups starting with md01
            group_num = i + 1
            download_group = format_download_group(group_num)

            # Generate site URL (repository, not tarball)
            # First query Go proxy API for precise module info including subdirectory
            full_tag = version_to_tag(dep_version)
            module_info = {}
            origin_url = None
            try:
                proxy_url = f"https://proxy.golang.org/{module_path}/@v/{dep_version}.info"
                with urllib.request.urlopen(proxy_url, timeout=10) as response:
                    module_info = json_module.loads(response.read().decode('utf-8'))
            except Exception:
                pass

            # Use origin URL if available (handles subdirectory modules like github.com/owner/repo/subdir)
            origin = module_info.get("Origin", {})
            origin_url_from_api = origin.get("URL", "")

            if origin_url_from_api:
                # Convert the origin URL back to a module path for module_to_repo
                origin_module_path = None

                # Handle googlesource.com URLs (e.g., golang.org/x modules hosted there)
                import re as re_mod
                googlesource_match = re_mod.match(r'https://([^/]+\.googlesource\.com)/(.+)$', origin_url_from_api)
                if googlesource_match:
                    host_part = googlesource_match.group(1)  # e.g., go.googlesource.com
                    repo_name = googlesource_match.group(2)   # e.g., arch/protobuf

                    # Try to convert based on the original module path pattern
                    origin_module_path = None

                    # google.golang.org/* modules get converted based on their mapping
                    if module_path.startswith("google.golang.org/"):
                        remainder = module_path[len("google.golang.org/"):]
                        parts = remainder.split("/")
                        if len(parts) >= 1:
                            repo_name_from_module = parts[0]
                            # Use the original module path for lookup - module_to_repo will handle mapping
                            origin_module_path = f"google.golang.org/{repo_name_from_module}"

                    # golang.org/x/* modules get converted to github.com/golang/*
                    elif module_path.startswith("golang.org/x/"):
                        repo_name_from_module = module_path[len("golang.org/x/"):]
                        origin_module_path = f"golang.org/x/{repo_name_from_module}"

                if origin_module_path is None:
                    # Convert standard https://github.com URLs to module path format
                    # e.g., "https://github.com/charmbracelet/x" -> "github.com/charmbracelet/x"
                    origin_module_path = origin_url_from_api.replace("https://", "").replace("http://", "")

                repo_url, _ = module_to_repo(origin_module_path)
                origin_url = origin_url_from_api
            else:
                repo_url, _ = module_to_repo(module_path)

            # Extract owner/repo from github.com url
            if "github.com" in repo_url:
                repo_part = repo_url.split("github.com/")[1].rstrip("/")
            else:
                # Fallback for other repos - use the full path after first segment
                parts = repo_url.replace("/", " ").split()
                if len(parts) >= 2:
                    repo_part = "/".join(parts[-2:])
                else:
                    repo_part = module_path

            # Extract tag from version using helper function
            # For pseudo-versions, this returns just the commit hash
            # For regular versions, this keeps them as-is (e.g., v1.0.3)

            # Use commit hash from proxy API (avoids issues with subdirectory prefixes in tags)
            origin = module_info.get("Origin", {})
            git_hash = origin.get("Hash", "")
            tag_ref = origin.get("Ref", "")  # e.g., "refs/tags/ansi/v0.10.1"

            if git_hash:
                full_tag = git_hash
            elif tag_ref and "/tags/" in tag_ref:
                # Extract the tag name from refs/tags/<tagname>
                # This handles subdirectory prefixes like ansi/v0.10.1
                full_tag = tag_ref.split("/tags/")[-1]
            else:
                full_tag = version_to_tag(dep_version)

            # Construct vendor path - use the original module path (no modification)
            # The SITES entry needs GitHub mapping for download, but vendor directory
            # must retain the original module path structure
            vendor_path = module_path

            # Format repo_part with colon separator: owner:repo
            # Convert "github.com/owner/repo" to "owner:repo"
            if "/" in repo_part:
                parts = [p for p in repo_part.split("/") if p]  # Filter empty strings
                if len(parts) >= 2:
                    repo_part = f"{parts[-2]}:{parts[-1]}"
                else:
                    repo_part = repo_part.replace("/", ":")

            # Format with tab separators (Ravenports uses tabs, not spaces)
            md_sites_entries.append(f"SITES[{download_group}]=\t\tGITHUB/{repo_part}:{full_tag}:vendor/{vendor_path}")

            # Generate distfile entry - add to template's existing entries
            distfile_num = distfile_count + i + 1
            download_group_md = format_download_group(group_num)
            md_distfiles_entries.append(f"DISTFILE[{distfile_num}]=\t\tgenerated:{download_group_md}")

        # Calculate total distfiles (static from template + generated modules)
        total_distfiles = distfile_count + len(distfiles)

        # Format df_index for %%DF_INDEX%% marker (grouped by 10)
        df_index_numbers = list(range(1, total_distfiles + 1))
        df_index_str = format_df_index(df_index_numbers)

    # Step 7: Validate specification.template markers
    spec_template = os.path.join(port_dir, "specification.template")

    if not os.path.exists(spec_template):
        print(f"Error: specification.template not found: {spec_template}")
        sys.exit(1)

    required_markers = ["%%VERSION%%", "%%DOWNLOAD_GROUPS%%", "%%MD_SITES%%",
                       "%%MD_DISTFILES%%", "%%DF_INDEX%%"]

    with open(spec_template, "r") as f:
        template_content = f.read()

    missing_markers = [m for m in required_markers if m not in template_content]
    if missing_markers:
        print(f"Error: Missing required markers in template: {missing_markers}")
        sys.exit(1)

    # Step 8: Copy template to specification with marker handling
    spec_file = os.path.join(port_dir, "specification")

    def replace_marker(line, version):
        """Replace markers in a line."""
        if "%%VERSION%%" in line:
            return line.replace("%%VERSION%%", version)
        elif "%%DOWNLOAD_GROUPS%%" in line:
            num_distfiles = len(distfiles) if distfiles else 0
            return generate_download_groups_block(num_distfiles)
        elif "%%MD_SITES%%" in line:
            return "\n".join(md_sites_entries) + "\n"
        elif "%%DF_INDEX%%" in line:
            return df_index_str
        # For %%MD_DISTFILES%% - handled separately by looking for DISTFILE entries
        return line

    print(f"Generating specification with {len(distfiles)} distfile(s)...")

    # Extract modules to detect subdirectories before writing spec
    print("Extracting distfiles to detect subdirectories...")

    subdir_info = {}  # index -> (vendor_path, module_dir) for modules with subdirs

    for i, (module_path, dep_version, _) in enumerate(distfiles):
        download_group = format_download_group(i + 1)

        # Find the SITES entry for this group
        sites_entry = None
        for entry in md_sites_entries:
            if entry.startswith(f"SITES[{download_group}]="):
                sites_entry = entry
                break

        if not sites_entry:
            continue

        site_value = sites_entry.split("=", 1)[1].lstrip()
        sites_fields = site_value.split(":")
        if len(sites_fields) >= 4:
            vendor_path = ":".join(sites_fields[3:])
        else:
            continue

        url = sites_to_url(sites_entry)
        if not url:
            continue

        temp_dir = os.path.join(goport_dir, f"dist_detect_{i+1:04d}")
        try:
            module_dir, _ = download_and_extract_distfile(url, temp_dir, cache_dir)

            uses_subdir, reason, source_path = uses_subdirectory(module_dir, vendor_path)
            if uses_subdir:
                # Store: vendor_path, module_dir, and the subdirectory path containing go.mod
                subdir_info[i] = (vendor_path, module_dir, source_path)
        except Exception as e:
            print(f"  Warning: Failed to extract for subdir detection ({module_path}): {e}")
            continue

    # Apply +subdir suffix to SITES entries that need it
    if subdir_info:
        for idx, (vendor_path, module_dir, source_path) in subdir_info.items():
            if idx < len(md_sites_entries):
                entry = md_sites_entries[idx]
                site_value = entry.split("=", 1)[1].lstrip()
                sites_fields = site_value.split(":")
                if len(sites_fields) >= 4:
                    new_vendor_path = vendor_path + "+subdir"
                    prefix_fields = sites_fields[:3]
                    new_site_value = ':'.join(prefix_fields) + ":" + new_vendor_path
                    md_sites_entries[idx] = entry.replace(site_value, new_site_value)

    # Build post-patch symlink commands for modules with subdirectories
    post_patch_symlinks = []
    if subdir_info:
        for idx, (vendor_path, module_dir, source_path) in subdir_info.items():
            # Construct the symlink command
            expected_path = "${WRKSRC}/" + vendor_path  # What Go imports expect
            actual_path = "${WRKSRC}/" + vendor_path + "+subdir/" + source_path  # Where it's actually extracted
            post_patch_symlinks.append(f"\t${{LN}} -s {actual_path} {expected_path}")

    with open(spec_template, "r") as src:
        lines = src.readlines()

    # Track whether we've written md_distfiles (we'll do this separately)
    distfile_lines_written = False

    spec_lines = []
    in_post_patch = False
    for line in lines:
        if "%%MD_DISTFILES%%" in line and not distfile_lines_written:
            # Write all DISTFILE entries
            for entry in md_distfiles_entries:
                spec_lines.append(entry + "\n")
            distfile_lines_written = True
        else:
            spec_lines.append(replace_marker(line, version))

    # Find where to place symlink commands: either in pre-existing post-patch or at end
    has_post_patch = any(line.strip().startswith("post-patch:") for line in lines)

    if post_patch_symlinks:
        if not has_post_patch:
            # No existing post-patch section - add at end
            spec_lines.append("\npost-patch:\n")
            for cmd in post_patch_symlinks:
                spec_lines.append(cmd + "\n")
        else:
            # Insert into existing post-patch section
            new_spec_lines = []
            in_post_patch = False
            added_symlinks = False
            for i, line in enumerate(spec_lines):
                if line.strip().startswith("post-patch:"):
                    in_post_patch = True
                    new_spec_lines.append(line)
                elif in_post_patch and not added_symlinks:
                    # Found first line after post-patch header - insert symlinks now
                    for cmd in post_patch_symlinks:
                        new_spec_lines.append(cmd + "\n")
                    added_symlinks = True
                    new_spec_lines.append(line)
                else:
                    new_spec_lines.append(line)
            spec_lines = new_spec_lines

    with open(spec_file, "w") as dst:
        dst.writelines(spec_lines)

    print(f"Port specification written to {spec_file}")

    if subdir_info:
        print("\nModules with subdirectories (detected during generation):")
        for idx, (vendor_path, module_dir, source_path) in subdir_info.items():
            download_group = format_download_group(idx + 1)
            print(f"  {download_group}: {vendor_path}")
    else:
        print("\n(No modules with subdirectories detected)")

if __name__ == "__main__":
    main()
