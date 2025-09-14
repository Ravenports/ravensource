--- config.mk.orig	2025-09-08 18:45:58 UTC
+++ config.mk
@@ -4,15 +4,15 @@ VERSION = 4
 # Customize below to fit your system
 
 # paths
-PREFIX = /usr/local
+PREFIX ?= /usr/local
 MANPREFIX = $(PREFIX)/share/man
 
 # flags
 CPPFLAGS = -D_DEFAULT_SOURCE
-CFLAGS   = -std=c99 -pedantic -Wall -Wextra -Os
-LDFLAGS  = -s
+CFLAGS   += -std=c99 -pedantic -Wall -Wextra -Os
+LDFLAGS  += -s
 PNG-LDLIBS = -lpng
 JPG-LDLIBS = -ljpeg
 
 # compiler and linker
-CC = cc
+CC ?= cc
