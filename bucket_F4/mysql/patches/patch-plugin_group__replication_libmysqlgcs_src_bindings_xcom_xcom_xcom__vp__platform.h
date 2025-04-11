--- plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_vp_platform.h.orig	2024-12-16 11:00:04 UTC
+++ plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_vp_platform.h
@@ -37,13 +37,11 @@
 #endif
 #endif
 
-#ifdef __APPLE__
-#if __APPLE__
+#ifdef __NetBSD__
 
 /* xdr_uint64_t and xdr_uint32_t are not defined on OSX */
 #define xdr_uint64_t xdr_u_int64_t
 #define xdr_uint32_t xdr_u_int32_t
 #endif
-#endif
 
 #endif
