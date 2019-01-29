--- config.mk.orig	2018-11-06 22:27:25 UTC
+++ config.mk
@@ -12,6 +12,7 @@ DOTDESKTOPPREFIX := $(DESTDIR)$(PREFIX)/
 LIBDIR           := $(DESTDIR)$(PREFIX)/lib/vimb
 RUNPREFIX        := $(PREFIX)
 EXTENSIONDIR     := $(RUNPREFIX)/lib/vimb
+OS               := $(shell uname -s)
 
 # define some directories
 SRCDIR  = src
@@ -26,17 +27,20 @@ COMMIT := $(shell git describe --tags --
 CFLAGS   += -std=c99 -pipe -Wall -fPIC
 CPPFLAGS += -DVERSION=\"${VERSION}\" -DEXTENSIONDIR=\"${EXTENSIONDIR}\" -DCOMMIT=\"$(COMMIT)\"
 CPPFLAGS += -DPROJECT=\"vimb\" -DPROJECT_UCFIRST=\"Vimb\"
-CPPFLAGS += -D_XOPEN_SOURCE=500
-CPPFLAGS += -D__BSD_VISIBLE
 CPPFLAGS += -DGSEAL_ENABLE
 CPPFLAGS += -DGTK_DISABLE_SINGLE_INCLUDES
 CPPFLAGS += -DGDK_DISABLE_DEPRECATED
 
+ifeq "$(findstring $(OS),FreeBSD DragonFly)" ""
+CPPFLAGS += -D_XOPEN_SOURCE=500
+CPPFLAGS += -D__BSD_VISIBLE
+endif
+
 # flags used to build webextension
 EXTTARGET   = webext_main.so
 EXTCFLAGS   = ${CFLAGS} $(shell pkg-config --cflags webkit2gtk-web-extension-4.0)
 EXTCPPFLAGS = $(CPPFLAGS)
-EXTLDFLAGS  = $(shell pkg-config --libs webkit2gtk-web-extension-4.0) -shared
+EXTLDFLAGS  = -Wl,-rpath,$(PREFIX)/lib $(shell pkg-config --libs webkit2gtk-web-extension-4.0) -shared
 
 # flags used for the main application
 CFLAGS     += $(shell pkg-config --cflags $(LIBS))
