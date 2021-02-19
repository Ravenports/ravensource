--- numpy/f2py/cfuncs.py.orig	2021-02-07 09:26:20 UTC
+++ numpy/f2py/cfuncs.py
@@ -549,6 +549,9 @@ cppmacros["F2PY_THREAD_LOCAL_DECL"] = ""
 #define F2PY_THREAD_LOCAL_DECL __declspec(thread)
 #elif defined(__STDC_VERSION__) \\
       && (__STDC_VERSION__ >= 201112L) \\
+      && !defined(__DragonFly__) \\
+      && !defined(__FreeBSD__) \\
+      && !defined(__sun__) \\ 
       && !defined(__STDC_NO_THREADS__) \\
       && (!defined(__GLIBC__) || __GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ > 12))
 /* __STDC_NO_THREADS__ was first defined in a maintenance release of glibc 2.12,
