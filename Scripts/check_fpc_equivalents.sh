#!/bin/sh
#
# The purpose of this script is to catch FPC_EQUIVALENT values of "N/A"
# that are not on a whitelist.  This usually means they were forgotten
# to be defined.

CONSPIR=$(/raven/bin/ravenadm dev info D)

tmpfile=/tmp/fpc.notlist
PROG='{if ($3 == "N/A") print}'
awk "${PROG}" ${CONSPIR}/Mk/Misc/fpc_equivalents > ${tmpfile}

echo "List of ports with undefined FPC_EQUIVALENT values:"
while read ravenport version fpc_port; do
   case "${ravenport}" in
	libbsd) ;; 		# linux only
	libusb) ;; 		# linux only
	shadow) ;;		# linux only
	musl-fts) ;;		# linux only
	libgudev) ;;		# linux only
	libnftnl) ;;		# linux only
	libbsd4sol);;		# solaris only

	ravenports) ;;		# unique to ravenports
	libdl) ;;		# unique to ravenports
	ravensys-root) ;;	# unique to ravenports
	ravensys-toolchain) ;;	# unique to ravenports
	ravensys-uname) ;;	# unique to ravenports
	ravensys-selector) ;;	# unique to ravenports
	ravensys-utils) ;;	# unique to ravenports
	bmake-mk-files) ;;	# unique to ravenports
	ravenadm) ;;		# unique to ravenports
	autoselect-*) ;;	# unique to ravenports
	ravensw) ;;		# unique to ravenports

	bc) ;;			# for sysroot
	ed) ;;			# for sysroot
	xz) ;;			# for sysroot, deleted from FPC

	zlib) ;;		# deleted from FPC
	aflex*) ;;		# deleted from FPC
	go14) ;;		# ditto
	ede) ;;			# ditto

	fetch) ;;		# From DragonFly
	makewhatis) ;;		# From DragonFly
	mtree) ;;		# From DragonFly
	rpcgen) ;;		# From DragonFly
	sha256) ;;		# From DragonFly
	bsd-patch) ;;		# From DragonFly/FreeBSD
	bsd-which) ;;		# From DragonFly/FreeBSD

	libedit) ;;		# Different version scheme from FPC
	gnat-util) ;;		# Different version scheme from FPC
	gprbuild) ;;		# Different version scheme from FPC
	apr1|apr-util) ;;	# Different version scheme from FPC
	aom) ;;                 # ditto
	rtmpdump) ;;		# ditto
	libzen) ;;		# ditto
	compiler-rt) ;;		# ditto
	mariadb102) ;;		# ditto
	ImageMagick) ;;		# W.X.Y.Z rather than W.X.Y-Z
	irssi) ;;		# fake version
	libcdio-paranoia) ;;	# Symbols in version fake as older
	libunwind) ;;		# ditto
	unrar) ;;		# ditto
	autoconf213) ;;		# ditto
	cwm) ;;			# ditto
	fonts-gentium-basic) ;;	# ditto
	libdbusmenu-qt) ;;	# ditto
	fontconfig) ;;          # FPC tracking beta versions

	aspell-el) ;;		# requires EPOCH, 0.08 > 0.50 actually
	aspell-pl) ;;		# incorrectly identifies as newer (scheme difference)
	hunspell-pt*) ;;	# Freebsd combines BR/PT, but raven splits them up
	bash) ;;		# incorrectly identifies as different and older (5.1.p4 vs 5.1.4)
	openjade) ;;            # FreeBSD uses dev version, ravenports has release
	python-*) ;;            # manual python port
	ncurses) ;;		# FreeBSD uses dev version now
	ncurses60) ;;		# required for 1 or 2 apps
	gsfonts) ;;		# noschema (8.11 vs 8.11pre)
	norm) ;;		# fails to recognize 1.5.8 > 1.5r6
	double-conversion) ;;	# garbage version, recheck periodically
	w3m) ;;			# Different version scheme (we use OpenBSD now)
	webkitgtk) ;;		# older branch

	libexecinfo) ;;		# Different source from FPC
	doas) ;;		# ditto

	qt5-qtbase) ;;		# FreeBSD splits these packages into sep one
	qt5-qttools) ;;		#
	qt5-qtdeclarative) ;;	#
	gstreamer1-*-xshm) ;;   # FreeBSD combined with plugins-x
	qt6-*) ;;		# QT6 isn't on freebsd yet
	gtkmm40) ;;		# check periodically
	gtk4) ;;		# check periodically
	
	usb-modeswitch-data) ;;	# combined with sysutils/usb_modeswitch
	rustless-firefox) ;;	# currently like www/firefox-esr, but RP is frozen

	gps|gnatstudio) ;;	# removed from FPC (stupidly)
	GeoIP) ;;		# removed from FPC
	libcxx) ;;		# removed from FPC
	warsow*) ;;		# removed
	XML_EZ_Out) ;;		# removed
	libsparkcrypto) ;;	# removed
	langkit) ;;		# removed
	sparforte) ;;		# removed
	aucatctl) ;;		# removed
	simple_components) ;;	# removed
	py27-pygobject) ;;	# removed
	py27-setuptools) ;;	# removed
	aws) ;;			# removed
	db6) ;;			# removed

	mdds-1.5) ;;		# latest for libreoffice
	mdds) ;;

	libadalang*) ;;		# Rest are ports that FPC doesn't have yet
	ada_libfswatch) ;;
	ada_language_server) ;;
	ada_spawn) ;;
	langkit_support) ;;
	ACATS) ;;
	libtickit) ;;
	libmpack) ;;
	lua-mpack) ;;
	lua-penlight) ;;
	quex) ;;
	slider) ;;
	firebird30) ;;
	fuse3) ;;
	aspell-mg | aspell-hus) ;;
	gnatcross*) ;;
	edelib) ;;
	openpam) ;;
	AdaYaml) ;;
	libuuid) ;;
	stterm)  ;;
	bezitopo) ;;
	pekwm-themepack) ;;
	libxmlxx) ;;			# check libxml++ occ.
	guile) ;;			# check occasionally
	libsigcxx) ;;			# check occasionally
	hardlink-osx) ;;
	gnatcoll-*) ;;
	openmp|clang|lld|llvm-libunwind) ;;
	ldoc) ;;
	corefonts) ;;
	precomp) ;;
	oed) ;;
	libmnl) ;;
	libsvgtiny) ;;
	linenoise) ;;
	libnsfb) ;;
	elftoolchain) ;;
	libnslog) ;;
	libluv) ;;
	lua-zlib) ;;
	ixion) ;;
	skia) ;;
	shotgun) ;;
	libtcod) ;;
	termcap) ;;
	media-types) ;;
	opencl-clhpp) ;;
	rocm-device-libs) ;;
	b3sum) ;;
	dosfstools) ;;
	libvss) ;;
	gdk-pixbuf-xlib) ;;
	dos2unix) ;;
	msgpack-cxx) ;;
	libmd) ;;
	*) echo "${ravenport} ${version}"
   esac
done < ${tmpfile}

rm -f ${tmpfile}
