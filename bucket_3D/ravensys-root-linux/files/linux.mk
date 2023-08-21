# For Linux

Libexec_Linux=		# empty

Bin_Linux=\
	/bin/hostname \
	/bin/pax \
	/bin/dash \
	/bin/sh \
	# rest comes form coreutils

Usr_Bin_Linux=		# all come from coreutils except two
	# /bin/which and /usr/bin/ldd are scripts, special handling

Usr_Sbin_Linux=		# end
static_lib_Linux=	# Linux doesn't use /usr/lib but a sudirectory, needs special list

Linux_static_libs=\
	libc.a \
	libc_nonshared.a \
	libm.a \
	libutil.a \
	libcrypt.a \
	libpthread.a \
	libpthread_nonshared.a \
	libdl.a \
	libnsl.a \
	librt.a \
	libresolv.a \
	libanl.a \
	libmvec.a \
	libmvec_nonshared.a \
	librpcsvc.a \
	libieee.a \
	Mcrt1.o \
	Scrt1.o \
	crt1.o \
	crti.o \
	crtn.o \
	gcrt1.o \
	# end

dynamic_lib_Linux=	# Linux doesn't use /usr/lib, needs special list

Linux_RTLD=\
	ld-2.23.so/ld-linux-x86-64.so.2

Linux_C_lib=\
	libc-2.23.so/libc.so.6

Linux_thread_lib=\
	libpthread-2.23.so/libpthread.so.0
	
# /lib/x86_64-linux-gnu => /lib64
# real file / soname (also symlink)
# use to create /usr/lib64/<lib>.so => /lib64/soname

Linux_shared_libs=\
	${Linux_C_lib} \
	${Linux_thread_lib} \
	libm-2.23.so/libm.so.6 \
	libutil-2.23.so/libutil.so.1 \
	libcrypt-2.23.so/libcrypt.so.1 \
	libdl-2.23.so/libdl.so.2 \
	libnsl-2.23.so/libnsl.so.1 \
	librt-2.23.so/librt.so.1 \
	libresolv-2.23.so/libresolv.so.2 \
	libanl-2.23.so/libanl.so.1 \
	libmvec-2.23.so/libmvec.so.1 \
	libnss_compat-2.23.so/libnss_compat.so.2 \
	libnss_dns-2.23.so/libnss_dns.so.2 \
	libnss_files-2.23.so/libnss_files.so.2 \
	libnss_hesiod-2.23.so/libnss_hesiod.so.2 \
	libnss_nis-2.23.so/libnss_nis.so.2 \
	libnss_nisplus-2.23.so/libnss_nisplus.so.2 \
	libudev.so.1.6.4/libudev.so.1 \
	# end

Linux_extra_libs1=\
	libattr.so.1.1.0/libattr.so.1 \
	libacl.so.1.1.0/libacl.so.1 \
	# end (/lib)

Linux_extra_libs2=\
	# libustr-1.0.so.1.0.4/libustr-1.0.so.1 \
	# end (/usr/lib)

Linux_single_libs1=\
	# end (/lib/TARGET)

Linux_single_libs2=\
	# libsemanage.so.1 \
	# end (/usr/lib/TARGET)

headers_Linux_dirs=\
	acl \
	arpa \
	attr \
	asm-generic \
	drm \
	linux \
	net \
	netash \
	netatalk \
	netax25 \
	neteconet \
	netinet \
	netipx \
	netiucv \
	netpacket \
	netrom \
	netrose \
	nfs \
	protocols \
	rpc \
	rpcsvc \
	sound \
	scsi \
	sys \
	x86_64-linux-gnu \
	#end


