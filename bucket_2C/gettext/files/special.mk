# On linux, libintl is part of glibc so libintl.so doesn't get installed
.if ${OPSYS} == Linux
EXTERNAL="@comment "
.else
EXTERNAL=""
.endif
