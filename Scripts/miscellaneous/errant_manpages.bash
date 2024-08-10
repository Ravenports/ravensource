#!/usr/local/bin/bash
#
# Lists ports that have man pages outside of the man subpackage.
# Ideality there should be none.

DPATH=$(dirname "$0")
RSDIR=$(cd "${DPATH}/../.." && pwd -P)

check_for_man() {
   local filename="$1"
   if grep -q "man/man[12345678]" "$filename"; then
      echo "$filename"
   fi
}

while read xf; do
  case $xf in
     */plist.man) ;;
     */plist.man.*) ;;
     *) check_for_man $xf ;;     
  esac
done < <(find $RSDIR -type f -name "plist.*" -print0 | xargs -0 ls -tr)
