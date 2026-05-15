#!/raven/bin/python
#
# Generate rust rust port provided a Cargo.lock file, port name, and version.
# There must be a file named "specification.template" in the port's directory.
#
# Arguments:
#   1. portname
#   2. version
#   3. path/to/Cargo.lock

import os
import pathlib
import re
import sys
import subprocess

RAVENSRC = pathlib.Path(__file__).resolve().parent.parent.parent

def check_arguments():
    """
    Returns (None, None, None) if:
       - less than 3 arguments given
       - portname doesn't reflect an existing directory
       - argument 3 isn't a readable file
       - argument 3 filename is not Cargo.lock
       - specification.template doesn't exist in portname directory
    otherwise return tuple:
       - path/to/portname/directory
       - version (arg2 passthrough)
       - path/to/Cargo.lock (arg3 passthrough)
    """
    keep_going = False
    if len(sys.argv) > 3:
        lockfile = pathlib.Path(sys.argv[3])
        if lockfile.is_file() and os.access(lockfile, os.R_OK):
            if lockfile.name == "Cargo.lock":
                keep_going = True
            else:
                print(f"{sys.argv[3]} filename is not 'Cargo.lock'")
        else:
            print(f"{sys.argv[3]} does not exist or is not a readable file")
    else:
        print("Not enough arguments were provided.")
        print("Usage: rust_port.py <portname> <version> <path/to/Cargo.lock file>")
    if keep_going:
        try:
            result = subprocess.run(
                ["/raven/bin/ravenadm", "locate", sys.argv[1]],
                stdout=subprocess.PIPE,
                stderr=subprocess.STDOUT,
                text=True,
                check=True
            )
            location = result.stdout.strip()
            if location.startswith("Found at "):
                _, _, trailing_path = location.partition("bucket_")
                folder = f"{RAVENSRC}/bucket_{trailing_path}"
                template = pathlib.Path(f"{folder}/specification.template")
                if template.is_file() and os.access(template, os.R_OK):
                    return (folder, sys.argv[2], sys.argv[3])
                else:
                    print(f"Expected file {str(template)} is missing")
            else:
                print(f"${sys.argv[1]} is not valid port name.")
        except (subprocess.CalledProcessError, OSError):
            print(f"Failed to call ravenadm locate {sys.argv[1]}")
        
    return (None, None, None)


def read_lockfile(lockfile):
    """
    Read Cargo.lock line by line
    return tuple (crate list of dict, repo list of dict)
    """
    crates = []
    repos = {}
    name = None
    version = None
    repo_pattern = re.compile(
        r'github\.com/(?P<org>[^/]+)/(?P<project>[^?#"]+).*tag=(?P<tag>[^#"]+)'
    )
    with open(lockfile, "r", encoding="utf-8") as fin:
        for line in fin:
            sline = line.rstrip("\n")
            if sline.startswith('name = "'):
                name = sline.split('"')[1]
            elif sline.startswith('version = "'):
                version = sline.split('"')[1]
            elif sline.startswith('source = "'):
                source = sline.split('"')[1]
                if source.startswith("registry+"):
                    if name is not None and version is not None:
                        mydict = {"name": name, "version": version}
                        crates.append(mydict)
                    name = None
                    version = None
                elif source.startswith("git+"):
                    match = repo_pattern.search(source)
                    if match and name is not None and version is not None:
                        data = match.groupdict()
                        key = f"https://github.com/{data['org']}/{data['project']}"
                        if key in repos:
                            repos[key]["crates"].append(name)
                        else:
                            data["crates"] = [name]
                            repos[key] = data
                    name = None
                    version = None                     
    return (crates, repos)


def gh_crate_path(project, tag, name):
    """
    Determine the path to the crate in the github repository.
    Github will transform tags starting with "v", so account for that.
    sys.argv[1] is the verified portname
    """
    new_tag = tag
    if len(tag) > 1 and tag[0] == "v" and tag[1].isdigit():
        new_tag = tag[1:]  # Strips the first character ('v')
    return f"/construction/{sys.argv[1]}/{project}-{new_tag}/crates/{name}"
    

def create_extra_config_toml(folder, repos):
    """
    If crates is not empty, create ${FILESDIR}/config.toml
    """
    filesdir = pathlib.Path(f"{folder}/files")
    config_toml = pathlib.Path(filesdir / "config.toml")
    if not repos:
        config_toml.unlink(missing_ok=True)
        return

    filesdir.mkdir(parents=True, exist_ok=True)
    with config_toml.open("w", encoding="utf-8") as fout:
        fout.write("\n")
        fout.write("[net]\n")
        fout.write("offline = true\n")
        fout.write("\n")
        for key in repos.keys():
            fout.write(f'[patch."{key}"]\n')
            project = repos[key]["project"]
            tag = repos[key]["tag"]
            for name in repos[key]["crates"]:
                path = gh_crate_path(project, tag, name)
                fout.write(f'{name} = {{path = "{path}"}}\n')


