--- include/fluent-bit/simdutf/flb_simdutf_connector.h.orig	2026-04-14 17:27:00 UTC
+++ include/fluent-bit/simdutf/flb_simdutf_connector.h
@@ -24,7 +24,7 @@
 extern "C" {
 #endif /* __cplusplus */
 
-#ifdef __APPLE__
+#if defined __NetBSD__ || defined __APPLE__
 #include <stdint.h>
 #include <stddef.h>
 typedef int_least16_t CHAR16_T;
