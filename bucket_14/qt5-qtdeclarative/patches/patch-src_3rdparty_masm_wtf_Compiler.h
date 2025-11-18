$NetBSD: patch-src_3rdparty_masm_wtf_Compiler.h,v 1.1 2018/07/30 15:24:45 jperkin Exp $

Limit C11 _Static_assert to C code.

--- src/3rdparty/masm/wtf/Compiler.h.orig	2024-05-08 05:14:41 UTC
+++ src/3rdparty/masm/wtf/Compiler.h
@@ -134,7 +134,7 @@
 #if GCC_VERSION_AT_LEAST(4, 8, 0)
 #pragma GCC diagnostic ignored "-Wunused-local-typedefs"
 #endif
-#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
+#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L && !defined(__cplusplus)
 /* C11 support */
 #define WTF_COMPILER_SUPPORTS_C_STATIC_ASSERT 1
 #endif
