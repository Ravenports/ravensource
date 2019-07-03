#!/bin/sh
#
# This script downloads the latest module list and filters out the 200,000
# line file to module level entries
#
# input  : http://www.cpan.org/modules/02packages.details.txt.gz
# output : /tmp/cpan-work/latest_candidates.txt
#

plain="02packages.details.txt"
archive="${plain}.gz"
archurl="http://www.cpan.org/modules/${archive}"
workdir="/tmp/cpan-work"
newfile="${workdir}/latest_candidates.txt"

rm -rf ${workdir}
mkdir -p ${workdir}
env SSL_NO_VERIFY_PEER=1 fetch ${archurl} -o ${workdir}

if [ $? -ne 0 ]; then
  echo "download failed"
  exit 1;
fi

gunzip ${workdir}/${archive}

PROG='{ \
  if (NR < 10) next; \
#  if (counter > 130) exit; \
  if ($2 == "undef") next; \
  if ($2 == "0") next; \
  if ($3 == lastone) next;\
  if ($1 == "Acme" || substr($1,1,6) == "Acme::" || substr ($1,1,6) == "ACME::") next; \
  verindex = index($3, "-" $2 "."); \
  if (verindex == 0) next; \
  stem = substr($3, 1, verindex); \
  if (stem == laststem) next; \
  print; \
  lastone = $3; \
  laststem = stem; \
  counter++; \
}'

awk "${PROG}" ${workdir}/${plain} > ${newfile}
