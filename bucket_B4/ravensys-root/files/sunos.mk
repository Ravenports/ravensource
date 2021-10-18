# For Solaris 10

headers_SunOS_dirs=		# end
headers_SunOS=			# end
pcfiles_SunOS=			# end

platform-skeleton: common-skeleton
	@echo "=========================================="
	@echo "===  No extra directories for Solaris  ==="
	@echo "=========================================="


install-platform: install-common
	@echo "==================================="
	@echo "===  Solaris file installation  ==="
	@echo "==================================="
	
	cp ${CPA} ../${OPSYS:tl}/* ${DESTDIR}${BASE}/
	# use BSD's which (from ravensys-utils)
	${BSD_INSTALL_PROGRAM} ${LOCALBASE}/bin/which ${DESTDIR}${BASE}/usr/bin/
	# /bin/sh is really /usr/xpg4/bin/sh, move it there
	# Move /usr/bin/bash (from distro) to /bin/bash
	# hardlink /bin/bash to /bin/sh
	${MKDIR} ${DESTDIR}${BASE}/usr/xpg4/bin
	mv ${DESTDIR}${BASE}/bin/sh ${DESTDIR}${BASE}/usr/xpg4/bin/
	mv ${DESTDIR}${BASE}/usr/bin/bash ${DESTDIR}${BASE}/bin/bash
	ln ${DESTDIR}${BASE}/bin/bash ${DESTDIR}${BASE}/bin/sh

	# use coreutils that FreeBSD and DragonFly passed on (/bin)
.  for item in [ chmod cp date echo expr kill link ln ls mkdir mv pwd \
	realpath rm rmdir sleep test unlink
	cp ${CPA} ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/bin/${item}
.  endfor
	# use coreutils that FreeBSD and DragonFly passed on (/usr/bin)
.  for item in basename chgrp chown comm cut dirname env false head id \
	join mkfifo mktemp printenv printf readlink tail tee touch \
	tee tr true tsort uniq whoami
	cp ${CPA} ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/usr/bin/${item}
.  endfor
.  for item in stat
	cp ${CPA} ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/usr/bin/${item}
.  endfor

	# Fix headers for C++
	(cd ${DESTDIR}${BASE}/usr/include && sed -i'' \
		-e 's|\(__cplusplus >= 199711L\)|(!defined __clang__ \&\& \1)|g' \
		ctype.h \
		errno.h \
		iso/ctype_iso.h \
		iso/locale_iso.h \
		iso/math_iso.h \
		iso/setjmp_iso.h \
		iso/signal_iso.h \
		iso/stdarg_iso.h \
		iso/stddef_iso.h \
		iso/stdio_iso.h \
		iso/stdlib_iso.h \
		iso/string_iso.h \
		iso/time_iso.h \
		iso/wchar_iso.h \
		iso/wctype_iso.h \
		limits.h \
		locale.h \
		math.h \
		memory.h \
		mon.h \
		setjmp.h \
		signal.h \
		stdarg.h \
		stddef.h \
		stdio.h \
		stdlib.h \
		string.h \
		time.h \
		wchar.h \
		wctype.h \
		sys/sunddi.h \
		sys/mdb_modapi.h \
		sys/systm.h \
		sys/systm.h \
		sys/time.h \
		sys/time_impl.h \
		sys/time_std_impl.h \
		sys/types.h \
		sys/un.h \
	)
