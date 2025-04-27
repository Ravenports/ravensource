Fix SunOS CS,DS conflict not handled by include/llvm-c/DataTypes.h

--- include/llvm/ADT/SmallVector.h.orig	2025-04-16 00:23:49 UTC
+++ include/llvm/ADT/SmallVector.h
@@ -30,6 +30,11 @@
 #include <type_traits>
 #include <utility>
 
+#ifdef __sun
+#undef CS
+#undef DS
+#endif
+
 namespace llvm {
 
 template <typename T> class ArrayRef;
