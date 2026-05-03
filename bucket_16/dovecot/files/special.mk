HIBERNATE=

.if "${OPSYS}" == "FreeBSD"
. if "${MAJOR}" == "15"
PLIST_SUB+=	FREEBSD15=
HIBERNATE=	\#
. else
PLIST_SUB+= 	FREEBSD15="@comment "
. endif
.elif "${OPSYS}" == "Linux"
HIBERNATE=	\#
.endif
