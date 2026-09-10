--- src/library/tsitter/src/tree-sitter/lib/src/portable/endian.h.orig	2026-05-18 11:07:36 UTC
+++ src/library/tsitter/src/tree-sitter/lib/src/portable/endian.h
@@ -19,6 +19,7 @@
     defined(__linux__) || \
     defined(__GNU__) || \
     defined(__HAIKU__) || \
+    defined(__sun) || \
     defined(__illumos__) || \
     defined(__NetBSD__) || \
     defined(__OpenBSD__) || \
