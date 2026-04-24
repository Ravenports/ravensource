#!/raven/bin/python3
"""
This script generates the primary, dev, man, docs, and examples manifests
lists for the erlang port using the <profile>/manifests/erlang___std.txt file that
is generated after an erlang build.

It also generates special.mk with all the version definitions that the makefile
needs.  To run this script, ravenadm has be installed and erlang must have built
to the point it failed the plist checks.
"""

import subprocess
import pathlib
import re
import os
import sys
doc_varname_map = {
    "erts": "ERTS_DOC_VSN",
}

TYPE_DEV = "dev"
TYPE_DOC = "doc"
TYPE_EXA = "exa"
TYPE_MAN = "man"
TYPE_PRI = "pri"
TYPE_NUL = "bitbucket"
RE_DOC = re.compile(r"^(lib/erlang(?:/lib)?)/([a-zA-Z0-9_]+)-([\d.]+)/(doc/.*)")
RE_EXA = re.compile(r"^(lib/erlang(?:/lib)?)/([a-zA-Z0-9_]+)-([\d.]+)/((?:doc/)?examples/.*)")
RE_DEV = re.compile(r"^(lib/erlang(?:/lib)?)/([a-zA-Z0-9_]+)-([\d.]+)/(include/.*)")
RE_PRI = re.compile(r"^(lib/erlang(?:/lib)?)/([a-zA-Z0-9_]+)-([\d.]+)/(.*)")
RE_REL = re.compile(r"^(lib/erlang/releases)/(\d+)/(.*)")

varname_map = {
    "erts": "ERTS_VSN",
    "asn1": "ASN1_VSN",
    "common_test": "COMMTEST_VSN",
    "compiler": "COMPILER_VSN",
    "crypto": "CRYPTO_VSN",
    "debugger": "DEBUGGER_VSN",
    "dialyzer": "DIALYZER_VSN",
    "diameter": "DIAMETER_VSN",
    "edoc": "EDOC_VSN",
    "eldap": "ELDAP_VSN",
    "erl_interface": "ERLINT_VSN",
    "et": "ET_VSN",
    "eunit": "EUNIT_VSN",
    "ftp": "FTP_VSN",
    "inets": "INETS_VSN",
    "kernel": "KERNEL_VSN",
    "megaco": "MEGACO_VSN",
    "mnesia": "MNESIA_VSN",
    "observer": "OBSERVER_VSN",
    "os_mon": "OSMON_VSN",
    "parsetools": "PARTOOLS_VSN",
    "public_key": "PUBKEY_VSN",
    "reltool": "RELTOOL_VSN",
    "runtime_tools": "RT_TOOLS_VSN",
    "sasl": "SASL_VSN",
    "snmp": "SNMP_VSN",
    "ssh": "SSH_VSN",
    "ssl": "SSL_VSN",
    "stdlib": "STDLIB_VSN",
    "syntax_tools": "SYNTAX_VSN",
    "tftp": "TFTP_VSN",
    "tools": "TOOLS_VSN",
    "wx": "WX_VSN",
    "xmerl": "XMERL_VSN",
}

varname_doc_map = {
    "erts": "ERTS_DOC_VSN",
    "asn1": "ASN1_DOC_VSN",
    "common_test": "COMMTEST_DOC_VSN",
    "compiler": "COMPILER_DOC_VSN",
    "crypto": "CRYPTO_DOC_VSN",
    "debugger": "DEBUGGER_DOC_VSN",
    "dialyzer": "DIALYZER_DOC_VSN",
    "diameter": "DIAMETER_DOC_VSN",
    "edoc": "EDOC_DOC_VSN",
    "eldap": "ELDAP_DOC_VSN",
    "erl_interface": "ERLINT_DOC_VSN",
    "et": "ET_DOC_VSN",
    "eunit": "EUNIT_DOC_VSN",
    "ftp": "FTP_DOC_VSN",
    "inets": "INETS_DOC_VSN",
    "kernel": "KERNEL_DOC_VSN",
    "megaco": "MEGACO_DOC_VSN",
    "mnesia": "MNESIA_DOC_VSN",
    "observer": "OBSERVER_DOC_VSN",
    "os_mon": "OSMON_DOC_VSN",
    "parsetools": "PARTOOLS_DOC_VSN",
    "public_key": "PUBKEY_DOC_VSN",
    "reltool": "RELTOOL_DOC_VSN",
    "runtime_tools": "RT_TOOLS_DOC_VSN",
    "sasl": "SASL_DOC_VSN",
    "snmp": "SNMP_DOC_VSN",
    "ssh": "SSH_DOC_VSN",
    "ssl": "SSL_DOC_VSN",
    "stdlib": "STDLIB_DOC_VSN",
    "syntax_tools": "SYNTAX_DOC_VSN",
    "tftp": "TFTP_DOC_VSN",
    "tools": "TOOLS_DOC_VSN",
    "wx": "WX_DOC_VSN",
    "xmerl": "XMERL_DOC_VSN",
}



def path_to_manifest():
    """
    Uses ravenadm to locate the complate file list
    """
    bin_path = "/raven/bin/ravenadm"
    manifest_path = "/manifests/erlang___std.txt"

    if not os.path.exists(bin_path):
        return None

    try:
        result = subprocess.run(
            [bin_path, "dev", "info", "G"],
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            check=True
        )
        
        return result.stdout.strip() + manifest_path

    except (subprocess.CalledProcessError, OSError):
        return None


