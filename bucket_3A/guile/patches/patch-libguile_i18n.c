--- libguile/i18n.c.orig	2022-10-21 15:39:38 UTC
+++ libguile/i18n.c
@@ -43,6 +43,7 @@
 #include "smob.h"
 #include "strings.h"
 #include "symbols.h"
+#include "async.h"
 #include "syscalls.h"
 #include "threads.h"
 #include "values.h"
