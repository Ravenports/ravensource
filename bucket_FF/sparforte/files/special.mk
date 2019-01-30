.if ${SETMYSQL} == 1 || ${SETPGSQL} == 1
SFARG+=		-DAPQ=true
SETAPQ=		1
.else
SFARG+=		-DAPQ=false
SETAPG=		0
.endif

BUILDDATE!=	date "+%y%m%d"
SFARG+=		-DREADLINE=true
SFARG+=		-DBDB=true
SFARG+=		-DconfigbuildDate=\"${BUILDDATE}\"
SFARG+=		-Dconfigreleased=true

# Currently Ada is only available for x86, so we can assume the following
SF_ARCH=		${ARCH_STANDARD:S/x86_64/athlon64/}
SF_CPU_FLAG=		-march

.if ${OPSYS} == FreeBSD || ${OPSYS} == DragonFly
SF_CFLAGSTYPE=		-DFREEBSD
OSBIND=			os_bindings/spar_freebsd
.else
SF_CFLAGSTYPE=		-DLINUX
OSBIND=			os_bindings/spar_linux
.endif

.if ${ARCH_STANDARD} == x86_64 || ${ARCH_STANDARD} == aarch64
CPU_SDL=		spar_os-sdl-64bit
.else
CPU_SDL=		spar_os-sdl-32bit
.endif
