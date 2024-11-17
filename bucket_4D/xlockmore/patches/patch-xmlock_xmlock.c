--- xmlock/xmlock.c.orig	2023-07-12 21:33:07 UTC
+++ xmlock/xmlock.c
@@ -42,7 +42,7 @@ static const char sccsid[] = "@(#)xmlock
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #include <signal.h>
 #endif
 #include <sys/signal.h>
