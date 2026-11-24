--- lib/install_oses.mk.orig	2026-11-23 22:40:52 UTC
+++ lib/install_oses.mk
@@ -15,3 +15,7 @@ UNAME := $(shell sh -c 'MSYSTEM="MSYS" u
 
 # List of OSes for which target install is supported
 INSTALL_OS_LIST ?= Linux Darwin GNU/kFreeBSD GNU OpenBSD FreeBSD NetBSD DragonFly SunOS Haiku AIX MSYS_NT% CYGWIN_NT%
+
+
+
+INSTALL_OS_LIST += MidnightBSD
