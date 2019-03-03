#!/bin/sh

maintainer=marino
location=$(/raven/bin/ravenadm dev info D)
MISC=${location}/Mk/Misc
infofile=${MISC}/latest_release.txt
myid=$(id -un)

if [ "${myid}" != "${maintainer}" ]; then
   echo "Only ${maintainer} is allowed to tag new releases"
   exit 1
fi

lasthash=$(cd ${location} && git rev-list --tags --max-count=1)
lasttag=$(cd ${location} && git describe --tags ${lasthash})
lastdate=${lasttag%.[123456789]}
today=$(date "+%Y%m%d")

if [ "${today}" = "${lastdate}" ]; then
daily=$(make TAG=${lasttag} -V "TAG:E")
newtag=${lastdate}.$((${daily} + 1))
else
newtag=${today}.1
fi

if [ $# -lt 1 -o "${1}" != "confirm" ]; then
   echo "The tag '${newtag}' would be created"
   exit 0;
fi

echo "${newtag}" > ${infofile}
(cd ${location} && git add ${MISC})
(cd ${location} && git commit -m "Create Ravenports release ${newtag}" ${MISC})
(cd ${location} && git tag -a ${newtag} -m "Ravenports release ${newtag}")
