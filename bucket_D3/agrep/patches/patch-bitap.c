--- bitap.c.intermediate	2016-10-22 12:40:44 UTC
+++ bitap.c
@@ -447,7 +447,7 @@ int fd, M, D;
 #endif	/*AGREP_POINTER*/
 }
 
-fill_buf(fd, buf, record_size)
+int fill_buf(fd, buf, record_size)
 int fd, record_size; 
 unsigned char *buf;
 {
