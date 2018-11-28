$NetBSD: patch-memory_mozalloc_mozalloc__abort.cpp,v 1.1 2018/05/11 19:18:35 jperkin Exp $

Support SunOS.

--- ../../memory/mozalloc/mozalloc_abort.cpp.orig	2017-04-11 02:13:16 UTC
+++ ../../memory/mozalloc/mozalloc_abort.cpp
@@ -68,7 +68,11 @@ void fillAbortMessage(char (&msg)[N], ui
 //
 // That segmentation fault will be interpreted as another bug by ASan and as a
 // result, ASan will just exit(1) instead of aborting.
+#ifdef __sun
+void std::abort(void)
+#else
 void abort(void)
+#endif
 {
 #ifdef MOZ_WIDGET_ANDROID
     char msg[64] = {};
