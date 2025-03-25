--- src/modules/module-protocol-pulse/message-handler.c.orig	2025-03-14 10:07:06 UTC
+++ src/modules/module-protocol-pulse/message-handler.c
@@ -6,7 +6,9 @@
 #include <stdio.h>
 
 #include <regex.h>
+#if !defined(__DragonFly__) && !defined(__FreeBSD__)
 #include <malloc.h>
+#endif
 
 #include <spa/param/props.h>
 #include <spa/pod/builder.h>
