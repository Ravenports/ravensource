#!/bin/sh

maintainer=marino
repo=/home/marino/github/Ravenports
myid=$(id -un)
today=$(date "+%d %h %Y %H:%M")
message="Ravenports generated: ${today}"

if [ "${myid}" != "root" ]; then
   echo "Only root is allowed to regenerate ports (which requires using root-only ravenadm)"
   exit 1
fi

RPATH=$(realpath $0)
SCRIPTSDIR=$(dirname ${RPATH})
RAVENSRC=$(dirname ${SCRIPTSDIR})
HEXRANGE="0 1 2 3 4 5 6 7 8 9 A B C D E F"

for D1 in ${HEXRANGE}; do
  for D0 in ${HEXRANGE}; do
    BK=${RAVENSRC}/bucket_${D1}${D0}
    if [ -d ${BK} ]; then
      queue=$(find ${BK} -depth -maxdepth 1 -mindepth 1 -type d)
      for port in ${queue}; do
         /raven/bin/ravenadm dev buildsheet ${port} save
      done
    fi
  done
done

/raven/bin/ravenadm dev generate-index

chown -R ${maintainer} ${repo}

if [ $# -lt 1 -o "${1}" != "confirm" ]; then
   echo "add 'confirm' argument to regenerate (again) but with a commit this time"
   exit 0;
fi

(cd ${repo} && git add * && git commit -m "${message}")
