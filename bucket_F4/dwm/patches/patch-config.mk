--- config.mk	2023-01-13 06:28:24.304269397 +0000
+++ config.mk.new	2023-01-13 06:36:14.886263477 +0000
@@ -4,11 +4,11 @@
 # Customize below to fit your system
 
 # paths
-PREFIX = /usr/local
+PREFIX = __PREFIX__
 MANPREFIX = ${PREFIX}/share/man
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+X11INC = __PREFIX__/include/X11
+X11LIB = __PREFIX__/lib/X11
 
 # Xinerama, comment if you don't want it
 XINERAMALIBS  = -lXinerama
@@ -16,7 +16,7 @@
 
 # freetype
 FREETYPELIBS = -lfontconfig -lXft
-FREETYPEINC = /usr/include/freetype2
+FREETYPEINC = __PREFIX__/include/freetype2
 # OpenBSD (uncomment)
 #FREETYPEINC = ${X11INC}/freetype2
 #MANPREFIX = ${PREFIX}/man