def download_groups(crates, repos):
    """
    return the download groups block.
    All crates start with "cr", and the followed by an ordinal number starting with 1.
    If the number is less than 10 it is zero padded.
    If there are any repos, this download groups start with "gh" but continue
    increasing the ordinal count.
    There are 10 groups per line, but the very first group is always "main"
    """
    block = "DOWNLOAD_GROUPS=\tmain"
    counter = 1
    index = 0
    for crate in crates:
        counter = counter + 1
        index = index + 1
        chunk = f"\n\t\t\tcr{index:02d}" if (counter - 1) % 10 == 0 else f" cr{index:02d}"
        block = block + chunk
    for repo in repos:
        counter = counter + 1
        index = index + 1
        chunk = f"\n\t\t\tgh{index:02d}" if (counter - 1) % 10 == 0 else f" gh{index:02d}"
        block = block + chunk
    block = block + "\n"
    return block


def cr_sites(crates, repos):
    """
    Return the site definitions for the download groups defined in download_groups()
    """
    block = ""
    index = 0
    for crate in crates:
        index = index + 1
        chunk = f"SITES[cr{index:02d}]=\t\tCRATES/{crate['name']}:{crate['version']}\n"
        block = block + chunk
    for repo in repos:
        index = index + 1
        org = repos[repo]["org"]
        project = repos[repo]["project"]
        tag = repos[repo]["tag"]
        chunk = f"SITES[gh{index:02d}]=\t\tGITHUB/{org}:{project}:{tag}\n"
        block = block + chunk
    return block     


def cr_distfiles(crates, repos):
    """
    return "generated" distfile information for each crate and distfile
    """
    block = ""
    index = 0
    counter = 1
    for crate in crates:
        index = index + 1
        counter = counter + 1
        chunk = f"DISTFILE[{counter}]=\t\tgenerated:cr{index:02d}\n"
        block = block + chunk
    for repo in repos:
        index = index + 1
        counter = counter + 1
        chunk = f"DISTFILE[{counter}]=\t\tgenerated:gh{index:02d}\n"
        block = block + chunk
    return block


def df_index(crates, repos):
    """
    return block of DF index definitions
    """
    block = "DF_INDEX=\t\t1"
    counter = 1
    index = 1
    for crate in crates:
        counter = counter + 1
        index = index + 1
        chunk = f"\n\t\t\t{index}" if (counter - 1) % 10 == 0 else f" {index}"
        block = block + chunk
    for repo in repos:
        counter = counter + 1
        index = index + 1
        chunk = f"\n\t\t\t{index}" if (counter - 1) % 10 == 0 else f" {index}"
        block = block + chunk
    block = block + "\n"
    return block


def generate_spec_sheet(crates, repos, folder, version):
    """
    Create a new specsheet by taking the template and replacing the "%%" variables.
    Delete any crates.list file found
    """
    specsheet = pathlib.Path(f"{folder}/specification")
    template = pathlib.Path(f"{folder}/specification.template")
    clist = pathlib.Path(f"{folder}/crates.list")
    clist.unlink(missing_ok=True)

    with specsheet.open("w", encoding="utf-8") as spec:
        with template.open("r", encoding="utf-8") as fin:
            for line in fin:
                if "%%VERSION%%" in line:
                    spec.write(line.replace("%%VERSION%%", version))
                elif "%%DOWNLOAD_GROUPS%%" in line:
                    spec.write(download_groups(crates, repos))
                elif "%%CR_SITES%%" in line:
                    spec.write(cr_sites(crates, repos))
                elif "%%CR_DISTFILES%%" in line:
                    spec.write(cr_distfiles(crates, repos))
                elif "%%DF_INDEX%%" in line:
                    spec.write(df_index(crates, repos))
                else:
                    spec.write(line)


def main():
    """
    Script entry point
    """
    (folder, version, lockfile) = check_arguments()
    if folder is None:
        return 1
    (crates, repos) = read_lockfile(lockfile)
    create_extra_config_toml(folder, repos)
    generate_spec_sheet(crates, repos, folder, version)


if __name__ == "__main__":
    sys.exit(main())
