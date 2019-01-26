diff --git config.mk config.mk
index 5691aae..081f667 100644
--- config.mk
+++ config.mk
@@ -10,6 +10,7 @@ DOTDESKTOPPREFIX := $(DESTDIR)$(PREFIX)/share/applications
 LIBDIR           := $(DESTDIR)$(PREFIX)/lib/vimb
 RUNPREFIX        := $(PREFIX)
 EXTENSIONDIR     := $(RUNPREFIX)/lib/vimb
+OS               := $(shell uname -s)
 
 # define some directories
 SRCDIR  = src
@@ -22,12 +23,15 @@ LIBS = gtk+-3.0 'webkit2gtk-4.0 >= 2.20.0'
 CFLAGS   += -std=c99 -pipe -Wall -fPIC
 CPPFLAGS += -DEXTENSIONDIR=\"${EXTENSIONDIR}\"
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
