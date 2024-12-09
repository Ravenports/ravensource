#!/bin/sh
# This script generates the metafile used to bootstrap a Ravenports
# system on a new machine.
# shellcheck_disable=SC3043,SC3013

REPODIR="/build4/marino-huge/repository"
PROGRAM="/home/marino/repo_cron/meta.awk2"
METADATA="${REPODIR}/inventory.txt"
TMPFILE="/tmp/inventory.tmp"

repack_ravensw() {
  local opsys_abi="$1"
  local ravensw_file="$2"
  mkdir -p "/tmp/${opsys_abi}"
  # unpack ravensw package in tmp temporary directory
  (cd "/tmp/${opsys_abi}" && tar -xf "${ravensw_file}" 2>/dev/null)
  # gzip the binary
  (cd "/tmp/${opsys_abi}/raven/sbin" && gzip -7 --keep ravensw)
  # relocate gzipped file
  mv "/tmp/${opsys_abi}/raven/sbin/ravensw.gz" "${REPODIR}/${opsys_abi}/Latest/"
  # Update modification time to match tzst file
  touch -r "${ravensw_file}" "${REPODIR}/${opsys_abi}/Latest/ravensw.gz"
  # delete temporary directory
  rm -rf "/tmp/${opsys_abi}"
}


repack_rvn() {
  local opsys_abi="$1"
  local rvn_primary="$2"
  local rtmp="/tmp/${opsys_abi}"
  mkdir -p "$rtmp"
  # unpack rvn package in tmp temporary directory
  /raven/bin/xrvn -x "$rvn_primary" -o "$rtmp" 2>/dev/null
  rm "${rtmp}/raven/sbin/signserver.py"
  # gzip the binary
  (cd "${rtmp}/raven/sbin" && gzip -7 --keep rvn)
  # relocate gzipped file
  mv "${rtmp}/raven/sbin/rvn.gz" "${REPODIR}/${opsys_abi}/"
  # Update modification time to match rvn file
  touch -r "${rvn_primary}" "${REPODIR}/${opsys_abi}/rvn.gz"
  # delete temporary directory
  rm -rf "$rtmp"
}


repack_needed() {
  # We need to replace ravensw.gz under the following conditions:
  # 1.  $REPODIR/Latest/ravensw.gz does not exists
  # 2.  $REPODIR/Latest/ravensw.gz has different mtime than $ravensw_file
  local opsys_abi="$1"
  local ravensw_file="$2"
  local rgz="${REPODIR}/${opsys_abi}/Latest/ravensw.gz"
  local t1
  local t2


  if [ ! -f "$rgz" ]; then
     echo "yes"
     return
  fi
  t1=$(stat -f %m "$rgz")
  t2=$(stat -f %m "$ravensw_file")
  if [ $t1 -ne $t2 ]; then
     echo "yes"
     return
  fi
  echo "no"
}


rvn_repack_needed() {
  # We need to replace rvn.gz under the following conditions:
  # 1.  $REPODIR/rvn.gz does not exists
  # 2.  $REPODIR/rvn.gz has different mtime than $rvn_primary
  local opsys_abi="$1"
  local rvn_primary="$2"
  local rgz="${REPODIR}/${opsys_abi}/rvn.gz"
  local t1
  local t2

  if [ ! -f "$rgz" ]; then
     echo "yes"
     return
  fi
  t1=$(stat -f %m "$rgz")
  t2=$(stat -f %m "$rvn_primary")
  if [ $t1 -ne $t2 ]; then
     echo "yes"
     return
  fi
  echo "no"
}


rm -f "$TMPFILE"
(cd "$REPODIR" && find -s * -type d -depth 0 -name "*:*" | sort -f) |\
while read -r ABI
do
  if [ -d "${REPODIR}/${ABI}/files" ]; then
    rvn=$(find "${REPODIR}/${ABI}/files" -type f -name "rvn[~-]primary[~-]s*d[~-]*")
    if [ -n "$rvn" ]; then
       base_rvn=$(basename "$rvn")
       echo "${ABI} ${base_rvn}" >> "$TMPFILE"
       do_repack=$(rvn_repack_needed "$ABI" "$rvn")
       if [ "$do_repack" = "yes" ]; then
          repack_rvn "$ABI" "$rvn"
       fi
    else
       echo "${ABI} rvn-not-found" >> "$TMPFILE"
    fi
  elif [ -d "${REPODIR}/${ABI}/All" ]; then
    ravensw=$(find "${REPODIR}/${ABI}/All" -type f -name "ravensw-single*")
    if [ -n "$ravensw" ]; then
       base_rav=$(basename "$ravensw")
       echo "${ABI} ${base_rav}" >> "$TMPFILE"
       do_repack=$(repack_needed "$ABI" "$ravensw")
       if [ "$do_repack" = "yes" ]; then
          repack_ravensw "$ABI" "$ravensw"
       fi
    else
       echo "${ABI} ravensw-not-found" >> "$TMPFILE"
    fi
  fi
done

/usr/bin/awk -f "$PROGRAM" "$TMPFILE" > "$METADATA"
rm -f "$TMPFILE" 
