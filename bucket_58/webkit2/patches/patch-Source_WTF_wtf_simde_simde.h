--- Source/WTF/wtf/simde/simde.h.orig	2025-08-11 07:56:53 UTC
+++ Source/WTF/wtf/simde/simde.h
@@ -34,6 +34,8 @@
 #endif
 
 IGNORE_WARNINGS_BEGIN("constant-conversion")
+IGNORE_WARNINGS_BEGIN("sign-compare")
 #include <wtf/simde/arm/neon.h>
 #include <wtf/simde/arm/sve.h>
 IGNORE_WARNINGS_END
+IGNORE_WARNINGS_END
