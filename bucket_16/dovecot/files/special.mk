.if "${OPSYS}" == "FreeBSD"
. if "${MAJOR}" == "15"
PLIST_SUB+=	FREEBSD15=
. else
PLIST_SUB+= 	FREEBSD15="@comment "
. endif
.endif