headers_Linux=\
	_G_config.h \
	aio.h \
	aliases.h \
	alloca.h \
	ar.h \
	argp.h \
	argz.h \
	assert.h \
	byteswap.h \
	complex.h \
	cpio.h \
	crypt.h \
	ctype.h \
	dirent.h \
	dlfcn.h \
	elf.h \
	endian.h \
	envz.h \
	err.h \
	errno.h \
	error.h \
	execinfo.h \
	fcntl.h \
	features.h \
	fenv.h \
	fmtmsg.h \
	fnmatch.h \
	fstab.h \
	fts.h \
	ftw.h \
	gconv.h \
	getopt.h \
	glob.h \
	gnu-versions.h \
	grp.h \
	gshadow.h \
	iconv.h \
	ifaddrs.h \
	inttypes.h \
	langinfo.h \
	lastlog.h \
	libgen.h \
	libintl.h \
	libio.h \
	libudev.h \
	limits.h \
	link.h \
	locale.h \
	malloc.h \
	math.h \
	mcheck.h \
	memory.h \
	mntent.h \
	monetary.h \
	mqueue.h \
	netdb.h \
	nl_types.h \
	nss.h \
	obstack.h \
	paths.h \
	poll.h \
	printf.h \
	pthread.h \
	pty.h \
	pwd.h \
	re_comp.h \
	regex.h \
	regexp.h \
	resolv.h \
	sched.h \
	search.h \
	semaphore.h \
	setjmp.h \
	sgtty.h \
	shadow.h \
	signal.h \
	spawn.h \
	stab.h \
	stdc-predef.h \
	stdint.h \
	stdio.h \
	stdio_ext.h \
	stdlib.h \
	string.h \
	strings.h \
	stropts.h \
	syscall.h \
	sysexits.h \
	syslog.h \
	tar.h \
	termio.h \
	termios.h \
	tgmath.h \
	thread_db.h \
	time.h \
	ttyent.h \
	uchar.h \
	ucontext.h \
	ulimit.h \
	unistd.h \
	ustat.h \
	utime.h \
	utmp.h \
	utmpx.h \
	values.h \
	wait.h \
	wchar.h \
	wctype.h \
	wordexp.h \
	xlocale.h \
	# end

pcfiles_Linux=\
	libudev.pc \
	# end

