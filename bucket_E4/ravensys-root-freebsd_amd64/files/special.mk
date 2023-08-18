# Override bmake settings (important for bootstraps and sysroot rebases)
OPSYS=				${SYSTEM:H:H:H:H:H}
ARCH=				${SYSTEM:H:H:H:H:T}
ARCH_STANDARD=			${SYSTEM:H:H:H:T}
OSVERSION=			${SYSTEM:H:H:T}
OSREL=				${SYSTEM:H:T}
MAJOR=				${SYSTEM:T}

.if "${MAJOR}" == "13"
SYSPATH=			share${RAVENBASE}/sysroot/${OPSYS}
.else
SYSPATH=			share${RAVENBASE}/sysroot/${OPSYS}-${OSREL}
.endif
RSYS=				${PREFIX}/${SYSPATH}
FOS=				${WRKDIR}/${OPSYS:tl}
