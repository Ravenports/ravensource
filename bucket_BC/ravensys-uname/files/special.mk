# add ARCH_STANDARD conditions as multiple arches per OPSYS
# become supported

.if ${OPSYS:MFreeBSD}
SET_ARCH=	amd64
SET_PLATFORM=	amd64
.elif ${OPSYS:MDragonFly}
SET_ARCH=	x86_64
SET_PLATFORM=	x86_64
.elif ${OPSYS:MNetBSD}
SET_ARCH=	amd64
SET_PLATFORM=	amd64
.elif ${OPSYS:MOpenBSD}
SET_ARCH=	amd64
SET_PLATFORM=	amd64
.elif ${OPSYS:MDarwin}
SET_ARCH=	x86_64
SET_PLATFORM=	i386
.elif ${OPSYS:MSunOS}
SET_ARCH=	x86_64	#check
SET_PLATFORM=	x86_64
.elif ${OPSYS:MLinux}
SET_ARCH=	x86_64
SET_PLATFORM=	x86_64
.endif
