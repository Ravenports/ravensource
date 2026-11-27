#!/bin/sh
#
# Before running this script, update freebsd ports (/usr/ports) and
# regenerate index with "ravenadm dev generate-index" command.  Before
# that, regenerate conspiracy directory if necessary.  This provides
# the latest data for the script to function properly.
#
# The purpose of the script is to show which Ravenports are behind
# their FreeBSD Ports Collection counterparts.  It only applies to
# non-generated ports that have counterparts at FreeBSD.
#

CONSPIR=$(/raven/bin/ravenadm dev info D)
tmpfile=/tmp/fpc.list
deviants=/tmp/deviant.list
ports=/usr/ports

rm -f ${deviants}
PROG='{if ($3 != "N/A" && $3 != "generated") print}'
awk "${PROG}" ${CONSPIR}/Mk/Misc/fpc_equivalents > ${tmpfile}

export IGNORE_OSMAJOR=yes

known_mismatch()
{
   RESULT=0
   case "$1" in
      libedit) ;;		# DF: 20260512-3.1, FPC: 3.1-20260512
      apr1) ;;		        # DF: 1.7.6, FPC: 1.7.6.1.6.6
      libzen) ;;		# DF: 0.4.41, FPC: 0.4.41.26.10
      ImageMagic) ;;		# DF: 7.1.2-36, FPC: 7.1.2.36
      libcdio-paranoia) ;;	# DF: 10.2_2.0.2, FPC 10.2+2.0.2
      re2) ;;			# DF: 2025-11-05, FPC 20251105
      aspell-pl) ;;		# DF 6.0_20261101.0, FPC 6.0.20061121.0
      openjade) ;;		# DF 1.3.3p1 (DEV), FPC 1.3.2
      gsfonts) ;;		# DF 8.11pre44, FPC 8.11
      fonts-anonymous-pro) ;;	# DF 1_003, FPC 1.002
      xclip) ;;			# DF 0.13, FPC 0.13.99
      clisp) ;;			# DF 2.49, FPC 2.49.95+20241228
      musepack) ;;		# DF r475, FPC 2011.08.10
      mg) ;;			# DF 20260719, FPC 20261020 (different source)
      libisofs) ;;		# DF 1.5.8.pl02, FPC 1.5.8.02
      vde) ;;			# DF 2.3.3, FPC 2.3.3.86
      vde2) ;;			# DF 2.3.3, FPC 2.3.3.86
      dhcp) ;;			# DF 4.4.3.P1, FPC 4.4.3P1
      libsearpc) ;;		# DF 3.3.0, FPC 3.3.20260612
      libsndfile) ;;		# DF 1.2.2, FPC 1.2.2.20251216
      cd-discid) ;;		# DF 1.4, FPC 1.4.14
      usbids) ;;		# DF 2026.06.26, FPC 20260626
      lensfun) ;;		# DF 0.3.4, FPC 0.3.95
      freealut) ;;		# DF 1.1.0, FPC 1.1.0.20240801
      l-smash) ;;		# DF 2.18.0, FPC 2.18.0.10
      xorg-luit) ;;		# DF 2.0.20260907, FPC 20240102
      id3lib) ;;		# DF 3.8.3, FPC 3.8.3.20240114
      yasm) ;;			# DF 1.3.0, FPC 1.3.0.109
      docopt-cpp) ;;		# DF 0.6.3, FPC 0.6.3.5
      bash) ;;			# DF 5.3.p20, FPC 5.3.20
      *) RESULT=1
   esac
   return ${RESULT}
}

while read ravenport version fpc_port; do
  if [ -f ${ports}/${fpc_port}/Makefile ]; then
    portv=$(make -C ${ports}/${fpc_port} -V PORTVERSION)
    result=$(pkg version -t "${version}" "${portv}")
    if [ $? -ne 0 ]; then
       echo "failed to query ${fpc_port}"
    fi
    if [ "${result}" = "<" ]; then
       if known_mismatch "$ravenport"; then
         printf '%-40s version=%s freebsd=%s\n' "$ravenport" "$version" "$portv" >> ${deviants}
       else
         printf '%-40s version=%s freebsd=%s\n' "$ravenport" "$version" "$portv"
       fi
    fi
  else
       printf '%-40s ## DOES NOT EXIST ##' "$ravenport"
  fi
done < ${tmpfile}

echo ""
echo "==========================="
echo "= KNOWN SCHEMA MISMATCHES ="
echo "==========================="
cat ${deviants}

rm -f ${tmpfile} ${deviants}
