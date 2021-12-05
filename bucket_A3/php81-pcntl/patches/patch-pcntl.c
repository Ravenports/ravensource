--- pcntl.c.orig	2021-11-23 18:56:11 UTC
+++ pcntl.c
@@ -1528,9 +1528,11 @@ PHP_FUNCTION(pcntl_rfork)
 		flags |= RFPROC;
 	}
 
+#ifdef RFTSIGZMB
 	if ((flags & RFTSIGZMB) != 0) {
 		flags |= RFTSIGFLAGS(csignal);
 	}
+#endif
 
 	pid = rfork(flags);
 
