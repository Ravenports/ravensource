--- leptonica/src/sarray1.c.orig	2023-09-13 06:45:02 UTC
+++ leptonica/src/sarray1.c
@@ -149,6 +149,13 @@
 #endif  /* ! _WIN32 */
 #include "allheaders.h"
 
+#ifdef __sun
+static int
+dirfd(DIR *dirp) {
+        return (dirp->d_fd);
+}
+#endif
+
 static const l_uint32  MaxPtrArraySize = 25000000;  /* 25 million */
 static const l_int32   InitialPtrArraySize = 50;      /*!< n'importe quoi */
 
