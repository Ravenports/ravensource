$NetBSD: patch-Source_WTF_wtf_Assertions.h,v 1.1 2021/01/12 15:21:31 jperkin Exp $

Use regular static_assert on SunOS.

--- Source/WTF/wtf/Assertions.h.orig	2024-03-16 06:45:49 UTC
+++ Source/WTF/wtf/Assertions.h
@@ -489,7 +489,7 @@ constexpr bool assertionFailureDueToUnre
 
 /* COMPILE_ASSERT */
 #ifndef COMPILE_ASSERT
-#if COMPILER_SUPPORTS(C_STATIC_ASSERT)
+#if COMPILER_SUPPORTS(C_STATIC_ASSERT) && !defined(__sun)
 /* Unlike static_assert below, this also works in plain C code. */
 #define COMPILE_ASSERT(exp, name) _Static_assert((exp), #name)
 #else
