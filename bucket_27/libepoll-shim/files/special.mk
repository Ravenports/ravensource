.if "${OPSYS}" == "FreeBSD"
. if "${MAJOR}" == "13"
PLIST_SUB+= R13=""
. else
PLIST_SUB+= R13="@comment "
. endif
.endif
