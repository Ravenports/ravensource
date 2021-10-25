--- src/gn/version.h.orig	2020-08-12 19:30:44 UTC
+++ src/gn/version.h
@@ -8,6 +8,15 @@
 #include <optional>
 #include <string>
 
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
