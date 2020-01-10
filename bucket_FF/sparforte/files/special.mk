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
