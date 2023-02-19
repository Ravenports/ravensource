--- Include/pymacro.h.orig	2023-02-07 13:37:51 UTC
+++ Include/pymacro.h
@@ -6,8 +6,10 @@
 // the static_assert() macro. Define the static_assert() macro in Python until
 // <sys/cdefs.h> suports C11:
 // https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=255290
-#if defined(__FreeBSD__) && !defined(static_assert)
+#if (defined(__FreeBSD__) || defined(__DragonFly__)) && !defined(static_assert)
+# if !(defined(__cplusplus) && __cplusplus >= 201103L)
 #  define static_assert _Static_assert
+# endif
 #endif
 
 // static_assert is defined in glibc from version 2.16. Before it requires
