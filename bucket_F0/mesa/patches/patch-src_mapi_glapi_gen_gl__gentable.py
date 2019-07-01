--- src/mapi/glapi/gen/gl_gentable.py.orig	2019-06-25 10:45:22 UTC
+++ src/mapi/glapi/gen/gl_gentable.py
@@ -45,7 +45,7 @@ header = """/* GLXEXT is the define used
 #endif
 
 #if (defined(GLXEXT) && defined(HAVE_BACKTRACE)) \\
-	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__))
+	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__))
 #define USE_BACKTRACE
 #endif
 
