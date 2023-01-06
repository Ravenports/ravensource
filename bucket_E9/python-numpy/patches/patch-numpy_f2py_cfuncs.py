--- numpy/f2py/cfuncs.py.orig	2022-12-26 03:52:53 UTC
+++ numpy/f2py/cfuncs.py
@@ -546,6 +546,9 @@ cppmacros["F2PY_THREAD_LOCAL_DECL"] = ""
 #define F2PY_THREAD_LOCAL_DECL __thread
 #elif defined(__STDC_VERSION__) \\
       && (__STDC_VERSION__ >= 201112L) \\
+      && !defined(__DragonFly__) \\
+      && !defined(__FreeBSD__) \\
+      && !defined(__sun__) \\ 
       && !defined(__STDC_NO_THREADS__) \\
       && (!defined(__GLIBC__) || __GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ > 12)) \\
       && !defined(NPY_OS_OPENBSD) && !defined(NPY_OS_HAIKU)
