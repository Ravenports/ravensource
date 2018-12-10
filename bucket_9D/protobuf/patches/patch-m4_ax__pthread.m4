--- m4/ax_pthread.m4.orig	2018-12-04 23:52:48 UTC
+++ m4/ax_pthread.m4
@@ -212,7 +212,7 @@ case $host_os in
 	ax_pthread_check_macro="_REENTRANT"
 	;;
 
-	aix* | freebsd*)
+	aix*)
 	ax_pthread_check_macro="_THREAD_SAFE"
 	;;
 
