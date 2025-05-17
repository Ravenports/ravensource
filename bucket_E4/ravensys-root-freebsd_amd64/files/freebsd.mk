# For FreeBSD

Libexec_FreeBSD=	/libexec/ld-elf.so.1

Bin_FreeBSD=\
	/bin/[ \
	/bin/chflags \
	/bin/chmod \
	/bin/cp \
	/bin/date \
	/bin/echo \
	/bin/expr \
	/bin/hostname \
	/bin/kill \
	/bin/link \
	/bin/ln \
	/rescue/ls \
	/bin/mkdir \
	/bin/mv \
	/bin/pax \
	/bin/pwd \
	/bin/realpath \
	/bin/rm \
	/bin/rmdir \
	/rescue/sh \
	/bin/sleep \
	/bin/test \
	/bin/unlink \
	# end

Usr_Bin_FreeBSD=\
	/usr/bin/basename \
	/usr/bin/chgrp \
	/usr/sbin/chown \
	/usr/bin/comm \
	/usr/bin/cut \
	/usr/bin/dirname \
	/usr/bin/elfctl \
	/usr/bin/env \
	/usr/bin/false \
	/usr/bin/head \
	/usr/bin/id \
	/usr/bin/join \
	/usr/bin/ldd \
	/usr/bin/mkfifo \
	/usr/bin/mktemp \
	/usr/bin/printenv \
	/usr/bin/printf \
	/usr/bin/readlink \
	/usr/bin/stat \
	/usr/bin/tail \
	/usr/bin/tee \
	/usr/bin/touch \
	/usr/bin/tr \
	/usr/bin/true \
	/usr/bin/tsort \
	/usr/bin/uniq \
	/usr/bin/which \
	/usr/bin/whoami \
	# end

Usr_Sbin_FreeBSD=\
	/usr/sbin/pw \
	/usr/sbin/pwd_mkdb \
	# end

static_lib_FreeBSD=\
	/usr/lib/libc.a \
	/usr/lib/libm.a \
	/usr/lib/librt.a \
	/usr/lib/libutil.a \
	/usr/lib/libcrypt.a \
	/usr/lib/librpcsvc.a \
	/usr/lib/libpthread.a \
	/usr/lib/libbsdxml.a \
	/usr/lib/libcam.a \
	/usr/lib/libcompat.a \
	/usr/lib/libdevstat.a \
	/usr/lib/libgeom.a \
	/usr/lib/libkvm.a \
	/usr/lib/libmemstat.a \
	/usr/lib/libprocstat.a \
	/usr/lib/libthr.a \
	/usr/lib/libusb.a \
	/usr/lib/libusbhid.a \
	/usr/lib/libjail.a \
	/usr/lib/libsbuf.a \
	/usr/lib/libc_nonshared.a \
	/usr/lib/libssp_nonshared.a \
	/usr/lib/Scrt1.o \
	/usr/lib/gcrt1.o \
	/usr/lib/crt1.o \
	/usr/lib/crti.o \
	/usr/lib/crtn.o \
	# end

dynamic_lib_FreeBSD=\
	/lib/libc.so.7 \
	/lib/libm.so.5 \
	/lib/libutil.so.9 \
	/lib/libcrypt.so.5 \
	/lib/libkvm.so.7 \
	/lib/libcam.so.7 \
	/lib/libbsdxml.so.4 \
	/lib/libelf.so.2 \
	/lib/libgeom.so.5 \
	/lib/libsbuf.so.6 \
	/lib/libthr.so.3 \
	/lib/libdevstat.so.7 \
	/lib/libjail.so.1 \
	/lib/libcasper.so.1 \
	/lib/libnv.so.0 \
	/usr/lib/libdevinfo.so.6 \
	/usr/lib/libexecinfo.so.1 \
	/usr/lib/libmemstat.so.3 \
	/usr/lib/librpcsvc.so.5\
	/usr/lib/librt.so.1 \
	/usr/lib/libprocstat.so.1 \
	/usr/lib/libusb.so.3 \
	/usr/lib/libusbhid.so.4 \
	# end

headers_FreeBSD_dirs=\
	arpa \
	cam \
	crypto \
	dev \
	fs \
	geom \
	machine \
	net \
	net80211 \
	netipsec \
	netinet \
	netinet6 \
	nfsclient \
	rpc \
	rpcsvc \
	sys \
	ufs \
	vm \
	x86 \
	xlocale \
	# end

posix_headers=\
	aio.h \
	assert.h \
	complex.h \
	cpio.h \
	ctype.h \
	dirent.h \
	dlfcn.h \
	errno.h \
	fcntl.h \
	fenv.h \
	float.h \
	fmtmsg.h \
	fnmatch.h \
	ftw.h \
	glob.h \
	grp.h \
	iconv.h \
	inttypes.h \
	iso646.h \
	langinfo.h \
	libgen.h \
	limits.h \
	locale.h \
	math.h \
	monetary.h \
	mqueue.h \
	ndbm.h \
	netdb.h \
	nl_types.h \
	poll.h \
	pthread.h \
	pwd.h \
	regex.h \
	sched.h \
	search.h \
	semaphore.h \
	setjmp.h \
	signal.h \
	spawn.h \
	stdarg.h \
	stdbool.h \
	stddef.h \
	stdint.h \
	stdio.h \
	stdlib.h \
	string.h \
	strings.h \
	syslog.h \
	tar.h \
	termios.h \
	tgmath.h \
	time.h \
	ulimit.h \
	unistd.h \
	utime.h \
	utmpx.h \
	wchar.h \
	wctype.h \
	wordexp.h \
	# end

headers_BSD=\
	${posix_headers} \
	ar.h \
	bitstring.h \
	bluetooth.h \
	camlib.h \
	db.h \
	devinfo.h \
	devstat.h \
	efivar.h \
	elf-hints.h \
	elf.h \
	endian.h \
	err.h \
	floatingpoint.h \
	fstab.h \
	fts.h \
	getopt.h \
	ieeefp.h \
	ifaddrs.h \
	kvm.h \
	libusb.h \
	libusb20.h \
	libusb20_desc.h \
	libutil.h \
	link.h \
	linker_set.h \
	login_cap.h \
	memory.h \
	mpool.h \
	netconfig.h \
	nlist.h \
	osreldate.h \
	paths.h \
	printf.h \
	pthread_np.h \
	proc_service.h \
	readpassphrase.h \
	res_update.h \
	resolv.h \
	runetype.h \
	sdp.h \
	stdalign.h \
	stdatomic.h \
	stdnoreturn.h \
	stringlist.h \
	sysexits.h \
	syslog.h \
	timeconv.h \
	timers.h \
	ttyent.h \
	uchar.h \
	ucontext.h \
	usb.h \
	usbhid.h \
	uuid.h \
	vis.h \
	xlocale.h \
	# end

headers_FreeBSD=\
	${headers_BSD} \
	_ctype.h \
	bsm/audit.h \
	libusb20.h \
	libusb20_desc.h \
	kenv.h \
	libgeom.h \
	libprocstat.h \
	malloc_np.h \
	jail.h \
	# end

.if "${OSMAJOR}" == "13"
headers_FreeBSD+= threads.h
.endif

pcfiles_FreeBSD=\
	libusb-0.1.pc \
	libusb-2.0.pc \
	libusb-1.0.pc \
	# end

platform-skeleton: common-skeleton
	@echo "=============================================="
	@echo "===  Create extra directories for FreeBSD  ==="
	@echo "=============================================="
	${MKDIR} \
		${DESTDIR}${BASE}/libexec \
		${DESTDIR}${BASE}/usr/include/bsm \
		${DESTDIR}${BASE}/usr/share/locale/en_US.UTF-8 \
		# end

install-platform: install-common
	@echo "==================================="
	@echo "===  FreeBSD file installation  ==="
	@echo "==================================="
	(cd ${DESTDIR}${BASE}/usr/lib && \
		ln -s libm.so.5 libm.so && \
		ln -s librt.so.1 librt.so && \
		ln -s libkvm.so.7 libkvm.so && \
		ln -s libmemstat.so.3 libmemstat.so && \
		ln -s libcam.so.7 libcam.so && \
		ln -s libcrypt.so.5 libcrypt.so && \
		ln -s libutil.so.9 libutil.so && \
		ln -s librpcsvc.so.5 librpcsvc.so && \
		ln -s libusb.so.3 libusb.so && \
		ln -s libusbhid.so.4 libusbhid.so && \
		ln -s libthr.so.3 libthr.so && \
		ln -s libbsdxml.so.4 libbsdxml.so && \
		ln -s libdevstat.so.7 libdevstat.so && \
		ln -s libdevinfo.so.6 libdevinfo.so && \
		ln -s libprocstat.so.1 libprocstat.so && \
		ln -s libgeom.so.5 libgeom.so && \
		ln -s ${PREFIX}/lib/libexecinfo.so libexecinfo.so && \
		ln -s libthr.so libpthread.so && \
		ln -s libjail.so.1 libjail.so)
	${BSD_INSTALL_LIB} ../${OPSYS:tl}/lib/libgcc_s.so.1 ${DESTDIR}${BASE}/usr/lib/
	${BSD_INSTALL_LIB} ../${OPSYS:tl}/lib/libcxxrt.so.1 ${DESTDIR}${BASE}/usr/lib/
	${BSD_INSTALL_LIB} ../${OPSYS:tl}/usr/lib/libc++.so.1 ${DESTDIR}${BASE}/usr/lib/
.if "${OSMAJOR}" == "13"
	${BSD_INSTALL_LIB} ../${OPSYS:tl}/lib/casper/libcap_fileargs.so.1 \
		${DESTDIR}${BASE}/usr/lib/
	${BSD_INSTALL_LIB} ../${OPSYS:tl}/usr/lib/libstdthreads.so.0 \
		${DESTDIR}${BASE}/usr/lib/
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/lib/libstdthreads.a \
		${DESTDIR}${BASE}/usr/lib/
	(cd ${DESTDIR}${BASE}/usr/lib && \
		ln -s libstdthreads.so.0 libstdthreads.so \
	)
.endif
	sed -e 's|/lib/libc\.so|/usr/lib/libc.so|'  ../${OPSYS:tl}/usr/lib/libc.so \
		> ${DESTDIR}${BASE}/usr/lib/libc.so
	${BSD_INSTALL_SCRIPT} ../${OPSYS:tl}/usr/bin/lorder ${DESTDIR}${BASE}/usr/bin/

	rmdir ${DESTDIR}${BASE}/usr/include/dev/powermac_nvram
.if "${OSMAJOR}" == "12"
	rmdir ${DESTDIR}${BASE}/usr/include/dev/nand
.endif
.if "${OSMAJOR}" == "13"
	rmdir ${DESTDIR}${BASE}/usr/include/dev/wi
.endif
	
	# locale information
.  for LC in COLLATE CTYPE MESSAGES MONETARY NUMERIC TIME
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/share/locale/en_US.UTF-8/LC_${LC} \
		${DESTDIR}${BASE}/usr/share/locale/en_US.UTF-8/
.  endfor

	# former "post-install" target
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/etc/group \
		${DESTDIR}${BASE}/usr/share/group
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/etc/master.passwd \
		${DESTDIR}${BASE}/usr/share/master.passwd
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/etc/defaults/rc.conf \
		${DESTDIR}${BASE}/usr/share/rc.conf
	/usr/sbin/pwd_mkdb -p -d ${DESTDIR}${BASE}/usr/share \
		${DESTDIR}${BASE}/usr/share/master.passwd
	${MKDIR} ${DESTDIR}${BASE}/var/run
	# handle ldconfig hints
	${BSD_INSTALL_PROGRAM} ../${OPSYS:tl}/sbin/ldconfig \
		${DESTDIR}${BASE}/usr/bin/ldconfig
	../${OPSYS:tl}/usr/sbin/chroot ${DESTDIR}${BASE} /usr/bin/ldconfig /usr/lib
	rm ${DESTDIR}${BASE}/usr/bin/ldconfig
	mv ${DESTDIR}${BASE}/var/run/ld-elf.so.hints \
		${DESTDIR}${BASE}/usr/share/
	rm -rf ${DESTDIR}${BASE}/var
