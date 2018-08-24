--- tags.c.orig	2018-07-13 09:16:01 UTC
+++ tags.c
@@ -18,7 +18,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
-#if defined(LIBBSD_OVERLAY) || defined(__FreeBSD__) || defined(__GLIBC__)
+#if defined(LIBBSD_OVERLAY) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__GLIBC__)
 #  include <libutil.h>
 #else
 #include <util.h>
@@ -53,6 +53,9 @@ struct ctag {
 	char *pat;
 };
 RB_HEAD(tagtree, ctag) tags = RB_INITIALIZER(&tags);
+#ifdef __DragonFly__
+RB_PROTOTYPE(tagtree, ctag, entry, ctagcmp);
+#endif
 RB_GENERATE(tagtree, ctag, entry, ctagcmp);
 
 struct tagpos {
