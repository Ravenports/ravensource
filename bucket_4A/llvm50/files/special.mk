# for some reason linux freezes when linking two clang programs
# at the same time

.if ${OPSYS} == Linux
SINGLE_JOB=	yes
.endif