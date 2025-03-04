glib_MAN=	gtester.1 gtester-report.1 glib-gettextize.1
gio_MAN=	gdbus.1 gsettings.1 gio-querymodules.1 \
		glib-compile-schemas.1 gapplication.1 \
		glib-compile-resources.1 gresource.1 gdbus-codegen.1
gobject_MAN=	glib-genmarshal.1 glib-mkenums.1 gobject-query.1
pyscripts=	gio/tests/gengiotypefuncs.py \
		glib/update-gtranslit.py \


POST_PLIST_TARGET=	my-autolist

my-autolist:
	(cd ${STAGEDIR}${PREFIX} && \
	${FIND} share/glib-2.0/codegen share/glib-2.0/gdb share/gdb/auto-load \
	\( -type f -o -type l \) 2>/dev/null | ${SORT}) \
	>> ${WRKDIR}/.manifest.primary.mktmp
