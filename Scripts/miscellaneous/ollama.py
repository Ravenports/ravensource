#!/raven/bin/python
"""Helper script for ollama port - adds CMake dependency distfiles to specification.

Usage: python3 ollama.py <path_to_ollama_source|tarball_URL>

If a URL or tarball path is provided, the file will be downloaded/extracted automatically.
"""

import pathlib
import re
import sys


# Constants
LLAMA_CPP_VERSION_FILE = "LLAMA_CPP_VERSION"
MLX_VERSION_FILE = "MLX_VERSION"
MLX_C_VERSION_FILE = "MLX_C_VERSION"


def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <path_to_ollama_source|URL>")
        sys.exit(1)

    input_arg = sys.argv[1]
    
    # Check if it's a URL
    is_url = input_arg.startswith("http://") or input_arg.startswith("https://")
    
    source_path = pathlib.Path(input_arg)

    # If URL or tarball path, download/extract to temp directory
    temp_dir = None
    if is_url:
        import urllib.request
        import tempfile
        import shutil
        import subprocess

        print(f"Downloading {input_arg}...")

        with urllib.request.urlopen(input_arg) as response:
            with tempfile.NamedTemporaryFile(suffix='.tar.gz', delete=False) as tmp:
                shutil.copyfileobj(response, tmp)
                tarball_path = tmp.name

        temp_dir = pathlib.Path(tempfile.mkdtemp(prefix='ollama_'))
        print(f"Extracting to {temp_dir}...")

        subprocess.run(['tar', 'xzf', str(tarball_path), '-C', str(temp_dir)], check=True)

        # Find the extracted directory (should be ollama-<version>)
        source_path = temp_dir
        source_path = next(d for d in source_path.iterdir() if d.is_dir())

        # Clean up temp tarball
        pathlib.Path(tarball_path).unlink()

    elif input_arg.endswith('.tar.gz'):
        import tempfile
        import subprocess

        print(f"Extracting {input_arg}...")

        temp_dir = pathlib.Path(tempfile.mkdtemp(prefix='ollama_'))
        print(f"Extracting to {temp_dir}...")

        result = subprocess.run(['tar', 'xzf', input_arg, '-C', str(temp_dir)], capture_output=True)
        if result.returncode != 0:
            print(f"Error extracting tarball: {result.stderr.decode()}")
            sys.exit(1)

        # Find the extracted directory (should be ollama-<version>)
        dirs = [d for d in temp_dir.iterdir() if d.is_dir()]
        if not dirs:
            print("Error: No extracted directory found in tarball")
            sys.exit(1)
        source_path = dirs[0]

    version_file = source_path / LLAMA_CPP_VERSION_FILE
    if not version_file.exists():
        print(f"Error: {version_file} not found")
        sys.exit(1)

    # Read all version files
    try:
        with open(version_file) as f:
            llama_cpp_tag = f.read().strip()
        mlx_tag = (source_path / MLX_VERSION_FILE).read_text().strip()
        mlx_c_tag = (source_path / MLX_C_VERSION_FILE).read_text().strip()
    except Exception as e:
        print(f"Error reading version files: {e}")
        sys.exit(1)

    print("Processing ollama port...")
    print(f"  LLaMA C++ version: {llama_cpp_tag}")
    print(f"  MLX version: {mlx_tag}")
    print(f"  MLX-C version: {mlx_c_tag}")

    # Derive ravensource path (same pattern as golang_port.py)
    script_dir = pathlib.Path(__file__).resolve().parent
    # Script is in ravensource/Scripts/miscellaneous/, so go up 2 levels to get ravensource/
    ravensrc = script_dir.parent.parent

    # Load specification
    spec_file = ravensrc / "bucket_8E" / "ollama" / "specification"
    if not spec_file.exists():
        print(f"Error: {spec_file} not found")
        sys.exit(1)

    lines = spec_file.read_text().splitlines(keepends=True)

    # Find the highest mdXX number in SITES
    max_md = 0
    for i, line in enumerate(lines):
        match = re.match(r"^SITES\[md(\d+)\]", line)
        if match:
            num = int(match.group(1))
            if num > max_md:
                max_md = num

    llama_cpp_idx = max_md + 1
    mlx_idx = max_md + 2
    mlx_c_idx = max_md + 3

    #DISTFILE indices are offset by 1 from SITES md indices:
    # DISTFILE[94] corresponds to md93, so new entries need +1 offset
    llama_cpp_df_idx = llama_cpp_idx + 1
    mlx_df_idx = mlx_idx + 1
    mlx_c_df_idx = mlx_c_idx + 1

    # Check if already present in SITES section (before DISTFILE)
    sites_section_end_idx = None
    for i, line in enumerate(lines):
        if line.startswith("DISTFILE[1]="):
            sites_section_end_idx = i
            break

    current_sites = "".join(lines[:sites_section_end_idx])

    existing_entries = [
        f"GITHUB/ggml-org:llama.cpp:{llama_cpp_tag}",
        f"GITHUB/ml-explore:mlx:{mlx_tag}",
        f"GITHUB/ml-explore:mlx-c:{mlx_c_tag}",
    ]

    needs_addition = all(e not in current_sites for e in existing_entries)

    if not needs_addition:
        print("All additional distfiles are already present in specification")
        return

    # Add new SITES entries after the last one
    last_site_idx = None
    for i in reversed(range(sites_section_end_idx)):
        if re.match(r"^SITES\[md\d+\]", lines[i]):
            last_site_idx = i
            break

    llama_cpp_entry = f"SITES[md{llama_cpp_idx}]=\t\tGITHUB/ggml-org:llama.cpp:{llama_cpp_tag}\n"
    mlx_entry = f"SITES[md{mlx_idx}]=\t\tGITHUB/ml-explore:mlx:{mlx_tag}\n"
    mlx_c_entry = f"SITES[md{mlx_c_idx}]=\t\tGITHUB/ml-explore:mlx-c:{mlx_c_tag}\n"

    lines.insert(last_site_idx + 1, llama_cpp_entry)
    lines.insert(last_site_idx + 2, mlx_entry)
    lines.insert(last_site_idx + 3, mlx_c_entry)

    print(f"Added SITES entries for:")
    print(f"  - llama.cpp (md{llama_cpp_idx})")
    print(f"  - mlx (md{mlx_idx})")
    print(f"  - mlx-c (md{mlx_c_idx})")

    # Find and update DOWNLOAD_GROUPS line
    download_groups_line_idx = None
    for i, line in enumerate(lines):
        if line.startswith("DOWNLOAD_GROUPS="):
            download_groups_line_idx = i
            break

    if download_groups_line_idx is not None:
        # Build the new DOWNLOAD_GROUPS value with all md entries up to the highest
        groups_lines = []
        current_group_idx = download_groups_line_idx
        while current_group_idx < len(lines) and (lines[current_group_idx].strip().endswith('\\') or 'md' in lines[current_group_idx]):
            groups_lines.append(lines[current_group_idx])
            current_group_idx += 1

        # Parse existing groups and find the highest md number
        max_md_found = 0
        for line in groups_lines:
            matches = re.findall(r'md(\d+)', line)
            for m in matches:
                max_md_found = max(max_md_found, int(m))

        # The new entries start after max_md_found
        next_idx = max_md_found + 1

        # Rebuild DOWNLOAD_GROUPS with all groups up to the new highest
        all_groups = ["main"]
        for i in range(1, mlx_c_idx + 1):
            all_groups.append(f"md{i:02d}")

        # Format back to same style (10 per line)
        download_groups_formatted = []
        download_groups_formatted.append("DOWNLOAD_GROUPS=")

        num_per_line = 10
        chunks = [all_groups[i:i+num_per_line] for i in range(0, len(all_groups), num_per_line)]

        for idx, chunk in enumerate(chunks):
            if idx == 0:
                # First line: DOWNLOAD_GROUPS=\t(groups)
                indent = lines[download_groups_line_idx].split("DOWNLOAD_GROUPS=")[0]
                download_groups_formatted.append(f"{indent}\t{' '.join(chunk)}\n")
            else:
                # Continuation lines: <tab><tab><tab>groups (one more tab for alignment)
                download_groups_formatted.append(f"\t\t\t{' '.join(chunk)}\n")

        # Replace old DOWNLOAD_GROUPS section with new one
        lines[download_groups_line_idx:current_group_idx] = download_groups_formatted

    # Re-find DISTFILE section after SITES insertion
    distfile_start_idx = None
    for i, line in enumerate(lines):
        if line.startswith("DISTFILE[1]="):
            distfile_start_idx = i
            break

    # Find CMAKE_ARGS section and add FETCHCONTENT_SOURCE_DIR_LLAMA_CPP option
    cmake_args_end_idx = None
    for i, line in enumerate(lines):
        if line.startswith("CMAKE_ARGS="):
            cmake_args_end_idx = i
            # Continue to find end of CMAKE_ARGS block (next non-continued line)
            while cmake_args_end_idx + 1 < len(lines):
                next_line = lines[cmake_args_end_idx + 1]
                # Check if it's a continuation line (starts with tab) or new section
                if next_line.startswith("\t") and "=" in next_line:
                    cmake_args_end_idx += 1
                elif next_line.startswith("MAKE_ENV=") or next_line.startswith("post-patch:") or next_line.startswith("USES="):
                    break
                else:
                    cmake_args_end_idx += 1
            break

    if cmake_args_end_idx is not None:
        # Add the new FETCHCONTENT_SOURCE_DIR_LLAMA_CPP option on a continuation line
        llama_cpp_path = f"\t\t\t-DFETCHCONTENT_SOURCE_DIR_LLAMA_CPP=../llama.cpp-{llama_cpp_tag}\n"
        lines.insert(cmake_args_end_idx, llama_cpp_path)

    # Find post-patch section and add the patch command
    post_patch_idx = None
    for i, line in enumerate(lines):
        if line.startswith("post-patch:"):
            post_patch_idx = i
            break

    if post_patch_idx is not None:
        # Add the llama.cpp compat hook patch command on a new line after post-patch:
        patch_cmd = f"\tcd ${{WRKDIR}}/llama.cpp-{llama_cpp_tag} && patch -i ${{WRKSRC}}/llama/compat/001-llama-cpp-hooks.patch\n"
        lines.insert(post_patch_idx + 1, patch_cmd)

    distfile_end_idx = None
    for i in range(distfile_start_idx, len(lines)):
        if lines[i].startswith("DIST_SUBDIR=") or lines[i].startswith("DF_INDEX="):
            distfile_end_idx = i
            break

    # Find the last DISTFILE entry before DF_INDEX (using modified line numbers)
    last_distfile_idx = None
    for i in reversed(range(distfile_start_idx, distfile_end_idx)):
        if re.match(r"^DISTFILE\[\d+\]", lines[i]):
            last_distfile_idx = i
            break

    # Insert new DISTFILE entries after the last one
    llama_cpp_df = f"DISTFILE[{llama_cpp_df_idx}]=\t\tgenerated:md{llama_cpp_idx}\n"
    mlx_df = f"DISTFILE[{mlx_df_idx}]=\t\tgenerated:md{mlx_idx}\n"
    mlx_c_df = f"DISTFILE[{mlx_c_df_idx}]=\t\tgenerated:md{mlx_c_idx}\n"

    lines.insert(last_distfile_idx + 1, llama_cpp_df)
    lines.insert(last_distfile_idx + 2, mlx_df)
    lines.insert(last_distfile_idx + 3, mlx_c_df)

    print(f"Added DISTFILE entries:")
    print(f"  - DISTFILE[{llama_cpp_df_idx}] (md{llama_cpp_idx})")
    print(f"  - DISTFILE[{mlx_df_idx}] (md{mlx_idx})")
    print(f"  - DISTFILE[{mlx_c_df_idx}] (md{mlx_c_idx})")

    # Re-find DISTFILE section after insertions (indices have shifted)
    distfile_start_idx = None
    for i, line in enumerate(lines):
        if line.startswith("DISTFILE[1]="):
            distfile_start_idx = i
            break

    distfile_end_idx = None
    for i in range(distfile_start_idx, len(lines)):
        if lines[i].startswith("DIST_SUBDIR=") or lines[i].startswith("DF_INDEX="):
            distfile_end_idx = i
            break

    # Update DF_INDEX line
    for i in range(distfile_end_idx, len(lines)):
        if lines[i].startswith("DF_INDEX="):
            # Collect all existing indices from DISTFILE entries
            all_indices = []
            for line in lines:
                match = re.match(r"^DISTFILE\[(\d+)\]", line)
                if match:
                    all_indices.append(int(match.group(1)))

            sorted_indices = sorted(set(all_indices))

            # Rebuild DF_INDEX section - format with 10 indices per line like original
            new_df_lines = []
            indices_str = ' '.join(str(i) for i in sorted_indices)
            indices_list = indices_str.split()

            num_per_line = 10
            chunks = [indices_list[i:i+num_per_line] for i in range(0, len(indices_list), num_per_line)]

            for idx, chunk in enumerate(chunks):
                if idx == 0:
                    # First line: DF_INDEX=<tab><tab>indices
                    new_df_lines.append(f"DF_INDEX=\t\t{' '.join(chunk)}\n")
                else:
                    # Continuation lines: <tab><tab><tab>indices (one more tab for alignment)
                    new_df_lines.append(f"\t\t\t{' '.join(chunk)}\n")

            # Replace the old DF_INDEX section (line i and all continuation lines)
            end_idx = i + 1
            while end_idx < len(lines):
                line = lines[end_idx]
                stripped = line.lstrip()
                # Stop when we hit the start of a new section (SPKGS, OPTIONS, FPC_EQUIVALENT, etc.)
                if stripped.startswith("SPKGS[") or stripped.startswith("OPTIONS_AVAILABLE=") or stripped.startswith("FPC_EQUIVALENT="):
                    break
                end_idx += 1

            # Replace old lines with new ones (only the DF_INDEX block, not SPKGS or subsequent lines)
            lines[i:end_idx] = new_df_lines

    # Write back
    spec_file.write_text("".join(lines))

    print(f"Updated {spec_file}")
    
    # Clean up temp directory if we created one
    if temp_dir and temp_dir.exists():
        import shutil
        shutil.rmtree(temp_dir)

if __name__ == "__main__":
    main()
