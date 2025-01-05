--- client/mysqltest.cc.orig	2024-11-11 07:18:41 UTC
+++ client/mysqltest.cc
@@ -46,6 +46,7 @@
 #include <stdarg.h>
 #include <violite.h>
 #define PCRE2_STATIC 1  /* Important on Windows */
+#include "pcre2.h"
 #include "pcre2posix.h" /* pcreposix regex library */
 #ifdef HAVE_SYS_WAIT_H
 #include <sys/wait.h>
