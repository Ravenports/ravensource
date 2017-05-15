# Create identical sysroot regardless of host system

all: sysroot

Libexec_DragonFly=	/libexec/ld-elf.so.2
Libexec_FreeBSD=	/libexec/ld-elf.so.1

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

Usr_Sbin_DragonFly= \
		/usr/sbin/pw \
		/usr/sbin/pwd_mkdb
		# end

Usr_Bin_FreeBSD=	${Usr_Bin_DragonFly}
Usr_Sbin_FreeBSD=	${Usr_Sbin_DragonFly}

static_lib_generic=	/usr/lib/libc.a \
			/usr/lib/libm.a \
			/usr/lib/libutil.a \
			/usr/lib/libcrypt.a \
			/usr/lib/libkvm.a \
			/usr/lib/libpthread.a
static_lib_FreeBSD=	${static_lib_generic} \
			/usr/lib/libusb.a \
			/usr/lib/libusbhid.a
static_lib_DragonFly=	${static_lib_generic} \
			/usr/lib/libusb.a \
			/usr/lib/libusbhid.a \
			/usr/lib/crt1.o \
			/usr/lib/crti.o \
			/usr/lib/crtn.o
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
			link.h \
			memory.h \
			osreldate.h \
			paths.h \
			resolv.h \
			util.h \
			vis.h \
			libusb.h \
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

pcfiles_FreeBSD=	\
			# end
pcfiles_DragonFly=	libusb-0.1.pc \
			libusb-2.0.pc \
			libusb-1.0.pc \
			# end

sysroot:
	@echo "building not required"

install:
	${MKDIR} ${DESTDIR}${BASE}/bin \
		${DESTDIR}${BASE}/libexec \
		${DESTDIR}${BASE}/usr/bin \
		${DESTDIR}${BASE}/usr/include \
		${DESTDIR}${BASE}/usr/lib/pkgconfig \
		${DESTDIR}${BASE}/usr/share/file \
		${DESTDIR}${BASE}/usr/local \
		${DESTDIR}${BASE}/usr/include/arpa \
		${DESTDIR}${BASE}/usr/include/cpu \
		${DESTDIR}${BASE}/usr/include/rpc \
		${DESTDIR}${BASE}/usr/include/rpcsvc \
		${DESTDIR}${BASE}/usr/include/sys \
		${DESTDIR}${BASE}/usr/include/net \
		${DESTDIR}${BASE}/usr/include/netinet \
		${DESTDIR}${BASE}/usr/include/netinet6 \
		${DESTDIR}${BASE}/usr/include/machine \
		${DESTDIR}${BASE}/usr/include/xlocale \
		${DESTDIR}${BASE}/usr/sbin \
		# end
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
	@echo "dynlib item is ${item}"
	${BSD_INSTALL_LIB} ../${OPSYS:tl}${item} ${DESTDIR}${BASE}/usr/lib/
.endfor
.for item in ${static_lib_${OPSYS}}
	${BSD_INSTALL_DATA} ../${OPSYS:tl}${item} ${DESTDIR}${BASE}/usr/lib/
.endfor
	(cd ${DESTDIR}${BASE}/usr/lib && \
		ln -s ${libc} libc.so && \
		ln -s ${libm} libm.so && \
		ln -s ${libkvm} libkvm.so && \
		ln -s ${libcrypt} libcrypt.so && \
		ln -s ${libutil} libutil.so)
.if ${OPSYS} == DragonFly || ${OPSYS} == FreeBSD
	(cd ${DESTDIR}${BASE}/usr/lib && \
		ln -s ${libusb} libusb.so && \
		ln -s ${libusbhid} libusbhid.so)
.endif
.for item in ${pcfiles_${OPSYS}}
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/libdata/pkgconfig/${item} \
		${DESTDIR}${BASE}/usr/lib/pkgconfig/
.endfor
	${BSD_INSTALL_SCRIPT} ../${OPSYS:tl}/usr/bin/lorder \
		${DESTDIR}${BASE}/usr/bin/
.for item in md5 sha256 
	cp ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/bin/
.endfor
	cp ${LOCALBASE}/bin/gcat ${DESTDIR}${BASE}/bin/cat
.for item in bzip2 bunzip2 bzcat bzgrep bzegrep bzfgrep \
	grep fetch file flex flex++ gzip gunzip zcat zcmp zdiff zegrep \
	zfgrep zgrep lzcat lzcmp lzdiff lzegrep lzfgrep lzgrep lzma \
	unlzma unxz xz xzcat xzcmp xzdiff xzegrep xzfgrep xzgrep yacc \
	unzip less mtree bsdcat makewhatis dupe genpatch portfix
	cp ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/usr/bin/
.endfor
	cp ${LOCALBASE}/lib/libdl.a ${DESTDIR}${BASE}/usr/lib/
.for item in ${headers_${OPSYS}}
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/include/${item} ${DESTDIR}${BASE}/usr/include/${item}
.endfor
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/include/cpu/*.h ${DESTDIR}${BASE}/usr/include/cpu/
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/include/machine/*.h ${DESTDIR}${BASE}/usr/include/machine/
	${BSD_INSTALL_DATA} ../${OPSYS:tl}/usr/include/sys/*.h ${DESTDIR}${BASE}/usr/include/sys/
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