def path_to_erlang():
    # Get the file's path, find its parent directory, 
    # join the relative segments, and resolve to remove ".."
    return str(pathlib.Path(__file__).parent.joinpath("../../bucket_A3/erlang").resolve())


def doc_name(name):
    """
    Returns doc varname mapping.
    If mapping is undefined, return "TBD"
    """
    if name in varname_doc_map:
        return varname_doc_map[name]
    return "TBD"


def reg_name(name):
    """
    Returns varname mapping.
    If mapping is undefined, return "TBD"
    """
    if name in varname_map:
        return varname_map[name]
    return "TBD"


def classify(line):
    """
    Returns a tuple of (file type, variable, value, newline)
    if line == newline, then variable and value are both None
    """
    varname = None
    value = None
    newline = line
    ftype = TYPE_PRI
    looking = True
    if line.startswith("lib/erlang/doc/") or line.startswith("share/doc/erlang/"):
        ftype = TYPE_DOC
        looking = False
    if looking:
        if line.startswith("lib/erlang/man/"):
            ftype = TYPE_MAN
            looking = False
    if looking:
        if (line.startswith("lib/erlang/usr/include/") or
           line.startswith("lib/erlang/usr/lib/lib")
        ):
            ftype = TYPE_DEV
            looking = False
    if looking:
        if line.startswith("etc/rc.d/"):
            ftype = TYPE_NUL
            looking = False
    if looking:
        m = RE_EXA.match(line)
        if m:
            varname = doc_name(m.group(2))
            value = m.group(3)
            newline = m.group(1) + "/" + m.group(2) + "-%%" + varname + "%%/" + m.group(4)
            ftype = TYPE_EXA
            looking = False
    if looking:
        m = RE_DOC.match(line)
        if m:
            varname = doc_name(m.group(2))
            value = m.group(3)
            newline = m.group(1) + "/" + m.group(2) + "-%%" + varname + "%%/" + m.group(4)
            ftype = TYPE_DOC
            looking = False
    if looking:
        m = RE_DEV.match(line)
        if m:
            varname = reg_name(m.group(2))
            value = m.group(3)
            newline = m.group(1) + "/" + m.group(2) + "-%%" + varname + "%%/" + m.group(4)
            ftype = TYPE_DEV
            looking = False
    if looking:
        m = RE_PRI.match(line)
        if m:
            varname = reg_name(m.group(2))
            value = m.group(3)
            newline = m.group(1) + "/" + m.group(2) + "-%%" + varname + "%%/" + m.group(4)
            ftype = TYPE_PRI
            looking = False
    if looking:
        m = RE_REL.match(line)
        if m:
            newline = m.group(1) + "/%%RELEASE%%/" + m.group(3)
            ftype = TYPE_PRI
            looking = False

    return (ftype, varname, value, newline)


def main():
    """
    Script entry point
    """
    special = {}
    full_manifest = path_to_manifest()
    erlang_port = path_to_erlang()
    if not full_manifest:
        print("Failed to get path to full manifest.  Is ravenadm installed?")
        return 1
    if not os.path.exists(full_manifest):
        print("Manifest does not exist.  Build erlang first")
        print("Location: " + full_manifest)
        return 1

    fdev = open(erlang_port + "/manifests/plist.dev", "w")
    fman = open(erlang_port + "/manifests/plist.man", "w")
    fdoc = open(erlang_port + "/manifests/plist.docs", "w")
    fpri = open(erlang_port + "/manifests/plist.primary", "w")
    fexa = open(erlang_port + "/manifests/plist.examples", "w")

    fpri.write("%%ONLY-SUNOS%%lib/erlang/lib/os_mon-%%OSMON_VSN%%/priv/bin/ferrule\n")
    fpri.write("%%ONLY-SUNOS%%lib/erlang/lib/os_mon-%%OSMON_VSN%%/priv/bin/mod_syslog\n")
    fpri.write("%%ONLY-SUNOS%%lib/erlang/lib/os_mon-%%OSMON_VSN%%/src/ferrule.c\n")
    fpri.write("%%ONLY-SUNOS%%lib/erlang/lib/os_mon-%%OSMON_VSN%%/src/mod_syslog.c\n")

    with open(full_manifest, "r") as fin:
        for line in fin:
            (ftype, variable, value, newline) = classify(line.strip())
            if ftype == TYPE_DEV:
                fdev.write(newline + "\n")
            elif ftype == TYPE_MAN:
                fman.write(newline + "\n")
            elif ftype == TYPE_DOC:
                fdoc.write(newline + "\n")
            elif ftype == TYPE_PRI:
                fpri.write(newline + "\n")
            elif ftype == TYPE_EXA:
                fexa.write(newline + "\n")
            if variable:
                special[variable] = value

    fexa.close()
    fpri.close()
    fdoc.close()
    fman.close()
    fdev.close()

    with open(erlang_port + "/files/special.mk", "w") as fspc:
        for varname in sorted(special.keys()):
            fspc.write(f"{varname + '=':<24} {special[varname]}\n")


if __name__ == "__main__":
    sys.exit(main())
