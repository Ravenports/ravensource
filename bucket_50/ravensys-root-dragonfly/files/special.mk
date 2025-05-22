# Override bmake settings (important for bootstraps and sysroot rebases)
OPSYS=				${SYSTEM:H:H:H:H:H}
ARCH=				${SYSTEM:H:H:H:H:T}
ARCH_STANDARD=			${SYSTEM:H:H:H:T}
OSVERSION=			${SYSTEM:H:H:T}
OSREL=				${SYSTEM:H:T}
MAJOR=				${SYSTEM:T}

SYSPATH=			share${RAVENBASE}/sysroot/${OPSYS}
RSYS=				${PREFIX}/${SYSPATH}
FOS=				${WRKDIR}/${OPSYS:tl}
