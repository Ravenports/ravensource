# Create identical sysroot regardless of host system

all: sysroot

Libexec_DragonFly=	/libexec/ld-elf.so.2
Libexec_FreeBSD=	/libexec/ld-elf.so.1
Libexec_Linux=		# empty

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
		/usr/share/initrd/bin/ls \
		/bin/mkdir \
		/bin/mv \
		/bin/pax \
		/bin/pwd \
		/bin/realpath \
		/bin/rm \
		/bin/rmdir \
		/usr/share/initrd/bin/sh \
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
		/bin/unlink

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
# /usr/bin/patch  (devel/patch)
# /usr/bin/sed    (textproc/gsed)
# /usr/bin/tar    (archivers/libarchive)
# /usr/bin/xargs  (misc/findutils)
# /usr/bin/yacc   (devel/byacc)
# /usr/bin/less*  (sysutils/less)
# /usr/bin/mtree  (sysutils/mtree)
# /usr/bin/sort   (sysutils/coreutils)
# /usr/bin/pkg-static (ports-mgmt/pkg)
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
		/usr/bin/install \
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
		/usr/bin/wc \
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
			/usr/lib/libutil.a \
			/usr/lib/libcrypt.a \
			/usr/lib/libpthread.a
static_lib_FreeBSD=	${static_lib_generic} \
			/usr/lib/libkvm.a \
			/usr/lib/libusb.a \
			/usr/lib/libusbhid.a
static_lib_DragonFly=	${static_lib_generic} \
			/usr/lib/libkvm.a \
			/usr/lib/libusb.a \
			/usr/lib/libusbhid.a \
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
			/usr/lib/libpthread.so
dynamic_lib_FreeBSD=	${dynamic_generic} \
			/usr/lib/${libusb} \
			/usr/lib/${libusbhid}
dynamic_lib_DragonFly=	${dynamic_generic} \
			/usr/lib/libpthread.so.0 \
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
Linux_extra_libs1=	# libaudit.so.1.0.0/libaudit.so.1 \
			# end (/lib)
Linux_extra_libs2=	# libustr-1.0.so.1.0.4/libustr-1.0.so.1 \
			# end (/usr/lib)
Linux_single_libs1=	# libsepol.so.1 \
			# libselinux.so.1 \
			# end (/lib)
Linux_single_libs2=	# libsemanage.so.1 \
			# end (/usr/lib)
posix_headers=		aio.h \
			arpa/inet.h \
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
			net/if.h \
			netdb.h \
			netinet/in.h \
			netinet/tcp.h \
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
			sys/ipc.h \
			sys/mman.h \
			sys/msg.h \
			sys/resource.h \
			sys/select.h \
			sys/sem.h \
			sys/shm.h \
			sys/socket.h \
			sys/stat.h \
			sys/statvfs.h \
			sys/time.h \
			sys/times.h \
			sys/types.h \
			sys/uio.h \
			sys/un.h \
			sys/utsname.h \
			sys/wait.h \
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

headers_FreeBSD=	${posix_headers:Nstropts.h:Ntrace.h} \
			libutil.h \
			pthread_np.h \
			usb.h \
			usbhid.h \
			# end
