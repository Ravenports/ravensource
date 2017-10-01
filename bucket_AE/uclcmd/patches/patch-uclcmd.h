--- uclcmd.h.orig	2017-04-28 04:19:05 UTC
+++ uclcmd.h
@@ -51,6 +51,12 @@
 #define __DECONST(type, var)    ((type)(uintptr_t)(const void *)(var))
 #endif
 
+#ifndef __printflike
+#define	__printflike(fmtarg, firstvararg) \
+            __attribute__((__nonnull__(fmtarg), \
+			  __format__ (__printf__, fmtarg, firstvararg)))
+#endif
+
 #define UCLCMD_PARSER_FLAGS	UCL_PARSER_KEY_LOWERCASE | \
 		UCL_PARSER_NO_IMPLICIT_ARRAYS | UCL_PARSER_SAVE_COMMENTS
 
