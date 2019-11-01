#!/bin/sh

maintainer=marino
repo=/usr/raven #/home/marino/github/Ravenports
myid=$(id -un)

if [ "${myid}" != "root" ]; then
   echo "Only root is allowed to regenerate ports (which requires using root-only ravenadm)"
   exit 1
fi

DPATH=$(dirname $0)
SCRIPTSDIR=$(cd ${DPATH} && pwd -P)
RAVENSRC=$(dirname ${SCRIPTSDIR})
HEXRANGE="0 1 2 3 4 5 6 7 8 9 A B C D E F"

for D1 in ${HEXRANGE}; do
  for D0 in ${HEXRANGE}; do
    BK=${RAVENSRC}/bucket_${D1}${D0}
    if [ -d ${BK} ]; then
      queue=$(find ${BK} -depth -maxdepth 1 -mindepth 1 -type d)
      for port in ${queue}; do
         echo "=============  ${port}"
         /raven/bin/ravenadm dev sort ${port}
      done
    fi
  done
done
