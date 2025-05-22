# For DragonFly

Libexec_DragonFly=	/libexec/ld-elf.so.2

Bin_DragonFly=\
	/bin/[ \
	/usr/bin/chflags \
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

Usr_Bin_DragonFly= \
	/usr/bin/basename \
	/usr/bin/chgrp \
	/usr/sbin/chown \
	/usr/bin/comm \
	/usr/bin/cut \
	/usr/bin/dirname \
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

Usr_Sbin_DragonFly=\
	/usr/sbin/pw \
	/usr/sbin/pwd_mkdb \
	# end

static_lib_DragonFly=\
	/usr/lib/libc.a \
	/usr/lib/libm.a \
	/usr/lib/librt.a \
	/usr/lib/libutil.a \
	/usr/lib/libcrypt.a \
	/usr/lib/librpcsvc.a \
	/usr/lib/libpthread.a \
	/usr/lib/libcam.a \
	/usr/lib/libkvm.a \
	/usr/lib/libsbuf.a \
	/usr/lib/libusb.a \
	/usr/lib/libusbhid.a \
	/usr/lib/Scrt1.o \
	/usr/lib/gcrt1.o \
	/usr/lib/crt1.o \
	/usr/lib/crti.o \
	/usr/lib/crtn.o \
	# end

dynamic_lib_DragonFly=\
	/lib/libc.so.8 \
	/lib/libm.so.4 \
	/lib/libutil.so.4 \
	/lib/libcrypt.so.4 \
	/lib/libkvm.so.3 \
	/lib/libcam.so.3 \
	/lib/libsbuf.so.3 \
	/lib/libprop.so.3 \
	/lib/libdevattr.so.3 \
	/lib/libdevstat.so.3 \
	/usr/lib/librpcsvc.so.3 \
	/usr/lib/librt.so.0 \
	/usr/lib/libdevinfo.so.3 \
	/usr/lib/libdevmapper.so.0 \
	/usr/lib/libkinfo.so.2 \
	/usr/lib/libpthread.so \
	/usr/lib/libpthread.so.0 \
	/usr/lib/libexecinfo.so.1 \
	/usr/lib/libusb.so.2 \
	/usr/lib/libusbhid.so.4 \
	# end

headers_DragonFly_dirs=\
	arpa \
	bus \
	cpu \
	crypto \
	dev \
	libprop \
	machine \
	net \
	netbt \
	netinet \
	netinet6 \
	netproto \
	protocols \
	rpc \
	rpcsvc \
	sys \
	vfs \
	vm \
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
	kenv.h \
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
	readpassphrase.h \
	res_update.h \
	resolv.h \
	runetype.h \
	sdp.h \
	stdalign.h \
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

.if "${OSREL}" == "6.4"
headers_BSD+=\
	malloc_np.h \
	# end
.endif

headers_DragonFly=\
	${headers_BSD} \
	devattr.h \
	dfregress.h \
	disktab.h \
	evtr.h \
	kinfo.h \
	kinfo_pcpu.h \
	libcryptsetup.h \
	luks.h \
	mntopts.h \
	re_comp.h \
	util.h \
	# end

pcfiles_DragonFly=\
	libusb-0.1.pc \
	libusb-2.0.pc \
	libusb-1.0.pc \
	# end

platform-skeleton: common-skeleton
	@echo "================================================"
	@echo "===  Create extra directories for DragonFly  ==="
	@echo "================================================"
	${MKDIR} \
		${DESTDIR}${BASE}/libexec \
		${DESTDIR}${BASE}/usr/include/compat \
		${DESTDIR}${BASE}/usr/share/locale/en_US.UTF-8 \
		${DESTDIR}${BASE}/usr/lib/gcc80 \
		# end

install-platform: install-common
	@echo "====================================="
	@echo "===  DragonFly file installation  ==="
	@echo "====================================="
	(cd ${DESTDIR}${BASE}/usr/lib && \
		ln -s libm.so.4 libm.so && \
		ln -s librt.so.0 librt.so && \
		ln -s libkvm.so.3 libkvm.so && \
		ln -s libcam.so.3 libcam.so && \
		ln -s libcrypt.so.4 libcrypt.so && \
		ln -s libutil.so.4 libutil.so && \
		ln -s librpcsvc.so.3 librpcsvc.so && \
		ln -s libusb.so.2 libusb.so && \
		ln -s libusbhid.so.4 libusbhid.so && \
		ln -s libc.so.8 libc.so && \
		ln -s libsbuf.so.3 libsbuf.so && \
		ln -s libprop.so.3 libprop.so && \
		ln -s libdevattr.so.3 libdevattr.so && \
		ln -s libdevstat.so.3 libdevstat.so && \
		ln -s libdevinfo.so.3 libdevinfo.so && \
		ln -s libkinfo.so.2 libkinfo.so && \
		ln -s libdevmapper.so.0 libdevmapper.so)		
	${BSD_INSTALL_SCRIPT} ../${OPSYS:tl}/usr/bin/lorder ${DESTDIR}${BASE}/usr/bin/
	(cd ${DESTDIR}${BASE}/usr/include && \
		ln -s ../dev/misc/evdev compat/linux && \
		ln -s vfs fs && \
		ln -s vfs ufs && \
		ln -s vfs/nfs nfs && \
		ln -s vfs/ntfs ntfs && \
		ln -s vfs/isofs isofs && \
		ln -s vfs/msdosfs msdosfs && \
		ln -s netproto/smb netsmb && \
		ln -s bus/pccard pccard && \
		ln -s bus/cam cam)
.  for item in gcc80/libstdc++.so.9
	${BSD_INSTALL_LIB} ../${OPSYS:tl}/usr/lib/${item} ${DESTDIR}${BASE}/usr/lib/${item}
.  endfor
.  for item in gcc80/libgcc_pic.a
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/lib/${item} ${DESTDIR}${BASE}/usr/lib/${item}
.  endfor

	rm ${DESTDIR}${BASE}/usr/include/net/zlib.h
	rm -rf ${DESTDIR}${BASE}/usr/include/net/ipfw*
	rm -rf ${DESTDIR}${BASE}/usr/include/net/pf
	rmdir  ${DESTDIR}${BASE}/usr/include/vfs/mfs
	# fix timespec* for c++17
	sed -i '/if __ISO_C_VISIBLE >= 2011$$/ s#$$# || (defined(__cplusplus) \&\& __cplusplus >= 201703) &#' \
		${DESTDIR}${BASE}/usr/include/time.h

	# locale information
.  for LC in COLLATE CTYPE MESSAGES MONETARY NUMERIC TIME
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/share/locale/en_US.UTF-8/LC_${LC} \
		${DESTDIR}${BASE}/usr/share/locale/en_US.UTF-8/
.  endfor

	# former "post-install" target
	sed -e '/^git_daemon:/d; /^dhcpd:/d' ../${OPSYS:tl}/etc/group \
		> ${DESTDIR}${BASE}/usr/share/group
	sed -e '/^git_daemon:/d; /^dhcpd:/d' ../${OPSYS:tl}/etc/master.passwd \
		> ${DESTDIR}${BASE}/usr/share/master.passwd
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
