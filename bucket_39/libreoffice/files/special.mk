COLLADA_MODS=	COLLADABaseUtils \
		COLLADAFramework \
		COLLADASaxFrameworkLoader \
		GeneratedSaxParser

COLLADA_CFLAGS=	${COLLADA_MODS:S|^|-isystem ${LOCALBASE}/include/opencollada/|}
COLLADA_LIBS=	-L${LOCALBASE}/lib/opencollada ${COLLADA_MODS:S|^COLLADA|OpenCOLLADA|:S|^|-l|}

REPLACE_LIST= \
	external/curl/ExternalProject_curl.mk \
	external/liblangtag/ExternalProject_langtag.mk \
	external/libxmlsec/ExternalProject_xmlsec.mk \
	external/libxslt/ExternalProject_xslt.mk \
	external/nss/ExternalProject_nss.mk \
	external/openssl/ExternalProject_openssl.mk \
	external/redland/ExternalProject_raptor.mk \
	external/redland/ExternalProject_rasqal.mk \
	external/redland/ExternalProject_redland.mk \
	include/osl/endian.h \
	registry/workben/makefile.mk \
	sal/osl/unx/system.cxx \
	solenv/bin/modules/installer/parameter.pm \
	soltools/mkdepend/main.c \
	stoc/source/corereflection/criface.cxx \
	vcl/qa/cppunit/BitmapTest.cxx \
	vcl/unx/generic/app/saldata.cxx \
	vcl/unx/generic/dtrans/X11_selection.cxx \
	vcl/unx/generic/gdi/salbmp.cxx \
	vcl/unx/generic/printer/printerinfomanager.cxx \
	vcl/unx/kde/kdedata.cxx \
	desktop/unx/source/start.c \
	jvmfwk/plugins/sunmajor/pluginlib/sunversion.cxx \
	jvmfwk/plugins/sunmajor/pluginlib/sunversion.hxx \
	sal/osl/unx/process_impl.cxx \
	sal/osl/unx/sockimpl.hxx \
	sal/osl/unx/pipe.cxx \
	vcl/unx/gtk3/gtk3gtkdata.cxx \
	vcl/unx/gtk/gtkdata.cxx

PERCENT_BSD_LIST= \
	Repository.mk \
	avmedia/Library_avmediaogl.mk \
	chart2/Library_chartcore.mk \
	chart2/Library_chartopengl.mk \
	desktop/CppunitTest_desktop_app.mk \
	desktop/Library_crashreport.mk\
	desktop/Library_sofficeapp.mk \
	libreofficekit/Module_libreofficekit.mk \
	libreofficekit/Executable_gtktiledviewer.mk \
	libreofficekit/Library_libreofficekitgtk.mk \
	svx/Executable_gengal.mk \
	vcl/CppunitTest_vcl_wmf_test.mk \
	vcl/Executable_vcldemo.mk \
	vcl/Executable_visualbackendtest.mk \
	vcl/Executable_ui-previewer.mk \
	vcl/Executable_mtfdemo.mk \
	vcl/Module_vcl.mk \
	vcl/Library_desktop_detector.mk \
	vcl/Library_vcl.mk \
	vcl/Executable_icontest.mk