headers_DragonFly=	${posix_headers:Nstropts.h:Ntrace.h} \
			libutil.h \
			pthread_np.h \
			usb.h \
			usbhid.h \
			ar.h \
			arpa/ftp.h \
			arpa/nameser.h \
			arpa/nameser_compat.h \
			arpa/telnet.h \
			arpa/tftp.h \
			db.h \
			elf.h \
			err.h \
			floatingpoint.h \
			fts.h \
			getopt.h \
			ieeefp.h \
			ifaddrs.h \
			kvm.h \
			link.h \
			memory.h \
			nlist.h \
			osreldate.h \
			paths.h \
			resolv.h \
			util.h \
			vis.h \
			libusb.h \
			net/if_dl.h \
			net/if_var.h \
			netconfig.h \
			netinet/in_systm.h \
			netinet/ip.h \
			netinet6/in6.h \
			readpassphrase.h \
			rpc/auth.h \
			rpc/auth_des.h \
			rpc/auth_kerb.h \
			rpc/auth_unix.h \
			rpc/clnt.h \
			rpc/clnt_soc.h \
			rpc/clnt_stat.h \
			rpc/des.h \
			rpc/des_crypt.h \
			rpc/key_prot.h \
			rpc/nettype.h \
			rpc/pmap_clnt.h \
			rpc/pmap_prot.h \
			rpc/pmap_rmt.h \
			rpc/raw.h \
			rpc/rpc.h \
			rpc/rpc_com.h \
			rpc/rpc_msg.h \
			rpc/rpcb_clnt.h \
			rpc/rpcb_prot.h \
			rpc/rpcb_prot.x \
			rpc/rpcent.h \
			rpc/svc.h \
			rpc/svc_auth.h \
			rpc/svc_dg.h \
			rpc/svc_soc.h \
			rpc/types.h \
			rpc/xdr.h \
			rpcsvc/bootparam_prot.h \
			rpcsvc/bootparam_prot.x \
			rpcsvc/crypt.h \
			rpcsvc/crypt.x \
			rpcsvc/key_prot.h \
			rpcsvc/key_prot.x \
			rpcsvc/klm_prot.h \
			rpcsvc/klm_prot.x \
			rpcsvc/mount.h \
			rpcsvc/mount.x \
			rpcsvc/nfs_prot.h \
			rpcsvc/nfs_prot.x \
			rpcsvc/nis.h \
			rpcsvc/nis.x \
			rpcsvc/nis_cache.h \
			rpcsvc/nis_cache.x \
			rpcsvc/nis_callback.h \
			rpcsvc/nis_callback.x \
			rpcsvc/nis_db.h \
			rpcsvc/nis_object.x \
			rpcsvc/nis_tags.h \
			rpcsvc/nislib.h \
			rpcsvc/nlm_prot.h \
			rpcsvc/nlm_prot.x \
			rpcsvc/rex.h \
			rpcsvc/rex.x \
			rpcsvc/rnusers.h \
			rpcsvc/rnusers.x \
			rpcsvc/rquota.h \
			rpcsvc/rquota.x \
			rpcsvc/rstat.h \
			rpcsvc/rstat.x \
			rpcsvc/rwall.h \
			rpcsvc/rwall.x \
			rpcsvc/sm_inter.h \
			rpcsvc/sm_inter.x \
			rpcsvc/spray.h \
			rpcsvc/spray.x \
			rpcsvc/yp.h \
			rpcsvc/yp.x \
			rpcsvc/yp_prot.h \
			rpcsvc/ypclnt.h \
			rpcsvc/yppasswd.h \
			rpcsvc/yppasswd.x \
			rpcsvc/ypupdate_prot.h \
			rpcsvc/ypupdate_prot.x \
			rpcsvc/ypxfrd.h \
			rpcsvc/ypxfrd.x \
			runetype.h \
			stringlist.h \
			sysexits.h \
			ttyent.h \
			ucontext.h \
			uuid.h \
			vm/pmap.h \
			vm/swap_pager.h \
			vm/vm.h \
			vm/vm_extern.h \
			vm/vm_kern.h \
			vm/vm_map.h \
			vm/vm_object.h \
			vm/vm_page.h \
			vm/vm_page2.h \
			vm/vm_pageout.h \
			vm/vm_pager.h \
			vm/vm_param.h \
			vm/vm_zone.h \
			vm/vnode_pager.h \
			xlocale.h \
			xlocale/_ctype.h \
			xlocale/_inttypes.h \
			xlocale/_langinfo.h \
			xlocale/_locale.h \
			xlocale/_monetary.h \
			xlocale/_stdlib.h \
			xlocale/_stdio.h \
			xlocale/_string.h \
			xlocale/_strings.h \
			xlocale/_time.h \
			xlocale/_wchar.h \
			xlocale/_uchar.h \
			# end

headers_Linux_dirs=	arpa \
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
pcfiles_FreeBSD=	# end
pcfiles_DragonFly=	libusb-0.1.pc \
			libusb-2.0.pc \
			libusb-1.0.pc \
			# end

sysroot:
	@echo "building not required"

install:
	${MKDIR} \
		${DESTDIR}${BASE}/bin \
		${DESTDIR}${BASE}/lib \
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
		${DESTDIR}${BASE}/usr/include/cpu \
		${DESTDIR}${BASE}/usr/include/netinet6 \
		${DESTDIR}${BASE}/usr/include/sys \
		${DESTDIR}${BASE}/usr/include/machine \
		${DESTDIR}${BASE}/usr/include/vm \
		${DESTDIR}${BASE}/usr/include/xlocale \
		# end
