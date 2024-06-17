--- client/mysqltest.cc.orig	2024-05-09 08:56:44 UTC
+++ client/mysqltest.cc
@@ -46,6 +46,7 @@
 #include <stdarg.h>
 #include <violite.h>
 #define PCRE2_STATIC 1  /* Important on Windows */
+#include "pcre2.h"
 #include "pcre2posix.h" /* pcreposix regex library */
 #ifdef HAVE_SYS_WAIT_H
 #include <sys/wait.h>
