--- numpy/f2py/cfuncs.py.orig	2022-01-29 12:20:32 UTC
+++ numpy/f2py/cfuncs.py
@@ -578,6 +578,9 @@ cppmacros["F2PY_THREAD_LOCAL_DECL"] = ""
 #define F2PY_THREAD_LOCAL_DECL __thread
 #elif defined(__STDC_VERSION__) \\
       && (__STDC_VERSION__ >= 201112L) \\
+      && !defined(__DragonFly__) \\
+      && !defined(__FreeBSD__) \\
+      && !defined(__sun__) \\ 
       && !defined(__STDC_NO_THREADS__) \\
       && (!defined(__GLIBC__) || __GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ > 12)) \\
       && !defined(__OpenBSD__)
