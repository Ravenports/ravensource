# On linux, libintl is part of glibc so libintl.so doesn't get installed
.if ${OPSYS} == Linux || ${OPSYS} == SunOS
EXTERNAL="@comment "
.else
EXTERNAL=""
_USES_build+= 555:assemble_pic
_USES_stage+= 555:install_pic
.endif

assemble_pic:
	(cd ${WRKSRC}/gettext-runtime/intl/.libs &&\
	 ${AR} -cq libintl_pic.a *.o &&\
	 ranlib libintl_pic.a)

install_pic:
	${INSTALL_DATA} ${WRKSRC}/gettext-runtime/intl/.libs/libintl_pic.a \
		${STAGEDIR}${PREFIX}/lib/
