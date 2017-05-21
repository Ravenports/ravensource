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
		/bin/bash \
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

Usr_Sbin_DragonFly= \
		/usr/sbin/pw \
		/usr/sbin/pwd_mkdb
		# end

Usr_Sbin_FreeBSD=	${Usr_Sbin_DragonFly}
Usr_Sbin_Linux=		# empty

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
static_lib_Linux=	# Linux doesn't use /usr/lib, needs special list
			# /usr/lib/x86_64-linux-gnu => /usr/lib64
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
Linux_RTLD=		ld-linux-x86-64.so.2/ld-2.23.so
			# /lib/x86_64-linux-gnu => /lib64
			# real file / soname (also symlink)
			# use to create /usr/lib64/<lib>.so => /lib64/soname
Linux_shared_libs=	libc-2.23.so/libc.so.6 \
			libm-2.23.so/libm.so.6 \
			libutil-2.23.so/libutil.so.1 \
			libcrypt-2.23.so/libcrypt.so.1 \
			libpthread-2.23.so/libpthread.so.0 \
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

headers_Linux=		aio.h \
			aliases.h \
			alloca.h \
			ar.h \
			argp.h \
			argz.h \
			arpa/ftp.h \
			arpa/inet.h \
			arpa/nameser.h \
			arpa/nameser_compat.h \
			arpa/telnet.h \
			arpa/tftp.h \
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
			net/ethernet.h \
			net/if.h \
			net/if_arp.h \
			net/if_packet.h \
			net/if_ppp.h \
			net/if_shaper.h \
			net/if_slip.h \
			net/ppp-comp.h \
			net/ppp_defs.h \
			net/route.h \
			netash/ash.h \
			netatalk/at.h \
			netax25/ax25.h \
			netdb.h \
			neteconet/ec.h \
			netinet/ether.h \
			netinet/icmp6.h \
			netinet/if_ether.h \
			netinet/if_fddi.h \
			netinet/if_tr.h \
			netinet/igmp.h \
			netinet/in.h \
			netinet/in_systm.h \
			netinet/ip.h \
			netinet/ip6.h \
			netinet/ip_icmp.h \
			netinet/tcp.h \
			netinet/udp.h \
			netipx/ipx.h \
			netiucv/iucv.h \
			netpacket/packet.h \
			netrom/netrom.h \
			netrose/rose.h \
			nfs/nfs.h \
			nl_types.h \
			nss.h \
			obstack.h \
			paths.h \
			poll.h \
			printf.h \
			protocols/routed.h \
			protocols/rwhod.h \
			protocols/talkd.h \
			protocols/timed.h \
			pthread.h \
			pty.h \
			pwd.h \
			re_comp.h \
			regex.h \
			regexp.h \
			resolv.h \
			rpc/auth.h \
			rpc/auth_des.h \
			rpc/auth_unix.h \
			rpc/clnt.h \
			rpc/des_crypt.h \
			rpc/key_prot.h \
			rpc/netdb.h \
			rpc/pmap_clnt.h \
			rpc/pmap_prot.h \
			rpc/pmap_rmt.h \
			rpc/rpc.h \
			rpc/rpc_des.h \
			rpc/rpc_msg.h \
			rpc/svc.h \
			rpc/svc_auth.h \
			rpc/types.h \
			rpc/xdr.h \
			rpcsvc/bootparam.h \
			rpcsvc/bootparam_prot.h \
			rpcsvc/bootparam_prot.x \
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
			rpcsvc/nis_callback.h \
			rpcsvc/nis_callback.x \
			rpcsvc/nis_object.x \
			rpcsvc/nis_tags.h \
			rpcsvc/nislib.h \
			rpcsvc/nlm_prot.h \
			rpcsvc/nlm_prot.x \
			rpcsvc/rex.h \
			rpcsvc/rex.x \
			rpcsvc/rquota.h \
			rpcsvc/rquota.x \
			rpcsvc/rstat.h \
			rpcsvc/rstat.x \
			rpcsvc/rusers.h \
			rpcsvc/rusers.x \
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
			rpcsvc/ypupd.h \
			sched.h \
			scsi/scsi.h \
			scsi/scsi_ioctl.h \
			scsi/sg.h \
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
			x86_64-linux-gnu/a.out.h \
			x86_64-linux-gnu/bits/a.out.h \
			x86_64-linux-gnu/bits/auxv.h \
			x86_64-linux-gnu/bits/byteswap-16.h \
			x86_64-linux-gnu/bits/byteswap.h \
			x86_64-linux-gnu/bits/cmathcalls.h \
			x86_64-linux-gnu/bits/confname.h \
			x86_64-linux-gnu/bits/dirent.h \
			x86_64-linux-gnu/bits/dlfcn.h \
			x86_64-linux-gnu/bits/elfclass.h \
			x86_64-linux-gnu/bits/endian.h \
			x86_64-linux-gnu/bits/environments.h \
			x86_64-linux-gnu/bits/epoll.h \
			x86_64-linux-gnu/bits/errno.h \
			x86_64-linux-gnu/bits/error.h \
			x86_64-linux-gnu/bits/eventfd.h \
			x86_64-linux-gnu/bits/fcntl-linux.h \
			x86_64-linux-gnu/bits/fcntl.h \
			x86_64-linux-gnu/bits/fcntl2.h \
			x86_64-linux-gnu/bits/fenv.h \
			x86_64-linux-gnu/bits/fenvinline.h \
			x86_64-linux-gnu/bits/huge_val.h \
			x86_64-linux-gnu/bits/huge_valf.h \
			x86_64-linux-gnu/bits/huge_vall.h \
			x86_64-linux-gnu/bits/hwcap.h \
			x86_64-linux-gnu/bits/in.h \
			x86_64-linux-gnu/bits/inf.h \
			x86_64-linux-gnu/bits/initspin.h \
			x86_64-linux-gnu/bits/inotify.h \
			x86_64-linux-gnu/bits/ioctl-types.h \
			x86_64-linux-gnu/bits/ioctls.h \
			x86_64-linux-gnu/bits/ipc.h \
			x86_64-linux-gnu/bits/ipctypes.h \
			x86_64-linux-gnu/bits/libio-ldbl.h \
			x86_64-linux-gnu/bits/libm-simd-decl-stubs.h \
			x86_64-linux-gnu/bits/link.h \
			x86_64-linux-gnu/bits/local_lim.h \
			x86_64-linux-gnu/bits/locale.h \
			x86_64-linux-gnu/bits/math-finite.h \
			x86_64-linux-gnu/bits/math-vector.h \
			x86_64-linux-gnu/bits/mathcalls.h \
			x86_64-linux-gnu/bits/mathdef.h \
			x86_64-linux-gnu/bits/mathinline.h \
			x86_64-linux-gnu/bits/mman-linux.h \
			x86_64-linux-gnu/bits/mman.h \
			x86_64-linux-gnu/bits/monetary-ldbl.h \
			x86_64-linux-gnu/bits/mqueue.h \
			x86_64-linux-gnu/bits/mqueue2.h \
			x86_64-linux-gnu/bits/msq.h \
			x86_64-linux-gnu/bits/nan.h \
			x86_64-linux-gnu/bits/netdb.h \
			x86_64-linux-gnu/bits/param.h \
			x86_64-linux-gnu/bits/poll.h \
			x86_64-linux-gnu/bits/poll2.h \
			x86_64-linux-gnu/bits/posix1_lim.h \
			x86_64-linux-gnu/bits/posix2_lim.h \
			x86_64-linux-gnu/bits/posix_opt.h \
			x86_64-linux-gnu/bits/printf-ldbl.h \
			x86_64-linux-gnu/bits/pthreadtypes.h \
			x86_64-linux-gnu/bits/resource.h \
			x86_64-linux-gnu/bits/sched.h \
			x86_64-linux-gnu/bits/select.h \
			x86_64-linux-gnu/bits/select2.h \
			x86_64-linux-gnu/bits/sem.h \
			x86_64-linux-gnu/bits/semaphore.h \
			x86_64-linux-gnu/bits/setjmp.h \
			x86_64-linux-gnu/bits/setjmp2.h \
			x86_64-linux-gnu/bits/shm.h \
			x86_64-linux-gnu/bits/sigaction.h \
			x86_64-linux-gnu/bits/sigcontext.h \
			x86_64-linux-gnu/bits/siginfo.h \
			x86_64-linux-gnu/bits/signalfd.h \
			x86_64-linux-gnu/bits/signum.h \
			x86_64-linux-gnu/bits/sigset.h \
			x86_64-linux-gnu/bits/sigstack.h \
			x86_64-linux-gnu/bits/sigthread.h \
			x86_64-linux-gnu/bits/sockaddr.h \
			x86_64-linux-gnu/bits/socket.h \
			x86_64-linux-gnu/bits/socket2.h \
			x86_64-linux-gnu/bits/socket_type.h \
			x86_64-linux-gnu/bits/stab.def \
			x86_64-linux-gnu/bits/stat.h \
			x86_64-linux-gnu/bits/statfs.h \
			x86_64-linux-gnu/bits/statvfs.h \
			x86_64-linux-gnu/bits/stdio-ldbl.h \
			x86_64-linux-gnu/bits/stdio.h \
			x86_64-linux-gnu/bits/stdio2.h \
			x86_64-linux-gnu/bits/stdio_lim.h \
			x86_64-linux-gnu/bits/stdlib-bsearch.h \
			x86_64-linux-gnu/bits/stdlib-float.h \
			x86_64-linux-gnu/bits/stdlib-ldbl.h \
			x86_64-linux-gnu/bits/stdlib.h \
			x86_64-linux-gnu/bits/string.h \
			x86_64-linux-gnu/bits/string2.h \
			x86_64-linux-gnu/bits/string3.h \
			x86_64-linux-gnu/bits/stropts.h \
			x86_64-linux-gnu/bits/sys_errlist.h \
			x86_64-linux-gnu/bits/syscall.h \
			x86_64-linux-gnu/bits/sysctl.h \
			x86_64-linux-gnu/bits/syslog-ldbl.h \
			x86_64-linux-gnu/bits/syslog-path.h \
			x86_64-linux-gnu/bits/syslog.h \
			x86_64-linux-gnu/bits/termios.h \
			x86_64-linux-gnu/bits/time.h \
			x86_64-linux-gnu/bits/timerfd.h \
			x86_64-linux-gnu/bits/timex.h \
			x86_64-linux-gnu/bits/types.h \
			x86_64-linux-gnu/bits/typesizes.h \
			x86_64-linux-gnu/bits/uio.h \
			x86_64-linux-gnu/bits/unistd.h \
			x86_64-linux-gnu/bits/ustat.h \
			x86_64-linux-gnu/bits/utmp.h \
			x86_64-linux-gnu/bits/utmpx.h \
			x86_64-linux-gnu/bits/utsname.h \
			x86_64-linux-gnu/bits/waitflags.h \
			x86_64-linux-gnu/bits/waitstatus.h \
			x86_64-linux-gnu/bits/wchar-ldbl.h \
			x86_64-linux-gnu/bits/wchar.h \
			x86_64-linux-gnu/bits/wchar2.h \
			x86_64-linux-gnu/bits/wordsize.h \
			x86_64-linux-gnu/bits/xopen_lim.h \
			x86_64-linux-gnu/bits/xtitypes.h \
			x86_64-linux-gnu/fpu_control.h \
			x86_64-linux-gnu/gnu/lib-names-64.h \
			x86_64-linux-gnu/gnu/lib-names.h \
			x86_64-linux-gnu/gnu/libc-version.h \
			x86_64-linux-gnu/gnu/stubs-64.h \
			x86_64-linux-gnu/gnu/stubs.h \
			x86_64-linux-gnu/ieee754.h \
			x86_64-linux-gnu/sys/acct.h \
			x86_64-linux-gnu/sys/auxv.h \
			x86_64-linux-gnu/sys/bitypes.h \
			x86_64-linux-gnu/sys/cdefs.h \
			x86_64-linux-gnu/sys/debugreg.h \
			x86_64-linux-gnu/sys/dir.h \
			x86_64-linux-gnu/sys/elf.h \
			x86_64-linux-gnu/sys/epoll.h \
			x86_64-linux-gnu/sys/errno.h \
			x86_64-linux-gnu/sys/eventfd.h \
			x86_64-linux-gnu/sys/fanotify.h \
			x86_64-linux-gnu/sys/fcntl.h \
			x86_64-linux-gnu/sys/file.h \
			x86_64-linux-gnu/sys/fsuid.h \
			x86_64-linux-gnu/sys/gmon.h \
			x86_64-linux-gnu/sys/gmon_out.h \
			x86_64-linux-gnu/sys/inotify.h \
			x86_64-linux-gnu/sys/io.h \
			x86_64-linux-gnu/sys/ioctl.h \
			x86_64-linux-gnu/sys/ipc.h \
			x86_64-linux-gnu/sys/kd.h \
			x86_64-linux-gnu/sys/klog.h \
			x86_64-linux-gnu/sys/mman.h \
			x86_64-linux-gnu/sys/mount.h \
			x86_64-linux-gnu/sys/msg.h \
			x86_64-linux-gnu/sys/mtio.h \
			x86_64-linux-gnu/sys/param.h \
			x86_64-linux-gnu/sys/pci.h \
			x86_64-linux-gnu/sys/perm.h \
			x86_64-linux-gnu/sys/personality.h \
			x86_64-linux-gnu/sys/poll.h \
			x86_64-linux-gnu/sys/prctl.h \
			x86_64-linux-gnu/sys/procfs.h \
			x86_64-linux-gnu/sys/profil.h \
			x86_64-linux-gnu/sys/ptrace.h \
			x86_64-linux-gnu/sys/queue.h \
			x86_64-linux-gnu/sys/quota.h \
			x86_64-linux-gnu/sys/raw.h \
			x86_64-linux-gnu/sys/reboot.h \
			x86_64-linux-gnu/sys/reg.h \
			x86_64-linux-gnu/sys/resource.h \
			x86_64-linux-gnu/sys/select.h \
			x86_64-linux-gnu/sys/sem.h \
			x86_64-linux-gnu/sys/sendfile.h \
			x86_64-linux-gnu/sys/shm.h \
			x86_64-linux-gnu/sys/signal.h \
			x86_64-linux-gnu/sys/signalfd.h \
			x86_64-linux-gnu/sys/socket.h \
			x86_64-linux-gnu/sys/socketvar.h \
			x86_64-linux-gnu/sys/soundcard.h \
			x86_64-linux-gnu/sys/stat.h \
			x86_64-linux-gnu/sys/statfs.h \
			x86_64-linux-gnu/sys/statvfs.h \
			x86_64-linux-gnu/sys/stropts.h \
			x86_64-linux-gnu/sys/swap.h \
			x86_64-linux-gnu/sys/syscall.h \
			x86_64-linux-gnu/sys/sysctl.h \
			x86_64-linux-gnu/sys/sysinfo.h \
			x86_64-linux-gnu/sys/syslog.h \
			x86_64-linux-gnu/sys/sysmacros.h \
			x86_64-linux-gnu/sys/termios.h \
			x86_64-linux-gnu/sys/time.h \
			x86_64-linux-gnu/sys/timeb.h \
			x86_64-linux-gnu/sys/timerfd.h \
			x86_64-linux-gnu/sys/times.h \
			x86_64-linux-gnu/sys/timex.h \
			x86_64-linux-gnu/sys/ttychars.h \
			x86_64-linux-gnu/sys/ttydefaults.h \
			x86_64-linux-gnu/sys/types.h \
			x86_64-linux-gnu/sys/ucontext.h \
			x86_64-linux-gnu/sys/uio.h \
			x86_64-linux-gnu/sys/ultrasound.h \
			x86_64-linux-gnu/sys/un.h \
			x86_64-linux-gnu/sys/unistd.h \
			x86_64-linux-gnu/sys/user.h \
			x86_64-linux-gnu/sys/ustat.h \
			x86_64-linux-gnu/sys/utsname.h \
			x86_64-linux-gnu/sys/vfs.h \
			x86_64-linux-gnu/sys/vlimit.h \
			x86_64-linux-gnu/sys/vm86.h \
			x86_64-linux-gnu/sys/vt.h \
			x86_64-linux-gnu/sys/vtimes.h \
			x86_64-linux-gnu/sys/wait.h \
			x86_64-linux-gnu/sys/xattr.h \
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
		${DESTDIR}${BASE}/lib \
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
		${DESTDIR}${BASE}/lib \
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
		${DESTDIR}${BASE}/usr/lib64 \
		${DESTDIR}${BASE}/usr/include/netash \
		${DESTDIR}${BASE}/usr/include/netatalk \
		${DESTDIR}${BASE}/usr/include/netax25 \
		${DESTDIR}${BASE}/usr/include/neteconet \
		${DESTDIR}${BASE}/usr/include/netipx \
		${DESTDIR}${BASE}/usr/include/netiucv \
		${DESTDIR}${BASE}/usr/include/netpacket \
		${DESTDIR}${BASE}/usr/include/netrom \
		${DESTDIR}${BASE}/usr/include/netrose \
		${DESTDIR}${BASE}/usr/include/nfs \
		${DESTDIR}${BASE}/usr/include/protocols \
		${DESTDIR}${BASE}/usr/include/scsi \
		${DESTDIR}${BASE}/usr/include/x86_64-linux-gnu/bits \
		${DESTDIR}${BASE}/usr/include/x86_64-linux-gnu/gnu \
		${DESTDIR}${BASE}/usr/include/x86_64-linux-gnu/sys \
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
	${BSD_INSTALL_DATA} ../linux/usr/lib/x86_64-linux-gnu/${item} ${DESTDIR}${BASE}/usr/lib64/
