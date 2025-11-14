--- include/fluent-bit/simdutf/flb_simdutf_connector.h.orig	2025-10-08 13:42:21 UTC
+++ include/fluent-bit/simdutf/flb_simdutf_connector.h
@@ -24,7 +24,7 @@
 extern "C" {
 #endif /* __cplusplus */
 
-#ifdef __APPLE__
+#if defined __NetBSD__ || defined __APPLE__
 #include <stdint.h>
 #include <stddef.h>
 typedef int_least16_t CHAR16_T;
