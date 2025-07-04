# For SunOS (OmniOS)

Libexec_SunOS=\
	# end

Bin_SunOS=\
	# end

Usr_Bin_SunOS=\
	# end

Usr_Sbin_SunOS=\
	# end

static_lib_SunOS=\
	# end

dynamic_lib_SunOS=\
	# end

headers_SunOS_dirs=\
	# end

headers_SunOS=\
	# end

pcfiles_SunOS=\
	# end

platform-skeleton: common-skeleton
	# end

install-platform: install-common
	@echo "================================="
	@echo "===  SunOS file installation  ==="
	@echo "================================="

	# from bash package
	cp ${CPA} ${LOCALBASE}/bin/bash ${DESTDIR}${BASE}/bin/

	# hardlink bash as sh
	ln ${DESTDIR}${BASE}/bin/bash ${DESTDIR}${BASE}/bin/sh

	# install coreutils (/bin)
.  for item in [ date echo expr kill link ln ls mkdir mv pwd \
	realpath rm rmdir sleep test unlink
	cp ${CPA} ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/bin/${item}
.  endfor

	# install coreutils (/usr/bin)
.  for item in basename chgrp chown comm cut dirname env false head id \
	join mkfifo mktemp printenv printf readlink tail tee touch \
	tee tr true tsort uniq whoami \
	stat
	cp ${CPA} ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/usr/bin/${item}
.  endfor

	# install user and guest files
	cp /port/files/passwd.initial ${DESTDIR}${BASE}/usr/share/passwd
	cp /port/files/group.initial ${DESTDIR}${BASE}/usr/share/group

	# install libgcc_s for sysroot programs that need it
	cp ${LOCALBASE}/toolchain/ravensys-gcc/lib/amd64/libgcc_s.so.1 \
		${DESTDIR}${BASE}/usr/lib/amd64/libgcc_s.so.1
