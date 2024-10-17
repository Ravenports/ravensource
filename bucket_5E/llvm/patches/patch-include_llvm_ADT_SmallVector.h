Fix SunOS CS,DS conflict not handled by include/llvm-c/DataTypes.h

--- include/llvm/ADT/SmallVector.h.orig	2024-10-15 08:17:37 UTC
+++ include/llvm/ADT/SmallVector.h
@@ -31,6 +31,11 @@
 #include <type_traits>
 #include <utility>
 
+#ifdef __sun
+#undef CS
+#undef DS
+#endif
+
 namespace llvm {
 
 template <typename T> class ArrayRef;
