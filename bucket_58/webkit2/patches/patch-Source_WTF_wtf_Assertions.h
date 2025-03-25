$NetBSD: patch-Source_WTF_wtf_Assertions.h,v 1.1 2021/01/12 15:21:31 jperkin Exp $

Use regular static_assert on SunOS.

--- Source/WTF/wtf/Assertions.h.orig	2025-02-25 08:25:40 UTC
+++ Source/WTF/wtf/Assertions.h
@@ -539,7 +539,7 @@ constexpr bool assertionFailureDueToUnre
 
 /* COMPILE_ASSERT */
 #ifndef COMPILE_ASSERT
-#if COMPILER_SUPPORTS(C_STATIC_ASSERT)
+#if COMPILER_SUPPORTS(C_STATIC_ASSERT) && !defined(__sun)
 /* Unlike static_assert below, this also works in plain C code. */
 #define COMPILE_ASSERT(exp, name) _Static_assert((exp), #name)
 #else
