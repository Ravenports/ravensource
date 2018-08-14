--- libscg/scsihack.c.orig	2013-07-30 18:37:09 UTC
+++ libscg/scsihack.c
@@ -138,8 +138,7 @@ EXPORT scg_ops_t scg_std_ops = {
 
 #endif	/* linux */
 
-#if	defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || \
-	defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#if	defined(__NetBSD__) || defined(__OpenBSD__)
 #define	SCSI_IMPL		/* We have a SCSI implementation for *BSD */
 
 #include "scsi-bsd.c"
