--- lib/assert.h.orig	2021-04-19 03:43:11 UTC
+++ lib/assert.h
@@ -43,6 +43,10 @@
 #ifndef INCLUDED_ASSERT_H
 #define INCLUDED_ASSERT_H
 
+#ifdef __cplusplus
+extern "C" {
+#endif
+
 #ifdef __STDC__
 #define assert(ex)      {if (!(ex))assertionfailed(__FILE__, __LINE__, #ex);}
 void assertionfailed(const char *file, int line, const char *expr);
@@ -50,4 +54,8 @@ void assertionfailed(const char *file, i
 #define assert(ex)      {if (!(ex))assertionfailed(__FILE__, __LINE__, (char*)0);}
 #endif
 
+#ifdef __cplusplus
+}
+#endif
+
 #endif /* INCLUDED_ASSERT_H */
