#!/bin/sh
#
# Generate Go crate-based port given a specification.template
#
# This script takes three arguments:
#  1) The port's namebase
#  2) The port's version
#  3) The directory that contains go.mod and go.sum 
#

GOPROG=/raven/bin/go

if [ $# -lt 3 ]; then
   echo "Usage: golang_port.sh <portname> <version> <directory to go.mod>"
   exit 1
fi

if [ ! -x "$GOPROG" ]; then
   echo "FATAL: go program $GOPROG is not installed or is not executable"
   exit 1
fi

DPATH=$(dirname "$0")
SCRIPTSDIR=$(cd "${DPATH}/.." && pwd -P)
RAVENSRC=$(dirname "${SCRIPTSDIR}")

NAMEBASE="$1"
VERSION="$2"
MOD_DIR="$3"
LOCATE=$(/raven/bin/ravenadm locate "$NAMEBASE")
FOLDER="${RAVENSRC}/bucket_${LOCATE#*bucket_}"
FILE_SPTEMP="${FOLDER}/specification.template"
TARGET="${FOLDER}/specification"
FILE_GO_MOD="${MOD_DIR}/go.mod"
FILE_GO_SUM="${MOD_DIR}/go.sum"
TEMP_GRAPH="/tmp/raven.graph"

if [ ! -f "$FILE_GO_MOD" ]; then
   echo "missing file: ${FILE_GO_MOD}"
   exit 1
fi

if [ ! -f "$FILE_GO_SUM" ]; then
   echo "missing file: ${FILE_GO_SUM}"
   exit 1
fi

if [ ! -f "$FILE_SPTEMP" ]; then
   echo "missing file: ${FILE_SPTEMP}"
   exit 1
fi

(cd "$MOD_DIR" && ${GOPROG} mod graph > "$TEMP_GRAPH")

# How to interpret graph
# Abridged example:
# github.com/git-lfs/git-lfs/v3 github.com/git-lfs/gitobj/v2@v2.1.1
# github.com/git-lfs/git-lfs/v3 github.com/git-lfs/go-netrc@v0.0.0-20210914205454-f0c862dd687a
# github.com/git-lfs/git-lfs/v3 golang.org/x/crypto@v0.0.0-20220411220226-7b82a4e95df4
# github.com/git-lfs/git-lfs/v3 gopkg.in/yaml.v3@v3.0.1
# golang.org/x/crypto@v0.0.0-20220411220226-7b82a4e95df4 golang.org/x/net@v0.0.0-20211112202133-69e39bad7dc2
# gopkg.in/yaml.v3@v3.0.1 gopkg.in/check.v1@v0.0.0-20161208181325-20d25e280405
#
# The first field is a requirement.
# The second field is requirement of the first requirement
# Split the second field with the "@" delimiter.
# The first component is in format of <host>/<org>/<project>/<vendor path>.  The latter is optional
# the second component is either a hash or a tag
# Example of a github tag:  "@v2.1.1"
# Example of a githb hash: "@v0.0.0-20210914205454-f0c862dd687a" (hash is "f0c862dd687a")
#    SITES: GITHUB/git-lfs:gitobj:v2.1.1
#    SITES: GITHUB/git-lfs:go-netrc:f0c862dd687a
# Mirror of golang.org/x/(net|crypto|mod|text|tools) at GITHUB/golang/
# Mirror of gopkg.in/yaml.v3 at GITHUB/go-yaml/yaml/releases/tag/v3.0.1
# Mirror of gopkg.in/check.v1 at GITHUB/go-check/check/tree/v1

sed -e "s|%%VERSION%%|${VERSION}|" "${FILE_SPTEMP}" > /tmp/spec.1

awk -vnamebase="$NAMEBASE" -f "${SCRIPTSDIR}/assembler/_golang.awk" "$TEMP_GRAPH" /tmp/spec.1 > "$TARGET"
echo "file written: ${TARGET}"

rm -f /tmp/spec.1
rm -f "$TEMP_GRAPH"
