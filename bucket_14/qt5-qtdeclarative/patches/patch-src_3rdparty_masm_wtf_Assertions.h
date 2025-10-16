--- src/3rdparty/masm/wtf/Assertions.h.orig	2023-04-24 07:13:40 UTC
+++ src/3rdparty/masm/wtf/Assertions.h
@@ -344,7 +344,7 @@ while (0)
 
 /* COMPILE_ASSERT */
 #ifndef COMPILE_ASSERT
-#if COMPILER_SUPPORTS(C_STATIC_ASSERT)
+#if !defined(__cplusplus) && COMPILER_SUPPORTS(C_STATIC_ASSERT)
 /* Unlike static_assert below, this also works in plain C code. */
 #define COMPILE_ASSERT(exp, name) _Static_assert((exp), #name)
 #elif COMPILER_SUPPORTS(CXX_STATIC_ASSERT)
