--- common/tags.c.orig	2008-11-01 23:21:42 UTC
+++ common/tags.c
@@ -23,6 +23,7 @@
 
 // #include "mpcenc.h"
 #include <stdio.h>
+#include <string.h>
 #include <mpc/mpc_types.h>
 
 #ifdef _WIN32
@@ -34,7 +35,7 @@
 #endif
 
 // Path separator
-#if defined __unix__  ||  defined __bsdi__  ||  defined __FreeBSD__  ||  defined __OpenBSD__  ||  defined __NetBSD__  ||  defined __APPLE__
+#if defined __unix__  ||  defined __bsdi__  ||  defined __FreeBSD__  ||  defined __OpenBSD__  ||  defined __NetBSD__  ||  defined __APPLE__ || defined __DragonFly__
 # define PATH_SEP               '/'
 # define DRIVE_SEP              '\0'
 #elif defined _WIN32  ||  defined __TURBOC__  ||  defined __ZTC__  ||  defined _MSC_VER
