--- src/gn/version.h.orig	2022-11-10 16:29:39 UTC
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
