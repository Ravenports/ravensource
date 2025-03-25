--- src/pipewire/private.h.orig	2025-03-14 10:07:06 UTC
+++ src/pipewire/private.h
@@ -14,6 +14,11 @@ extern "C" {
 #include <sys/socket.h>
 #include <sys/types.h> /* for pthread_t */
 
+#if defined(__NetBSD__)
+#include <pthread.h>
+#include <sys/time.h>
+#endif
+
 #include "pipewire/impl.h"
 
 #include <spa/support/plugin.h>
@@ -24,7 +29,7 @@ extern "C" {
 #include <spa/utils/result.h>
 #include <spa/utils/type-info.h>
 
-#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__GNU__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__GNU__) || defined(__NetBSD__)
 struct ucred {
 };
 #endif
