--- tests/amdgpu/security_tests.c.orig	2020-11-04 03:24:14 UTC
+++ tests/amdgpu/security_tests.c
@@ -29,7 +29,11 @@
 
 #include <string.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 #include <strings.h>
 #include <xf86drm.h>
 