platform-skeleton: common-skeleton
	@echo "============================================"
	@echo "===  Create extra directories for Linux  ==="
	@echo "============================================"
	${MKDIR} \
		${DESTDIR}${BASE}/lib \
		${DESTDIR}${BASE}/lib64 \
		${DESTDIR}${BASE}/lib/x86_64-linux-gnu \
		${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu \
		${DESTDIR}${BASE}/usr/lib/pkgconfig \
		# end

install-platform: install-common
	@echo "================================="
	@echo "===  Linux file installation  ==="
	@echo "================================="
.  for item in ${Linux_static_libs}
	${BSD_INSTALL_DATA} ../linux/usr/lib/x86_64-linux-gnu/${item} ${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu/
.  endfor
.  for item in ${Linux_shared_libs}
	cp ${CPA} ../linux/lib/x86_64-linux-gnu/${item:H} ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/
	cp ${CPA} ../linux/lib/x86_64-linux-gnu/${item:T} ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/
	cp ${CPA} ../linux/usr/lib/x86_64-linux-gnu/${item:T:R} ${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu/
.  endfor
.  for item in ${Linux_RTLD}
	cp ${CPA} ../linux/lib/x86_64-linux-gnu/${item:H} ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/
	cp ${CPA} ../linux/lib/x86_64-linux-gnu/${item:T} ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/
.  endfor
.  for item in ${Linux_extra_libs1}
	cp ${CPA} ../linux/lib/x86_64-linux-gnu/${item:H} ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/
	cp ${CPA} ../linux/lib/x86_64-linux-gnu/${item:T} ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/
	cp ${CPA} ../linux/lib/x86_64-linux-gnu/${item:T:R} ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/
.  endfor
.  for item in ${Linux_extra_libs2}
	cp ${CPA} ../linux/usr/lib/x86_64-linux-gnu/${item:H} ${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu/
	cp ${CPA} ../linux/usr/lib/x86_64-linux-gnu/${item:T} ${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu/
.  endfor
.  for item in ${Linux_single_libs1}
	cp ${CPA} ../linux/lib/x86_64-linux-gnu/${item} ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/
.  endfor
.  for item in ${Linux_single_libs2}
	cp ${CPA} ../linux/usr/lib/x86_64-linux-gnu/${item} ${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu/
.  endfor
	ln -s /lib/x86_64-linux-gnu/${Linux_RTLD:H} ${DESTDIR}${BASE}/lib64/${Linux_RTLD:T}
	# symlink libgcc_s.so.1 which lpthread needs in a specific location
	ln -s /raven/toolchain/${GCCX}/lib64/libgcc_s.so.1 ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/libgcc_s.so.1
	# certain shared libraries must be executable
	chmod 755 ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/${Linux_RTLD:H}
	chmod 755 ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/${Linux_C_lib:H}
	chmod 755 ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/${Linux_thread_lib:H}
	# From linux-only shadow package
.  for sbinitem in useradd usermod groupadd
	cp ${CPA} ${LOCALBASE}/sbin/${sbinitem} ${DESTDIR}${BASE}/usr/bin/
.  endfor
	# lorder is system-specific.  Linux has it natively though
	${BSD_INSTALL_SCRIPT} ../linux/usr/bin/lorder ${DESTDIR}${BASE}/usr/bin/
	# ldd and which are scripts, can't be stripped
	${BSD_INSTALL_SCRIPT} ../linux/usr/bin/ldd ${DESTDIR}${BASE}/usr/bin/
	${BSD_INSTALL_SCRIPT} ../linux/bin/which ${DESTDIR}${BASE}/usr/bin/
	# convert ldd from bash to dash
	sed -i'' -e "s|/bin/bash|/bin/dash|" ${DESTDIR}${BASE}/usr/bin/ldd
	# i386 version conflicts with amd64 version, so copy just the i386 files separately
	cp ${CPA} ../ravensys-root-linux_14/usr/include/i386-linux-gnu ${DESTDIR}${BASE}/usr/include/
	# locales
	${MKDIR} ${DESTDIR}${BASE}/usr/lib/locale
	${MKDIR} ${DESTDIR}${BASE}/usr/share/i18n/charmaps
	${MKDIR} ${DESTDIR}${BASE}/usr/share/i18n/locales
	cp ${CPA} ../linux/usr/share/i18n/charmaps/UTF-8.gz ${DESTDIR}${BASE}/usr/share/i18n/charmaps/
	cp ${CPA} ../linux/usr/lib/locale/C.UTF-8 ${DESTDIR}${BASE}/usr/lib/locale/
.  for locale in C POSIX en_US en_GB iso14651_t1 iso14651_t1_common i18n translit_*
	cp ${CPA} ../linux/usr/share/i18n/locales/${locale} ${DESTDIR}${BASE}/usr/share/i18n/locales/
.  endfor
	env I18NPATH=${DESTDIR}${BASE}/usr/share/i18n ../linux/usr/bin/localedef --prefix=${DESTDIR}${BASE} -f UTF-8 -i en_US en_US.UTF-8
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


	# former "post-install" target
	${BSD_INSTALL_DATA} /port/files/linux-group \
		${DESTDIR}${BASE}/usr/share/group
	${BSD_INSTALL_DATA} /port/files/linux-passwd \
		${DESTDIR}${BASE}/usr/share/passwd
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/etc/ld.so.conf.d/x86_64-linux-gnu.conf \
		${DESTDIR}${BASE}/usr/share/x86_64-linux-gnu.conf
	echo "include /etc/ld.so.conf.d/*.conf" > ${DESTDIR}${BASE}/usr/share/ld.so.conf
	ln -s asm-generic ${DESTDIR}${BASE}/usr/include/asm
