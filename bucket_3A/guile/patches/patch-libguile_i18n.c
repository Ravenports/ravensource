--- libguile/i18n.c.orig	2023-02-10 13:16:15 UTC
+++ libguile/i18n.c
@@ -43,6 +43,7 @@
 #include "smob.h"
 #include "strings.h"
 #include "symbols.h"
+#include "async.h"
 #include "syscalls.h"
 #include "threads.h"
 #include "values.h"
