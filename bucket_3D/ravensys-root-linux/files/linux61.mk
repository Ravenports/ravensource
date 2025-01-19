# For Linux

Libexec_Linux=		# empty

Bin_Linux=\
	/bin/hostname \
	/bin/pax \
	/bin/dash \
	/bin/sh \
	# rest comes form coreutils

Usr_Bin_Linux=\
	/usr/bin/iconv
	# all the rest come from coreutils except two
	# /bin/which and /usr/bin/ldd are scripts, special handling

Usr_Sbin_Linux=		# end
static_lib_Linux=	# Linux doesn't use /usr/lib but a sudirectory, needs special list
dynamic_lib_Linux=	# Linux doesn't use /usr/lib, needs special list
headers_Linux_dirs=	# Not used
headers_Linux=		# Not used
pcfiles_Linux=\
	libudev.pc \
	libacl.pc \
	libattr.pc \
	libcap.pc \
	libcrypt.pc \
	libnsl.pc \
	libtirpc.pc \
	libxcrypt.pc \
	libnl-genl-3.0.pc \
	libnl-3.0.pc \
	libpsx.pc \
	libsystemd.pc \
	nss.pc \
	# end

platform-skeleton: common-skeleton
	@echo "============================================"
	@echo "===  Create extra directories for Linux  ==="
	@echo "============================================"
	${MKDIR} \
		${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu \
		${DESTDIR}${BASE}/usr/lib/pkgconfig \
		# end

install-platform: install-common
	@echo "================================="
	@echo "===  Linux file installation  ==="
	@echo "================================="

	# first remove created include skeleton
	rm -rf ${DESTDIR}${BASE}/usr/include

	cp ${CPA} ../linux/lib ${DESTDIR}${BASE}/
	cp ${CPA} ../linux/lib64 ${DESTDIR}${BASE}/
	cp ${CPA} ../linux/usr/lib/* ${DESTDIR}${BASE}/usr/lib/
	cp ${CPA} ../linux/usr/include ${DESTDIR}${BASE}/usr/
	cp ${CPA} ../linux/usr/share/i18n ${DESTDIR}${BASE}/usr/share/
	cp ${CPA} ../linux/usr/share/locale ${DESTDIR}${BASE}/usr/share/

	# bring in ldconfig at a new location
	cp ${CPA} ../linux/sbin/ldconfig ${DESTDIR}${BASE}/usr/bin/

	# remove original pc files
	rm -rf ${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu/pkgconfig

	# symlink libgcc_s.so.1 which lpthread needs in a specific location
	ln -s /raven/toolchain/${GCCX}/lib64/libgcc_s.so.1 ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/libgcc_s.so.1

	# From linux-only shadow package (same as passwd_4.13+dfsg1-1+b1_amd64.deb)
.  for sbinitem in useradd usermod groupadd
	cp ${CPA} ${LOCALBASE}/sbin/${sbinitem} ${DESTDIR}${BASE}/usr/bin/
.  endfor
	# ldd and which are scripts, can't be stripped
	${BSD_INSTALL_SCRIPT} ../linux/usr/bin/ldd ${DESTDIR}${BASE}/usr/bin/
	${BSD_INSTALL_SCRIPT} ../linux/usr/bin/which.gnu ${DESTDIR}${BASE}/usr/bin/which
	# from bash package
	cp ${CPA} ${LOCALBASE}/bin/bash ${DESTDIR}${BASE}/bin/

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

	rmdir ${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu/krb5/plugins/libkrb5

	# former "post-install" target
	${BSD_INSTALL_DATA} /port/files/linux-group \
		${DESTDIR}${BASE}/usr/share/group
	${BSD_INSTALL_DATA} /port/files/linux-passwd \
		${DESTDIR}${BASE}/usr/share/passwd

	# ld search path support
	echo "# Multiarch support for Ravenports" > ${DESTDIR}${BASE}/usr/share/x86_64-linux-gnu.conf
	echo "/lib/x86_64-linux-gnu" >> ${DESTDIR}${BASE}/usr/share/x86_64-linux-gnu.conf
	echo "/usr/lib/x86_64-linux-gnu" >> ${DESTDIR}${BASE}/usr/share/x86_64-linux-gnu.conf
	echo "include /etc/ld.so.conf.d/*.conf" > ${DESTDIR}${BASE}/usr/share/ld.so.conf
	cp ${CPA} ../ravensys-root-linux_47/ld.so.cache \
		${DESTDIR}${BASE}/usr/share/

	# pre-generated locale definitions
	cp ${CPA} ../ravensys-root-linux_48/locale-archive \
		${DESTDIR}${BASE}/usr/lib/locale/