.  endfor
.  for item in ${Linux_shared_libs}
	${BSD_INSTALL_LIB} ../linux/lib/x86_64-linux-gnu/${item:H} ${DESTDIR}${BASE}/lib64/
	ln -s ${item:H} ${DESTDIR}${BASE}/lib64/${item:T}
	ln -s ../../lib64/${item:T} ${DESTDIR}${BASE}/usr/lib64/${item:T:R}
.  endfor
	${BSD_INSTALL_LIB} ../linux/lib/x86_64-linux-gnu/${Linux_RTLD:H} ${DESTDIR}${BASE}/lib64/
	ln -s ${Linux_RTLD:H} ${DESTDIR}${BASE}/lib64/${Linux_RTLD:T}
	# use coreutils that FreeBSD and DragonFly passed on (/bin)
.  for item in [ chmod cp date echo expr kill link ln ls mkdir mv pwd realpath rm rmdir sleep test unlink
	cp -a ${LOCALBASE}/bin/g${item} ${DESTDIR}${BASE}/bin/${item}
.  endfor
	# user coreutils that FreeBSD and DragonFly passed on (/usr/bin)
.  for item in basename chgrp chown comm cut dirname env false head id install join mkfifo mktemp \
	printenv printf readlink stat tail tee touch tee tr true tsort uniq wc whoami
	cp -a ${LOCALBASE}/bin/g${item} ${DESTDIR}${BASE}/usr/bin/${item}
.  endfor
	# ldd and which are scripts, can't be stripped
	${BSD_INSTALL_SCRIPT} ../linux/usr/bin/ldd ${DESTDIR}${BASE}/usr/bin/
	${BSD_INSTALL_SCRIPT} ../linux/bin/which ${DESTDIR}${BASE}/usr/bin/
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
