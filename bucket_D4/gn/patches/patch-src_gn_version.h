--- src/gn/version.h.orig	2026-03-12 15:29:33 UTC
+++ src/gn/version.h
@@ -15,6 +15,15 @@
 #undef minor
 #endif
 
+// Undefine major/minor from sys/types.h
+#ifdef major
+#undef major
+#endif
+
+#ifdef minor
+#undef minor
+#endif
+
 // Represents a semantic version.
 class Version {
  public:
