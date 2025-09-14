--- config.mk.orig	2025-09-08 20:07:41 UTC
+++ config.mk
@@ -4,15 +4,15 @@ VERSION = 1
 # Customize below to fit your system
 
 # paths
-PREFIX = /usr/local
+PREFIX ?= /usr/local
 MANPREFIX = ${PREFIX}/share/man
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+#X11INC = /usr/X11R6/include
+#X11LIB = /usr/X11R6/lib
 
 # includes and libs
-INCS = -I. -I/usr/include -I/usr/include/freetype2 -I${X11INC}
-LIBS = -L/usr/lib -lc -lm -L${X11LIB} -lXft -lfontconfig -lX11
+INCS = -I. -I${PREFIX}/include -I/${PREFIX}/include/freetype2
+LIBS = -L${PREFIX}/lib -lc -lm -lXft -lfontconfig -lX11
 # OpenBSD (uncomment)
 #INCS = -I. -I${X11INC} -I${X11INC}/freetype2
 # FreeBSD (uncomment)
