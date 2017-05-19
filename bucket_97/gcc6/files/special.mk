.if "${OPSYS}" == "Linux"	# only x86_64 supported right now
ASLIB=		lib64
.else
ASLIB=		lib
.endif
