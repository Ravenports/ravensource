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
	# link bash as sh
	ln -s bash ${DESTDIR}${BASE}/bin/sh 

	# install coreutils (/bin)
.  for item in [ chmod cp date echo expr kill link ln ls mkdir mv pwd \
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
