--- config.mk.orig	2019-02-02 12:55:02 UTC
+++ config.mk
@@ -2,11 +2,11 @@
 VERSION = 4.9
 
 # paths
-PREFIX = /usr/local
+PREFIX ?= /usr/local
 MANPREFIX = $(PREFIX)/share/man
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+X11INC ?= $(PREFIX)/include
+X11LIB ?= $(PREFIX)/lib
 
 # Xinerama, comment if you don't want it
 XINERAMALIBS  = -lXinerama
@@ -16,16 +16,16 @@ XINERAMAFLAGS = -DXINERAMA
 FREETYPELIBS = -lfontconfig -lXft
 FREETYPEINC = /usr/include/freetype2
 # OpenBSD (uncomment)
-#FREETYPEINC = $(X11INC)/freetype2
+FREETYPEINC = $(X11INC)/freetype2
 
 # includes and libs
 INCS = -I$(X11INC) -I$(FREETYPEINC)
 LIBS = -L$(X11LIB) -lX11 $(XINERAMALIBS) $(FREETYPELIBS)
 
 # flags
-CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -DVERSION=\"$(VERSION)\" $(XINERAMAFLAGS)
-CFLAGS   = -std=c99 -pedantic -Wall -Os $(INCS) $(CPPFLAGS)
-LDFLAGS  = $(LIBS)
+CPPFLAGS += -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -DVERSION=\"$(VERSION)\" $(XINERAMAFLAGS)
+CFLAGS   += -std=c99 $(INCS) $(CPPFLAGS)
+LDFLAGS  += $(LIBS)
 
 # compiler and linker
-CC = cc
+CC ?= cc
