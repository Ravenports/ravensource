$NetBSD: patch-include_llvm-c_DataTypes.h,v 1.1 2019/01/26 21:17:20 tnn Exp $

Don't implement sys/regset.h workaround, fix source instead.

--- include/llvm-c/DataTypes.h.orig	2020-10-07 10:10:48 UTC
+++ include/llvm-c/DataTypes.h
@@ -81,4 +81,27 @@ typedef signed int ssize_t;
 #define HUGE_VALF (float)HUGE_VAL
 #endif
 
+#if defined(__sun)
+#include <sys/regset.h>
+#undef CS
+#undef DS
+#undef ES
+#undef FS
+#undef GS
+#undef SS
+#undef EAX
+#undef ECX
+#undef EDX
+#undef EBX
+#undef ESP
+#undef EBP
+#undef ESI
+#undef EDI
+#undef EIP
+#undef UESP
+#undef EFL
+#undef ERR
+#undef TRAPNO
+#endif
+
 #endif /* LLVM_C_DATATYPES_H */