.endif
.if "${OPSYS}" == "FreeBSD"
	${MKDIR} \
		${DESTDIR}${BASE}/libexec \
		${DESTDIR}${BASE}/usr/include/cpu \
		${DESTDIR}${BASE}/usr/include/netinet6 \
		${DESTDIR}${BASE}/usr/include/sys \
		${DESTDIR}${BASE}/usr/include/machine \
		${DESTDIR}${BASE}/usr/include/vm \
		${DESTDIR}${BASE}/usr/include/xlocale \
		# end
.endif
.if "${OPSYS}" == "Linux"
	${MKDIR} \
		${DESTDIR}${BASE}/lib64 \
		${DESTDIR}${BASE}/lib/x86_64-linux-gnu \
		${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu \
		# end
.endif

.for item in ${Bin_${OPSYS}}
	${BSD_INSTALL_PROGRAM} ../${OPSYS:tl}${item} ${DESTDIR}${BASE}/bin/
.endfor
.for item in ${Usr_Bin_${OPSYS}}
	${BSD_INSTALL_PROGRAM} ../${OPSYS:tl}${item} ${DESTDIR}${BASE}/usr/bin/
.endfor
.for item in ${Usr_Sbin_${OPSYS}}
	${BSD_INSTALL_PROGRAM} ../${OPSYS:tl}${item} ${DESTDIR}${BASE}/usr/sbin/
.endfor
.for item in ${Libexec_${OPSYS}}
	${BSD_INSTALL_PROGRAM} ../${OPSYS:tl}${item} ${DESTDIR}${BASE}/libexec/
.endfor
.for item in ${dynamic_lib_${OPSYS}}
	${BSD_INSTALL_LIB} ../${OPSYS:tl}${item} ${DESTDIR}${BASE}/usr/lib/
.endfor
.for item in ${static_lib_${OPSYS}}
	${BSD_INSTALL_DATA} ../${OPSYS:tl}${item} ${DESTDIR}${BASE}/usr/lib/
.endfor
.if ${OPSYS} == DragonFly || ${OPSYS} == FreeBSD
	(cd ${DESTDIR}${BASE}/usr/lib && \
		ln -s ${libc} libc.so && \
		ln -s ${libm} libm.so && \
		ln -s ${libkvm} libkvm.so && \
		ln -s ${libcrypt} libcrypt.so && \
		ln -s ${libutil} libutil.so && \
		ln -s ${libusb} libusb.so && \
		ln -s ${libusbhid} libusbhid.so)
.endif
.if ${OPSYS} == Linux
.  for item in ${Linux_static_libs}
	${BSD_INSTALL_DATA} ../linux/usr/lib/x86_64-linux-gnu/${item} ${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu/
.  endfor
.  for item in ${Linux_shared_libs}
	cp -a ../linux/lib/x86_64-linux-gnu/${item:H} ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/
	cp -a ../linux/lib/x86_64-linux-gnu/${item:T} ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/
	cp -a ../linux/usr/lib/x86_64-linux-gnu/${item:T:R} ${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu/
.  endfor
.  for item in ${Linux_extra_libs1} ${Linux_RTLD}
	cp -a ../linux/lib/x86_64-linux-gnu/${item:H} ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/
	cp -a ../linux/lib/x86_64-linux-gnu/${item:T} ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/
.  endfor
.  for item in ${Linux_extra_libs2}
	cp -a ../linux/usr/lib/x86_64-linux-gnu/${item:H} ${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu/
	cp -a ../linux/usr/lib/x86_64-linux-gnu/${item:T} ${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu/
.  endfor
.  for item in ${Linux_single_libs1}
	cp -a ../linux/lib/x86_64-linux-gnu/${item} ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/
.  endfor
.  for item in ${Linux_single_libs2}
	cp -a ../linux/usr/lib/x86_64-linux-gnu/${item} ${DESTDIR}${BASE}/usr/lib/x86_64-linux-gnu/
.  endfor
	ln -s /lib/x86_64-linux-gnu/${Linux_RTLD:H} ${DESTDIR}${BASE}/lib64/${Linux_RTLD:T}
	# certain shared libraries must be executable
	chmod 755 ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/${Linux_RTLD:H}
	chmod 755 ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/${Linux_C_lib:H}
	chmod 755 ${DESTDIR}${BASE}/lib/x86_64-linux-gnu/${Linux_thread_lib:H}
	# use coreutils that FreeBSD and DragonFly passed on (/bin)
.  for item in [ chmod cp date echo expr kill link ln ls mkdir mv pwd realpath rm rmdir sleep test unlink
	cp -a ${LOCALBASE}/bin/g${item} ${DESTDIR}${BASE}/bin/${item}
.  endfor
	# user coreutils that FreeBSD and DragonFly passed on (/usr/bin)
.  for item in basename chgrp chown comm cut dirname env false head id install join mkfifo mktemp \
	printenv printf readlink stat tail tee touch tee tr true tsort uniq wc whoami
	cp -a ${LOCALBASE}/bin/g${item} ${DESTDIR}${BASE}/usr/bin/${item}
.  endfor
	# From linux-only shadow package
.  for sbinitem in useradd usermod groupadd
	cp -a ${LOCALBASE}/sbin/${sbinitem} ${DESTDIR}${BASE}/usr/bin/
.  endfor
	# ldd and which are scripts, can't be stripped
	${BSD_INSTALL_SCRIPT} ../linux/usr/bin/ldd ${DESTDIR}${BASE}/usr/bin/
	${BSD_INSTALL_SCRIPT} ../linux/bin/which ${DESTDIR}${BASE}/usr/bin/
	# convert ldd from bash to dash
	sed -i'' -e "s|/bin/bash|/bin/dash|" ${DESTDIR}${BASE}/usr/bin/ldd
	# for convenience from listing hundreds of files, copy all from specific directories
.  for hdr in ${headers_Linux_dirs}
	cp -a ../linux/usr/include/${hdr} ${DESTDIR}${BASE}/usr/include/
.  endfor
.endif
.for item in ${pcfiles_${OPSYS}}
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/libdata/pkgconfig/${item} \
		${DESTDIR}${BASE}/usr/lib/pkgconfig/
.endfor
	${BSD_INSTALL_SCRIPT} ../${OPSYS:tl}/usr/bin/lorder ${DESTDIR}${BASE}/usr/bin/
.for item in md5 sha256 
	cp -a ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/bin/
.endfor
	cp -a ${LOCALBASE}/bin/gcat ${DESTDIR}${BASE}/bin/cat
.for item in bzip2 bunzip2 bzcat bzgrep bzegrep bzfgrep \
	grep fetch file flex flex++ gzip gunzip zcat zcmp zdiff zegrep \
	zfgrep zgrep lzcat lzcmp lzdiff lzegrep lzfgrep lzgrep lzma \
	unlzma unxz xz xzcat xzcmp xzdiff xzegrep xzfgrep xzgrep yacc \
	unzip less mtree bsdcat makewhatis dupe genpatch portfix
	cp ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/usr/bin/
.endfor
.for item in ${headers_${OPSYS}}
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/include/${item} ${DESTDIR}${BASE}/usr/include/${item}
.endfor
.if ${OPSYS} == DragonFly || ${OPSYS} == FreeBSD
	cp ${LOCALBASE}/lib/libdl.a ${DESTDIR}${BASE}/usr/lib/
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/include/cpu/*.h ${DESTDIR}${BASE}/usr/include/cpu/
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/include/machine/*.h ${DESTDIR}${BASE}/usr/include/machine/
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/include/sys/*.h ${DESTDIR}${BASE}/usr/include/sys/
.endif
.for item in gsort/sort nawk/awk objdump/objdump-sysroot less/more \
	bmake/make bsdcpio/cpio bsdtar/tar gcmp/cmp gdiff/diff \
	gdiff3/diff3 gsdiff/sdiff gfind/find gxargs/xargs gm4/m4 \
	gpatch/patch gsed/sed ravensys-uname/uname nvi/vi
	cp ${LOCALBASE}/bin/${item:H} ${DESTDIR}${BASE}/usr/bin/${item:T}
.endfor
	cp ${LOCALBASE}/share/misc/terminfo.db.default ${DESTDIR}${BASE}/usr/share/terminfo.db
	cp ${LOCALBASE}/sbin/pkg-static ${DESTDIR}${BASE}/usr/bin/
	cp ${LOCALBASE}/share/file/magic.mgc ${DESTDIR}${BASE}/usr/share/file/
	sed -e "s|${LOCALBASE}|/usr|g" ${LOCALBASE}/bin/egrep \
		> ${DESTDIR}${BASE}/usr/bin/egrep
	sed -e "s|${LOCALBASE}|/usr|g" ${LOCALBASE}/bin/fgrep \
		> ${DESTDIR}${BASE}/usr/bin/fgrep
	chmod 755 ${DESTDIR}${BASE}/usr/bin/egrep \
		${DESTDIR}${BASE}/usr/bin/fgrep

extra-includes:
.for item in ${headers_${OPSYS}}
	@fgrep "#include" /usr/include/${item} || true
.endfor
