--- include/libEMF/wine/windef.h.orig	2026-05-04 19:14:29 UTC
+++ include/libEMF/wine/windef.h
@@ -126,6 +126,7 @@ typedef INT     CALLBACK (*PROC)();
 #endif
 
 /* min and max macros */
+#ifndef __cplusplus
 #ifndef NOMINMAX
 #ifndef max
 #define max(a,b)   (((a) > (b)) ? (a) : (b))
@@ -134,6 +135,7 @@ typedef INT     CALLBACK (*PROC)();
 #define min(a,b)   (((a) < (b)) ? (a) : (b))
 #endif
 #endif  /* NOMINMAX */
+#endif  /* __cplusplus */
 
 #ifndef _MAX_PATH
 /* FIXME: These are supposed to be in stdlib.h only */
