#!/bin/sh
#
# Used by Uses/python.mk
# argument 1 is equivalent to ${STAGEDIR}
# argument 2 is equivalent to ${PREFIX}
# argument 3 is the python command

PCMD="${3}"
PENV="/usr/bin/env python"
SARG="s|^\#![[:space:]]*${PENV}\([[:space:]]\)|\#!${PCMD}\1|; s|^\#![[:space:]]*${PENV}\$|\#!${PCMD}|"

check_file() {
	f="$1"
	top_line=$(sed -n -e '1s/^#![[:space:]]*\([^[:space:]]*\)[[:space:]]*\([^[:space:]]*\).*/\1 \2/p;2q' "${f}")

	interp=${top_line% * bridge} # Note: % * removes everything after the last space
        interp=${top_line% *}

	case "${interp}" in
	/usr/bin/env)
		interparg=${top_line#* }
		case "${interparg}" in
		python)
			echo "==> Adjusting /usr/bin/env shebang: ${f}"
			sed -i'' -e "${SARG}" "${f}"
			;;
		esac
	esac
}

find "${1}${2}" -type f -perm /111 -name "*.py" 2>/dev/null | while read -r ff; do
    check_file "$ff"
done
