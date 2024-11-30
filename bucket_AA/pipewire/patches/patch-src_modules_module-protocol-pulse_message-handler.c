--- src/modules/module-protocol-pulse/message-handler.c.orig	2024-10-23 07:44:10 UTC
+++ src/modules/module-protocol-pulse/message-handler.c
@@ -6,7 +6,9 @@
 #include <stdio.h>
 
 #include <regex.h>
+#if !defined(__DragonFly__) && !defined(__FreeBSD__)
 #include <malloc.h>
+#endif
 
 #include <spa/param/props.h>
 #include <spa/pod/builder.h>
