$NetBSD: patch-js_src_jsnativestack.cpp,v 1.1 2018/05/11 19:18:35 jperkin Exp $

Support SunOS.

--- jsnativestack.cpp.orig	2017-04-11 02:13:16 UTC
+++ jsnativestack.cpp
@@ -59,7 +59,7 @@ js::GetNativeStackBaseImpl()
 # endif
 }
 
-#elif defined(SOLARIS)
+#elif defined(__sun)
 
 #include <ucontext.h>
 
@@ -105,6 +105,7 @@ js::GetNativeStackBaseImpl()
 #  elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(NETBSD)
     /* e.g. on FreeBSD 4.8 or newer, neundorf@kde.org */
     pthread_attr_get_np(thread, &sattr);
+#  elif defined(__sun)
 #  else
     /*
      * FIXME: this function is non-portable;
