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
	libseccomp) ;;		# linux only
	libmount) ;;		# linux only
	libtirpc) ;;		# linux only
	rpcbind) ;;		# linux only
	unfs3) ;;		# linux only
	kmod) ;;		# linux only

	ravenports) ;;		# unique to ravenports
	ravensys-root*) ;;	# unique to ravenports
	ravensys-toolchain) ;;	# unique to ravenports
	ravensys-utils) ;;	# unique to ravenports
	ravensys-vuln) ;;	# unique to ravenports
	ravenadm) ;;		# unique to ravenports
	autoselect-*) ;;	# unique to ravenports
	rvn) ;;			# unique to ravenports

	bc) ;;			# for sysroot
	ed) ;;			# for sysroot
	xz) ;;			# for sysroot, deleted from FPC

	fw-amdgpu) ;;		# dragonfly only

	zlib) ;;		# deleted from FPC
	aflex*) ;;		# deleted from FPC
	zip-ada) ;;		# deleted from FPC
	booch95) ;;		# deleted from FPC
	anet) ;;		# deleted from FPC
	alog) ;;		# deleted from FPC
	pcsc-ada) ;;		# deleted from FPC
	apq-*) ;;		# deleted from FPC
	words) ;;		# deleted from FPC
	adasockets) ;;		# deleted from FPC
	sparforte) ;;		# deleted from FPC
	libsparkcrypto) ;;	# deleted from FPC
	PragmARC) ;;		# deleted from FPC
	XML_EZ_Out) ;;		# deleted from FPC
	generic_image_dec*) ;;	# deleted from FPC
	simple_components) ;;	# deleted from FPC
	templates-parser) ;;	# deleted from FPC
	excel-writer) ;;	# deleted from FPC
	matreshka) ;;		# deleted from FPC
	langkit) ;;		# deleted from FPC
	gtkada) ;;		# deleted from FPC
	adabase) ;;		# deleted from FPC
	gps|gnatstudio) ;;	# deleted from FPC (stupidly)
	ironsides) ;;		# deleted from FPC
	florist) ;;		# deleted from FPC
	lua-ada) ;;		# deleted from FPC
	aunit) ;;		# deleted from FPC
	ahven) ;;		# deleted from FPC
	ede) ;;			# deleted from FPC

	fetch) ;;		# From DragonFly
	libedit) ;;		# Different version scheme from FPC
	gprbuild) ;;		# Different version scheme from FPC
	apr1|apr-util) ;;	# Different version scheme from FPC
	aom) ;;                 # ditto
	rtmpdump) ;;		# ditto
	libzen) ;;		# ditto
	compiler-rt) ;;		# ditto
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
	re2) ;;			# different date punctuation

	aspell-el) ;;		# requires EPOCH, 0.08 > 0.50 actually
	aspell-pl) ;;		# incorrectly identifies as newer (scheme difference)
	hunspell-pt*) ;;	# Freebsd combines BR/PT, but raven splits them up
	bash) ;;		# incorrectly identifies as different and older (5.1.p4 vs 5.1.4)
	openjade) ;;            # FreeBSD uses dev version, ravenports has release
	python-*) ;;            # manual python port
	ncurses) ;;		# FreeBSD uses dev version now
	gsfonts) ;;		# noschema (8.11 vs 8.11pre)
	norm) ;;		# fails to recognize 1.5.8 > 1.5r6
	double-conversion) ;;	# garbage version, recheck periodically
	w3m) ;;			# Different version scheme (we use OpenBSD now)
	webkitgtk) ;;		# older branch
	fonts-anonymous-pro) ;;	# version comparison problem 1.002 vs 1_003
	xclip) ;;		# freebsd fake version
	clisp) ;;		# fake version 2.49.95+20241228
	nvi) ;;			# freebsd uses a different version with same namebase
	musepack) ;;		# version mismatch version=r475 freebsd=2011.08.10

	libexecinfo) ;;		# Different source from FPC
	doas) ;;		# ditto

	gstreamer1-*-xshm) ;;   # FreeBSD combined with plugins-x
	gtkmm40) ;;		# check periodically
	gtk4) ;;		# check periodically
	
	usb-modeswitch-data) ;;	# combined with sysutils/usb_modeswitch
	spirv-llvm-trans*22) ;; # FreeBSD doesn't have older versions
	tk90|tcl90) ;;		# FreeBSD doesn't have older versions
	ffmpeg8) ;;		# FreeBSD doesn't have older versions

	GeoIP) ;;		# removed from FPC
	libcxx) ;;		# removed from FPC
	warsow*) ;;		# removed
	aucatctl) ;;		# removed
	aws) ;;			# removed
	db6) ;;			# removed
	cairomm10) ;;		# removed
	wmctrl) ;;		# removed
	libcddb) ;;		# removed
	tcsh) ;;		# removed
	pangomm14) ;;		# removed
	db4) ;;			# removed
	giblib) ;;		# removed
	bmake) ;;		# removed
	libkate) ;;		# removed
	libtorrent-rasterbar) ;;      # removed
	xorg-driver-video-i740) ;;    # removed

	mdds-3.0|mdds-3.1) ;;	# freebsd only matches with mdds-3.2
	php8?-openssl) ;;	# not sure why this is missing from FPC

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
	fuse3) ;;
	aspell-mg | aspell-hus) ;;
	gnatcross*) ;;
	edelib) ;;
	openpam) ;;
	AdaYaml) ;;
	libuuid) ;;
	stterm)  ;;
	pekwm-themepack) ;;
	libxmlxx) ;;			# check libxml++ occ.
	guile) ;;			# check occasionally
	libsigcxx) ;;			# check occasionally
	gnatcoll-*) ;;
	llvm*|openmp*|clang*|lld*) ;;
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
	xmltoman) ;;
	xorg-dmx) ;;
	ferron) ;;
	blogc) ;;
	libusb-compat) ;;
	zxcvbn-c) ;;
	libart-trinity) ;;
	mandown) ;;
	fzssh) ;;
	AdaID) ;;
	ada-markdown) ;;
	oxicloud) ;;
	hickory-dns) ;;
	geomyidae) ;;
	fonts-VTCGoblinHand-ttf) ;;
	linux-api-headers) ;;
	prettier-ada) ;;
	gnatformat) ;;
	gnatdoc) ;;
	AdaSAT) ;;
	gpr2tools) ;;
	lal-refactor) ;;
	libxdiff_ada) ;;
	vss-*) ;;
	zesarux) ;;
	telescope) ;;
	l3afpad) ;;
	ssvnc) ;;
	postgresql-libversion) ;;
	pdfio) ;;
	libtiger) ;;
	rs-tftpd) ;;
	unifdef) ;;
	libvolume_id) ;;
	xsecurelock) ;;	
	libppd) ;;
	projectm-eval) ;;
	edlin) ;;
	freedit) ;;
	p7zip) ;;
	lua-alt-getopt) ;;
	vo-aacenc) ;;
	*) echo "${ravenport} ${version}"
   esac
done < ${tmpfile}

rm -f ${tmpfile}
