--- m4/ax_pthread.m4.orig	2018-07-27 20:30:28 UTC
+++ m4/ax_pthread.m4
@@ -212,7 +212,7 @@ case $host_os in
 	ax_pthread_check_macro="_REENTRANT"
 	;;
 
-	aix* | freebsd*)
+	aix*)
 	ax_pthread_check_macro="_THREAD_SAFE"
 	;;
 
