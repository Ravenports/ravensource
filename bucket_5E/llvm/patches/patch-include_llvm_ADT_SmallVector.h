Fix SunOS CS,DS conflict not handled by include/llvm-c/DataTypes.h

--- include/llvm/ADT/SmallVector.h.orig	2021-06-28 16:23:38 UTC
+++ include/llvm/ADT/SmallVector.h
@@ -32,6 +32,11 @@
 #include <type_traits>
 #include <utility>
 
+#ifdef __sun
+#undef CS
+#undef DS
+#endif
+
 namespace llvm {
 
 /// This is all the stuff common to all SmallVectors.
