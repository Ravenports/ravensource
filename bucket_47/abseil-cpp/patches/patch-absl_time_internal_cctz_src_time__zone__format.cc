$NetBSD: patch-absl_time_internal_cctz_src_time__zone__format.cc,v 1.2 2023/03/08 09:58:16 adam Exp $

Avoid _XOPEN_SOURCE.

--- absl/time/internal/cctz/src/time_zone_format.cc.orig	2023-05-04 14:32:38 UTC
+++ absl/time/internal/cctz/src/time_zone_format.cc
@@ -19,7 +19,7 @@
 #endif
 
 #if defined(HAS_STRPTIME) && HAS_STRPTIME
-#if !defined(_XOPEN_SOURCE) && !defined(__OpenBSD__)
+#if !defined(_XOPEN_SOURCE) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 #define _XOPEN_SOURCE  // Definedness suffices for strptime.
 #endif
 #endif
