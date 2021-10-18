# For MacOS (Untested)

headers_Darwin_dirs=	# end
headers_Darwin=			# end
pcfiles_Darwin=			# end

position-macos:
	${MKDIR} ${DESTDIR}/${BASE}
	mv ../${OPSYS:tl}/* ${DESTDIR}${BASE}/

common-skeleton: position-macos

platform-skeleton: common-skeleton
	@echo "========================================="
	@echo "===  No extra directories for Darwin  ==="
	@echo "========================================="


install-platform: install-common
	@echo "=================================="
	@echo "===  Darwin file installation  ==="
	@echo "=================================="
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

	# remove ELF tool on Mach system
	rm ${DESTDIR}${BASE}/usr/bin/objdump-sysroot


	# former "post-install" target
	chmod 600 ${DESTDIR}${BASE}/usr/share/master.passwd
	${DESTDIR}${BASE}/usr/sbin/pwd_mkdb -p -d ${DESTDIR}${BASE}/usr/share \
		${DESTDIR}${BASE}/usr/share/master.passwd
	# autogenerate System/Library part of manifest
	(cd ${STAGEDIR}${PREFIX} && \
		${FIND} share/raven/sysroot/Darwin/System \( -type f -or -type l \) | ${SORT} \
		>> ${WRKDIR}/.manifest.single.mktmp)
		
		