--- Instant/tptregexp/strerror.c.orig	1996-06-17 03:50:30 UTC
+++ Instant/tptregexp/strerror.c
@@ -3,9 +3,11 @@
  * (eg, SUN)
  */
 
+#if 0
 char *
 strerror(int num)
 {
 	perror(num);
 	return "";
 }    
+#endif
