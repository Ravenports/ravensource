--- scribus/third_party/lib2geom/isnan.h.orig	2020-11-14 22:37:17 UTC
+++ scribus/third_party/lib2geom/isnan.h
@@ -34,7 +34,7 @@
 #elif defined(WIN32) || defined(_isnan)
 # define is_nan(_a) (_isnan(_a)) 	/* Win32 definition */
 #elif defined(isnan) || defined(__FreeBSD__)
-# define is_nan(_a) (isnan(_a))		/* GNU definition */
+# define is_nan(_a) (std::isnan(_a))		/* GNU definition */
 #else
 # define is_nan(_a) (std::isnan(_a))
 #endif
