# For NetBSD

Libexec_NetBSD=		/libexec/ld.elf_so

# no realpath in NetBSD

Bin_NetBSD=\
	/bin/[ \
	/usr/bin/chflags \
	/bin/chmod \
	/bin/cp \
	/bin/echo \
	/bin/expr \
	/bin/hostname \
	/bin/kill \
	/usr/sbin/link \
	/bin/ln \
	/bin/ls \
	/bin/mkdir \
	/bin/mv \
	/bin/pax \
	/bin/pwd \
	/bin/rm \
	/bin/rmdir \
	/bin/sh \
	/bin/sleep \
	/bin/test \
	/usr/sbin/unlink \
	# end

# chgrp is /bin/symlink to /sbin/chown
# no tsort

Usr_Bin_NetBSD= \
	/usr/bin/basename \
	/sbin/chown \
	/usr/bin/comm \
	/usr/bin/cut \
	/usr/bin/dirname \
	/usr/bin/env \
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
	/usr/bin/uniq \
	/usr/bin/which \
	/usr/bin/whoami \
	/usr/sbin/groupadd \
	/usr/sbin/useradd \
	# end

Usr_Sbin_NetBSD=\
	/usr/sbin/pwd_mkdb \
	/usr/sbin/paxctl \
	# end

static_lib_NetBSD=\
	/usr/lib/libc.a \
	/usr/lib/libm.a \
	/usr/lib/librt.a \
	/usr/lib/libutil.a \
	/usr/lib/libcrypt.a \
	/usr/lib/libcompat.a \
	/usr/lib/libdevmapper.a \
	/usr/lib/libresolv.a \
	/usr/lib/librpcsvc.a \
	/usr/lib/libpthread.a \
	/usr/lib/libkvm.a \
	/usr/lib/libusbhid.a \
	/usr/lib/libx86_64.a \
	/usr/lib/libpci.a \
	/usr/lib/libjemalloc.a \
	/usr/lib/libossaudio.a \
	/usr/lib/libposix.a \
	/usr/lib/libperfuse.a \
	/usr/lib/libprop.a \
	/usr/lib/libpuffs.a \
	/usr/lib/libquota.a \
	/usr/lib/crt0.o \
	/usr/lib/crtbegin.o \
	/usr/lib/crtbeginS.o \
	/usr/lib/crtbeginT.o \
	/usr/lib/crtend.o \
	/usr/lib/crtendS.o \
	/usr/lib/crti.o \
	/usr/lib/crtn.o \
	/usr/lib/gcrt0.o \
	# end

# /bin/sh (for now)
ONLY_SO=\
	/usr/lib/libedit.so.3 \
	/usr/lib/libterminfo.so.2 \
	/usr/lib/libexecinfo.so.0 \
	/usr/lib/libelf.so.2 \
	# end

dynamic_lib_NetBSD=\
	/usr/lib/libc.so.12 \
	/usr/lib/libm.so.0 \
	/usr/lib/libutil.so.7 \
	/usr/lib/libcrypt.so.1 \
	/usr/lib/libkvm.so.6 \
	/usr/lib/libresolv.so.3 \
	/usr/lib/librpcsvc.so.1 \
	/usr/lib/librt.so.1 \
	/usr/lib/libdevmapper.so.1 \
	/usr/lib/libpthread.so.1 \
	/usr/lib/libusbhid.so.1 \
	/usr/lib/libx86_64.so.0 \
	/usr/lib/libpci.so.2 \
	/usr/lib/libjemalloc.so.0 \
	/usr/lib/libossaudio.so.1 \
	/usr/lib/libposix.so.0 \
	/usr/lib/libperfuse.so.0 \
	/usr/lib/libprop.so.1 \
	/usr/lib/libpuffs.so.2 \
	/usr/lib/libquota.so.1 \
	${ONLY_SO} \
	# end

headers_NetBSD_dirs=\
	altq \
	amd64 \
	arpa \
	crypto \
	dev \
	event2 \
	fs \
	msdosfs \
	net \
	net80211 \
	netbt \
	netcan \
	netinet \
	netinet6 \
	netipsec \
	nfs \
	ntfs \
	prop \
	protocols \
	rpc \
	rpcsvc \
	security \
	ssp \
	sys \
	ufs \
	uvm \
	x86 \
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
	sha1.h \
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
	atomic.h \
	bitstring.h \
	bluetooth.h \
	dwarf.h \
	endian.h \
	elf.h \
	err.h \
	fstab.h \
	fts.h \
	getopt.h \
	ieeefp.h \
	ifaddrs.h \
	kvm.h \
	libproc.h \
	link.h \
	link_elf.h \
	login_cap.h \
	memory.h \
	mpool.h \
	netconfig.h \
	netgroup.h \
	netpgp.h \
	nlist.h \
	paths.h \
	res_update.h \
	resolv.h \
	sdp.h \
	sgtty.h \
	soundcard.h \
	stdalign.h \
	stdnoreturn.h \
	stringlist.h \
	sysexits.h \
	syslog.h \
	ttyent.h \
	ucontext.h \
	usbhid.h \
	utmp.h \
	vis.h \
	# end

headers_NetBSD=\
	${headers_BSD} \
	disktab.h \
	lwp.h \
	malloc.h \
	mntopts.h \
	pci.h \
	perfuse.h \
	pthread_queue.h \
	pthread_types.h \
	puffs.h \
	puffsdump.h \
	quota.h \
	regexp.h \
	re_comp.h \
	stab.h \
	struct.h \
	threads.h \
	unwind.h \
	util.h \
	uuid.h \
	# end

pcfiles_NetBSD=\
	# end



platform-skeleton: common-skeleton
	@echo "============================================="
	@echo "===  Create extra directories for NetBSD  ==="
	@echo "============================================="
	${MKDIR} \
		${DESTDIR}${BASE}/libexec \
		${DESTDIR}${BASE}/usr/lib/i18n \
		${DESTDIR}${BASE}/usr/share/etc \
		${DESTDIR}${BASE}/usr/share/locale/en_US.UTF-8/LC_MESSAGES \
		# end

install-platform: install-common
	@echo "=================================="
	@echo "===  NetBSD file installation  ==="
	@echo "=================================="

	(cd ${DESTDIR}${BASE}/usr/lib && \
		ln -s libc.so.12 libc.so && \
		ln -s libm.so.0 libm.so && \
		ln -s libutil.so.7 libutil.so && \
		ln -s libcrypt.so.1 libcrypt.so && \
		ln -s libkvm.so.6 libkvm.so && \
		ln -s libresolv.so.3 libresolv.so && \
		ln -s librpcsvc.so.1 librpcsvc.so && \
		ln -s librt.so.1 librt.so && \
		ln -s libdevmapper.so.1 libdevmapper.so && \
		ln -s libpthread.so.1 libpthread.so && \
		ln -s libpci.so.2 libpci.so && \
		ln -s libjemalloc.so.0 libjemalloc.so && \
		ln -s libossaudio.so.1 libossaudio.so && \
		ln -s libposix.so.0 libposix.so && \
		ln -s libperfuse.so.0 libperfuse.so && \
		ln -s libpuffs.so.2 libpuffs.so && \
		ln -s librop.so.1 libprop.so && \
		ln -s libquota.so.1 libquota.so && \
		ln -s libx86_64.so.0 libx86_64.so && \
		ln -s libusbhid.so.1 libusbhid.so)

	# use coreutils versions
.  for item in date
	cp ${CPA} ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/bin/${item}
.  endfor

.for SCRIPT in lorder false true
	${BSD_INSTALL_SCRIPT} ../${OPSYS:tl}/usr/bin/${SCRIPT} ${DESTDIR}${BASE}/usr/bin/
.endfor
	${BSD_INSTALL_PROGRAM} ../${OPSYS:tl}/sbin/chown ${DESTDIR}${BASE}/usr/bin/chgrp
	${BSD_INSTALL_PROGRAM} ${LOCALBASE}/bin/bsd_realpath \
		${DESTDIR}${BASE}/bin/realpath

	# locale information
.  for LC in CTYPE MONETARY NUMERIC TIME
	cp ../${OPSYS:tl}/usr/share/locale/en_US.UTF-8/LC_${LC} \
		${DESTDIR}${BASE}/usr/share/locale/en_US.UTF-8/
.  endfor
	cp ../${OPSYS:tl}/usr/share/locale/en_US.UTF-8/LC_MESSAGES/SYS_LC_MESSAGES \
		${DESTDIR}${BASE}/usr/share/locale/en_US.UTF-8/LC_MESSAGES/
	cp ../${OPSYS:tl}/usr/lib/i18n/libUTF8.so.5.0 \
		${DESTDIR}${BASE}/usr/lib/i18n/

	# former "post-install" target
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/etc/group \
		${DESTDIR}${BASE}/usr/share/group
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/etc/master.passwd \
		${DESTDIR}${BASE}/usr/share/master.passwd
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/etc/defaults/rc.conf \
		${DESTDIR}${BASE}/usr/share/rc.conf
	/usr/sbin/pwd_mkdb -p -d ${DESTDIR}${BASE}/usr/share \
		${DESTDIR}${BASE}/usr/share/master.passwd
	mv ${DESTDIR}${BASE}/usr/share/etc/* ${DESTDIR}${BASE}/usr/share
	rmdir ${DESTDIR}${BASE}/usr/share/etc
	rmdir ${DESTDIR}${BASE}/usr/include/dev/ieee1394

	ln -s /libexec/ld.elf_so ${DESTDIR}${BASE}/usr/libexec/ld.elf_so
	echo "Dummy - not used on NetBSD/AMD64" > ${DESTDIR}${BASE}/usr/share/ld.so.hints

	ln -s amd64 ${DESTDIR}${BASE}/usr/include/machine

	# entire timezone data
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/share/zoneinfo/UTC \
                ${DESTDIR}${BASE}/usr/share/localtime
