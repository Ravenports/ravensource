--- unix/tclUnixInit.c.orig	2024-11-27 15:56:57 UTC
+++ unix/tclUnixInit.c
@@ -394,14 +394,6 @@ TclpInitPlatform(void)
 #endif /* SIGPIPE */
 
 #if defined(__FreeBSD__) && defined(__GNUC__)
-    /*
-     * Adjust the rounding mode to be more conventional. Note that FreeBSD
-     * only provides the __fpsetreg() used by the following two for the GNU
-     * Compiler. When using, say, Intel's icc they break. (Partially based on
-     * patch in BSD ports system from root@celsius.bychok.com)
-     */
-
-    fpsetround(FP_RN);
     (void) fpsetmask(0L);
 #endif
 
