# Create identical sysroot regardless of host system

all: sysroot

Libexec_DragonFly=	/libexec/ld-elf.so.2
Libexec_FreeBSD=	/libexec/ld-elf.so.1
Libexec_Linux=		# empty

Libelf_FreeBSD=		libelf.so.2
Libthr_FreeBSD=		libthr.so.3
Libsbuf_FreeBSD=	libsbuf.so.6
Libdevstat_FreeBSD=	libdevstat.so.7
Libprocstat_FreeBSD=	libprocstat.so.1
Libgeom_FreeBSD=	libgeom.so.5
Libbsdxml_FreeBSD=	libbsdxml.so.4

CPA=			-RpP

# /bin/cat    (archivers/libarchive)
# /bin/md5    (security/sha256)
# /bin/sha256 (security/sha256)

Bin_DragonFly=	/bin/[ \
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
		/bin/unlink

Bin_FreeBSD=	/bin/[ \
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

Bin_Linux=	/bin/hostname \
		/bin/pax \
		/bin/dash \
		/bin/sh \
		# rest comes form coreutils

# /usr/bin/awk    (lang/nawk)
# /usr/bin/cpio	  (archivers/libarchive)
# /usr/bin/bzip2* (archivers/bzip2)
# /usr/bin/cmp    (textproc/diffutils)
# /usr/bin/diff*  (textproc/diffutils)
# /usr/bin/grep*  (textproc/gnugrep)
# /usr/bin/fetch  (ftp/fetch)
# /usr/bin/file   (sysutils/file)
# /usr/bin/find   (misc/findutils)
# /usr/bin/flex*  (textproc/flex)
# /usr/bin/gzip*  (archivers/gzip)
# /usr/bin/uname  (sysutils/uname)
# /usr/bin/unzip  (archivers/unzip)
# /usr/bin/xz*    (archivers/xz)
# /usr/bin/m4     (devel/m4)
# /usr/bin/make   (devel/bmake)
# /usr/bin/sed    (textproc/gsed)
# /usr/bin/tar    (archivers/libarchive)
# /usr/bin/xargs  (misc/findutils)
# /usr/bin/yacc   (devel/byacc)
# /usr/bin/less*  (sysutils/less)
# /usr/bin/mtree  (sysutils/mtree)
# /usr/bin/sort   (sysutils/coreutils)
# /usr/bin/objdump-sysroot (devel/binutils)

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

Usr_Bin_FreeBSD=	${Usr_Bin_DragonFly}

Usr_Bin_Linux=	# all come from coreutils except two
		# /bin/which and /usr/bin/ldd are scripts, special handling

Usr_Sbin_DragonFly= 	/usr/sbin/pw \
			/usr/sbin/pwd_mkdb \
			# end
Usr_Sbin_FreeBSD=	${Usr_Sbin_DragonFly}
Usr_Sbin_Linux=		# end

static_lib_generic=	/usr/lib/libc.a \
			/usr/lib/libm.a \
			/usr/lib/librt.a \
			/usr/lib/libutil.a \
			/usr/lib/libcrypt.a \
			/usr/lib/librpcsvc.a \
			/usr/lib/libpthread.a
static_lib_FreeBSD=	${static_lib_generic} \
			/usr/lib/libbsdxml.a \
			/usr/lib/libcam.a \
			/usr/lib/libcompat.a \
			/usr/lib/libdevstat.a \
			/usr/lib/libgeom.a \
			/usr/lib/libkvm.a \
			/usr/lib/libprocstat.a \
			/usr/lib/libthr.a \
			/usr/lib/libusb.a \
			/usr/lib/libusbhid.a \
			/usr/lib/libjail.a \
			/usr/lib/libsbuf.a \
			/usr/lib/Scrt1.o \
			/usr/lib/gcrt1.o \
			/usr/lib/crt1.o \
			/usr/lib/crti.o \
			/usr/lib/crtn.o
static_lib_DragonFly=	${static_lib_generic} \
			/usr/lib/libcam.a \
			/usr/lib/libkvm.a \
			/usr/lib/libsbuf.a \
			/usr/lib/libusb.a \
			/usr/lib/libusbhid.a \
			/usr/lib/Scrt1.o \
			/usr/lib/gcrt1.o \
			/usr/lib/crt1.o \
			/usr/lib/crti.o \
			/usr/lib/crtn.o
static_lib_Linux=	# Linux doesn't use /usr/lib but a sudirectory, needs special list
Linux_static_libs=	libc.a \
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
dynamic_generic=	/lib/${libc} \
			/lib/${libm} \
			/lib/${libutil} \
			/lib/${libcrypt} \
			/lib/${libkvm} \
			/usr/lib/${librpcsvc} \
			/usr/lib/${librt}
dynamic_lib_FreeBSD=	${dynamic_generic} \
			/lib/${Libbsdxml_FreeBSD} \
			/lib/${Libelf_FreeBSD} \
			/lib/${Libgeom_FreeBSD} \
			/lib/${Libsbuf_FreeBSD} \
			/lib/${Libthr_FreeBSD} \
			/lib/${Libdevstat_FreeBSD} \
			/usr/lib/libexecinfo.so.1 \
			/lib/libjail.so.1 \
			/usr/lib/${Libprocstat_FreeBSD} \
			/usr/lib/${libusb} \
			/usr/lib/${libusbhid}
dynamic_lib_DragonFly=	${dynamic_generic} \
			/lib/libcam.so.3 \
			/lib/libsbuf.so.3 \
			/lib/libprop.so.3 \
			/lib/libdevattr.so.3 \
			/lib/libdevstat.so.3 \
			/usr/lib/libdevinfo.so.3 \
			/usr/lib/libdevmapper.so.0 \
			/usr/lib/libpthread.so \
			/usr/lib/libpthread.so.0 \
			/usr/lib/libexecinfo.so.1 \
			/usr/lib/${libusb} \
			/usr/lib/${libusbhid}
dynamic_lib_Linux=	# Linux doesn't use /usr/lib, needs special list
Linux_RTLD=		ld-2.23.so/ld-linux-x86-64.so.2
Linux_C_lib=		libc-2.23.so/libc.so.6
Linux_thread_lib=	libpthread-2.23.so/libpthread.so.0
			# /lib/x86_64-linux-gnu => /lib64
			# real file / soname (also symlink)
			# use to create /usr/lib64/<lib>.so => /lib64/soname
Linux_shared_libs=	${Linux_C_lib} \
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
			# end
Linux_extra_libs1=	libattr.so.1.1.0/libattr.so.1 \
			libacl.so.1.1.0/libacl.so.1 \
			# end (/lib)
Linux_extra_libs2=	# libustr-1.0.so.1.0.4/libustr-1.0.so.1 \
			# end (/usr/lib)
Linux_single_libs1=	# end (/lib/TARGET)
Linux_single_libs2=	# libsemanage.so.1 \
			# end (/usr/lib/TARGET)
posix_headers=		aio.h \
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
			stropts.h \
			syslog.h \
			tar.h \
			termios.h \
			tgmath.h \
			time.h \
			trace.h \
			ulimit.h \
			unistd.h \
			utime.h \
			utmpx.h \
			wchar.h \
			wctype.h \
			wordexp.h \
			# end

headers_SunOS_dirs=	#end
headers_SunOS=		#end

headers_Darwin_dirs=	#end
headers_Darwin=		#end

headers_FreeBSD_dirs=	arpa \
			cam \
			crypto \
			dev \
			geom \
			machine \
			net \
			net80211 \
			netipsec \
			netinet \
			netinet6 \
			rpc \
			rpcsvc \
			sys \
			vm \
			x86 \
			xlocale \
			# end

headers_DragonFly_dirs=	arpa \
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

headers_DragonFly=	${posix_headers:Nstropts.h:Ntrace.h} \
			ar.h \
			bitstring.h \
			bluetooth.h \
			camlib.h \
			devattr.h \
			devinfo.h \
			devstat.h \
			dfregress.h \
			disktab.h \
			efivar.h \
			elf-hints.h \
			elf.h \
			err.h \
			evtr.h \
			floatingpoint.h \
			fstab.h \
			fts.h \
			getopt.h \
			ieeefp.h \
			ifaddrs.h \
			kvm.h \
			libcryptsetup.h \
			libusb.h \
			libusb20.h \
			libusb20_desc.h \
			libutil.h \
			link.h \
			linker_set.h \
			login_cap.h \
			luks.h \
			memory.h \
			mntopts.h \
			mpool.h \
			netconfig.h \
			nlist.h \
			osreldate.h \
			paths.h \
			printf.h \
			pthread_np.h \
			re_comp.h \
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
			util.h \
			utmp.h \
			uuid.h \
			vis.h \
			xlocale.h \
			# end

headers_FreeBSD=	${headers_DragonFly:Nutil.h:Ndevattr.h:Ndfregress.h:Ndisktab.h:Nevtr.h:Nlibcryptsetup.h:Nluks.h:Nmntopts.h:Nre_comp.h:Nutmp.h} \
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

headers_Linux_dirs=	acl \
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
			scsi \
			sys \
			x86_64-linux-gnu \
			#end
headers_Linux=		_G_config.h \
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

pcfiles_Linux=		# end
pcfiles_SunOS=		# end
pcfiles_Darwin=		# end
pcfiles_FreeBSD=	libusb-0.1.pc \
			libusb-2.0.pc \
			libusb-1.0.pc \
			# end
pcfiles_DragonFly=	libusb-0.1.pc \
			libusb-2.0.pc \
			libusb-1.0.pc \
			# end

sysroot:
	@echo "building not required"

install:
.if "${OPSYS}" == "Darwin"
	${MKDIR} ${DESTDIR}/${BASE}
	mv ../${OPSYS:tl}/* ${DESTDIR}${BASE}/
.endif
	${MKDIR} \
		${DESTDIR}${BASE}/bin \
		${DESTDIR}${BASE}/usr/bin \
		${DESTDIR}${BASE}/usr/include \
		${DESTDIR}${BASE}/usr/lib/pkgconfig \
		${DESTDIR}${BASE}/usr/share/file \
		${DESTDIR}${BASE}/usr/local \
		${DESTDIR}${BASE}/usr/include/arpa \
		${DESTDIR}${BASE}/usr/include/net \
		${DESTDIR}${BASE}/usr/include/netinet \
		${DESTDIR}${BASE}/usr/include/rpc \
		${DESTDIR}${BASE}/usr/include/rpcsvc \
		${DESTDIR}${BASE}/usr/sbin \
		# end
.if "${OPSYS}" == "DragonFly"
	${MKDIR} \
		${DESTDIR}${BASE}/libexec \
		${DESTDIR}${BASE}/usr/include/compat \
		${DESTDIR}${BASE}/usr/share/locale/en_US.UTF-8 \
		${DESTDIR}${BASE}/usr/lib/gcc80 \
		# end
.endif
.if "${OPSYS}" == "FreeBSD"
	${MKDIR} \
		${DESTDIR}${BASE}/libexec \
		${DESTDIR}${BASE}/usr/include/bsm \
		${DESTDIR}${BASE}/usr/share/locale/en_US.UTF-8 \
		# end
.endif
.if "${OPSYS}" == "Linux"
	${MKDIR} \
		${DESTDIR}${BASE}/lib \
		${DESTDIR}${BASE}/lib64 \
		${DESTDIR}${BASE}/lib/x86_64-linux-gnu \
		${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu \
		# end
.endif

.if "${OPSYS}" == "SunOS"
	cp ${CPA} ../${OPSYS:tl}/* ${DESTDIR}${BASE}/
	# use BSD's which
	${BSD_INSTALL_PROGRAM} ${LOCALBASE}/bin/which ${DESTDIR}${BASE}/usr/bin/
	# /bin/sh is really /usr/xpg4/bin/sh, move it there
	# Move /usr/bin/bash (from distro) to /bin/bash
	# hardlink /bin/bash to /bin/sh
	mkdir -p ${DESTDIR}${BASE}/usr/xpg4/bin
	mv ${DESTDIR}${BASE}/bin/sh ${DESTDIR}${BASE}/usr/xpg4/bin/
	mv ${DESTDIR}${BASE}/usr/bin/bash ${DESTDIR}${BASE}/bin/bash
	ln ${DESTDIR}${BASE}/bin/bash ${DESTDIR}${BASE}/bin/sh
.elif "${OPSYS}" == "Darwin"
	# do nothing
.else
.  for item in ${Bin_${OPSYS}}
	${BSD_INSTALL_PROGRAM} ../${OPSYS:tl}${item} ${DESTDIR}${BASE}/bin/
.  endfor
.  for item in ${Usr_Bin_${OPSYS}}
	${BSD_INSTALL_PROGRAM} ../${OPSYS:tl}${item} ${DESTDIR}${BASE}/usr/bin/
.  endfor
.  for item in ${Usr_Sbin_${OPSYS}}
	${BSD_INSTALL_PROGRAM} ../${OPSYS:tl}${item} ${DESTDIR}${BASE}/usr/sbin/
.  endfor
.  for item in ${Libexec_${OPSYS}}
	${BSD_INSTALL_PROGRAM} ../${OPSYS:tl}${item} ${DESTDIR}${BASE}/libexec/
.  endfor
.  for item in ${dynamic_lib_${OPSYS}}
	${BSD_INSTALL_LIB} ../${OPSYS:tl}${item} ${DESTDIR}${BASE}/usr/lib/
.  endfor
.  for item in ${static_lib_${OPSYS}}
	${BSD_INSTALL_DATA} ../${OPSYS:tl}${item} ${DESTDIR}${BASE}/usr/lib/
.  endfor
.endif
.if ${OPSYS} == DragonFly || ${OPSYS} == FreeBSD
	(cd ${DESTDIR}${BASE}/usr/lib && \
		ln -s ${libc} libc.so && \
		ln -s ${libm} libm.so && \
		ln -s ${librt} librt.so && \
		ln -s ${libkvm} libkvm.so && \
		ln -s ${libcrypt} libcrypt.so && \
		ln -s ${libutil} libutil.so && \
		ln -s ${librpcsvc} librpcsvc.so && \
		ln -s ${libusb} libusb.so && \
		ln -s ${libusbhid} libusbhid.so)
	${BSD_INSTALL_SCRIPT} ../${OPSYS:tl}/usr/bin/lorder ${DESTDIR}${BASE}/usr/bin/
.endif
.if ${OPSYS} == FreeBSD
	(cd ${DESTDIR}${BASE}/usr/lib && \
		ln -s ${Libthr_FreeBSD} libthr.so && \
		ln -s ${Libbsdxml_FreeBSD} libbsdxml.so && \
		ln -s ${Libdevstat_FreeBSD} libdevstat.so && \
		ln -s ${Libprocstat_FreeBSD} libprocstat.so && \
		ln -s ${Libgeom_FreeBSD} libgeom.so && \
		ln -s ${PREFIX}/lib/libexecinfo.so libexecinfo.so && \
		ln -s libthr.so libpthread.so && \
		ln -s libjail.so.1 libjail.so)
	${BSD_INSTALL_LIB} ../${OPSYS:tl}/lib/libgcc_s.so.1 ${DESTDIR}${BASE}/usr/lib/
	${BSD_INSTALL_LIB} ../${OPSYS:tl}/lib/libcxxrt.so.1 ${DESTDIR}${BASE}/usr/lib/
	${BSD_INSTALL_LIB} ../${OPSYS:tl}/usr/lib/libc++.so.1 ${DESTDIR}${BASE}/usr/lib/
.endif
.if ${OPSYS} == DragonFly
	(cd ${DESTDIR}${BASE}/usr/lib && \
		ln -s libsbuf.so.3 libsbuf.so && \
		ln -s libprop.so.3 libprop.so && \
		ln -s libdevattr.so.3 libdevattr.so && \
		ln -s libdevstat.so.3 libdevstat.so && \
		ln -s libdevinfo.so.3 libdevinfo.so && \
		ln -s libdevmapper.so.0 libdevmapper.so && \
		ln -s libcam.so.3 libcam.so)
	(cd ${DESTDIR}${BASE}/usr/include && \
		ln -s /usr/include/dev/misc/evdev compat/linux && \
		ln -s vfs fs && \
		ln -s vfs ufs && \
		ln -s vfs/nfs nfs && \
		ln -s vfs/ntfs ntfs && \
		ln -s vfs/isofs isofs && \
		ln -s vfs/msdos msdosfs && \
		ln -s netproto/smb netsmb && \
		ln -s bus/pccard pccard && \
		ln -s bus/cam cam)
.  for item in gcc80/libstdc++.so.9
	${BSD_INSTALL_LIB} ../${OPSYS:tl}/usr/lib/${item} ${DESTDIR}${BASE}/usr/lib/${item}
.  endfor
.  for item in gcc80/libgcc_pic.a
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/lib/${item} ${DESTDIR}${BASE}/usr/lib/${item}
.  endfor
.endif
.if ${OPSYS} == Linux
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
	cp ${CPA} ../ravensys-root_14/usr/include/i386-linux-gnu ${DESTDIR}${BASE}/usr/include/
	# locales
	mkdir -p ${DESTDIR}${BASE}/usr/lib/locale
	mkdir -p ${DESTDIR}${BASE}/usr/share/i18n/charmaps
	mkdir -p ${DESTDIR}${BASE}/usr/share/i18n/locales
	cp ${CPA} ../linux/usr/share/i18n/charmaps/UTF-8.gz ${DESTDIR}${BASE}/usr/share/i18n/charmaps/
	cp ${CPA} ../linux/usr/lib/locale/C.UTF-8 ${DESTDIR}${BASE}/usr/lib/locale/
.  for locale in C POSIX en_US en_GB iso14651_t1 iso14651_t1_common i18n translit_*
	cp ${CPA} ../linux/usr/share/i18n/locales/${locale} ${DESTDIR}${BASE}/usr/share/i18n/locales/
.  endfor
	env I18NPATH=${DESTDIR}${BASE}/usr/share/i18n ../linux/usr/bin/localedef --prefix=${DESTDIR}${BASE} -f UTF-8 -i en_US en_US.UTF-8
	# from bash package
	cp ${CPA} ${LOCALBASE}/bin/bash ${DESTDIR}${BASE}/bin/
.endif
.if ${OPSYS} == Linux || ${OPSYS} == SunOS || ${OPSYS} == Darwin
	# use coreutils that FreeBSD and DragonFly passed on (/bin)
.  for item in [ chmod cp date echo expr kill link ln ls mkdir mv pwd \
	realpath rm rmdir sleep test unlink
	cp ${CPA} ${LOCALBASE}/bin/g${item} ${DESTDIR}${BASE}/bin/${item}
.  endfor
	# use coreutils that FreeBSD and DragonFly passed on (/usr/bin)
.  for item in basename chgrp chown comm cut dirname env false head id \
	join mkfifo mktemp printenv printf readlink tail tee touch \
	tee tr true tsort uniq whoami
	cp ${CPA} ${LOCALBASE}/bin/g${item} ${DESTDIR}${BASE}/usr/bin/${item}
.  endfor
.  if ${OPSYS} == Linux || ${OPSYS} == SunOS
.    for item in stat
	cp ${CPA} ${LOCALBASE}/bin/g${item} ${DESTDIR}${BASE}/usr/bin/${item}
.    endfor
.  endif
.endif

	# for convenience from listing hundreds of files, copy all from specific directories
.  for hdr in ${headers_${OPSYS}_dirs}
	cp ${CPA} ../${OPSYS:tl}/usr/include/${hdr} ${DESTDIR}${BASE}/usr/include/
.  endfor
.for item in ${pcfiles_${OPSYS}}
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/libdata/pkgconfig/${item} \
		${DESTDIR}${BASE}/usr/lib/pkgconfig/
.endfor
.for item in md5 sha256 
	cp ${CPA} ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/bin/
.endfor
	cp ${CPA} ${LOCALBASE}/bin/gcat ${DESTDIR}${BASE}/bin/cat
.for item in m4 bzip2 bunzip2 bzcat bzgrep bzegrep bzfgrep lockf \
	grep file flex flex++ gzip gunzip zcat zcmp zdiff zegrep \
	zfgrep zgrep lzcat lzcmp lzdiff lzegrep lzfgrep lzgrep lzma \
	unlzma unxz xz xzcat xzcmp xzdiff xzegrep xzfgrep xzgrep yacc \
	unzip less mtree bsdcat dupe genpatch portfix patch fetch
	cp ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/usr/bin/
.endfor
.  for item in sed find xargs cmp diff diff3 sdiff \
	install wc sort od mknod seq
	cp ${CPA} ${LOCALBASE}/bin/g${item} ${DESTDIR}${BASE}/usr/bin/${item}
.  endfor
.for item in ${headers_${OPSYS}}
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/include/${item} ${DESTDIR}${BASE}/usr/include/${item}
.endfor
.if ${OPSYS} == DragonFly
	cp ${LOCALBASE}/lib/libdl.a ${DESTDIR}${BASE}/usr/lib/
	rm ${DESTDIR}${BASE}/usr/include/net/zlib.h
	rm -rf ${DESTDIR}${BASE}/usr/include/net/ipfw*
	rm -rf ${DESTDIR}${BASE}/usr/include/net/pf
	rmdir  ${DESTDIR}${BASE}/usr/include/vfs/mfs
	# fix timespec* for c++17
	sed -i '/if __ISO_C_VISIBLE >= 2011$$/ s#$$# || (defined(__cplusplus) \&\& __cplusplus >= 201703) &#' \
		${DESTDIR}${BASE}/usr/include/time.h
.endif
.if ${OPSYS} == FreeBSD
	cp ${LOCALBASE}/lib/libdl.a ${DESTDIR}${BASE}/usr/lib/
	rmdir ${DESTDIR}${BASE}/usr/include/dev/nand
	rmdir ${DESTDIR}${BASE}/usr/include/dev/powermac_nvram
.endif
.for item in nawk/awk objdump/objdump-sysroot less/more bmake/make \
	bsdcpio/cpio bsdtar/tar ravensys-uname/uname nvi/vi
	cp ${LOCALBASE}/bin/${item:H} ${DESTDIR}${BASE}/usr/bin/${item:T}
.endfor
	ln -s m4 ${DESTDIR}${BASE}/usr/bin/gm4
	cp ${LOCALBASE}/share/misc/terminfo.db.default ${DESTDIR}${BASE}/usr/share/terminfo.db
	cp ${LOCALBASE}/sbin/ravensw ${DESTDIR}${BASE}/usr/bin/
	cp ${LOCALBASE}/sbin/makewhatis ${DESTDIR}${BASE}/usr/bin/
	cp ${LOCALBASE}/share/file/magic.mgc ${DESTDIR}${BASE}/usr/share/file/
	sed -e "s|${LOCALBASE}|/usr|g" ${LOCALBASE}/bin/egrep \
		> ${DESTDIR}${BASE}/usr/bin/egrep
	sed -e "s|${LOCALBASE}|/usr|g" ${LOCALBASE}/bin/fgrep \
		> ${DESTDIR}${BASE}/usr/bin/fgrep
	chmod 755 ${DESTDIR}${BASE}/usr/bin/egrep \
		${DESTDIR}${BASE}/usr/bin/fgrep
.if ${OPSYS} == Darwin
	rm ${DESTDIR}${BASE}/usr/bin/objdump-sysroot
.endif
.if ${OPSYS} == DragonFly || ${OPSYS} == FreeBSD
.  for LC in COLLATE CTYPE MESSAGES MONETARY NUMERIC TIME
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/share/locale/en_US.UTF-8/LC_${LC} \
		${DESTDIR}${BASE}/usr/share/locale/en_US.UTF-8/
.  endfor
.endif

extra-includes:
.for item in ${headers_${OPSYS}}
	@fgrep "#include" /usr/include/${item} || true
.endfor
