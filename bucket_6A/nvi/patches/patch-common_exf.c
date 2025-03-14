Get rid of "page sizes must be a power-of-2" warning when loading a file.

--- common/exf.c.orig	2007-11-18 16:41:42 UTC
+++ common/exf.c
@@ -228,15 +228,17 @@ file_init(SCR *sp, FREF *frp, char *rcv_
 		/*
 		 * XXX
 		 * A seat of the pants calculation: try to keep the file in
-		 * 15 pages or less.  Don't use a page size larger than 10K
+		 * 15 pages or less.  Don't use a page size larger than 16K
 		 * (vi should have good locality) or smaller than 1K.
 		 */
-		psize = ((sb.st_size / 15) + 1023) / 1024;
-		if (psize > 10)
-			psize = 10;
-		if (psize == 0)
-			psize = 1;
-		psize *= 1024;
+		psize = (sb.st_size > 0) ? ffsl(sb.st_size - 1) + 1 : 0;
+		/* Do these very low limits make sense anymore? */
+		if (psize < 10)
+			psize = 10;  /* 1K  */
+		if (psize > 14)
+			psize = 14;  /* 16K */
+		/* Keep page size on power of 2 boundary to keep db4 happy. */
+		psize = 1 << psize;
 
 		F_SET(ep, F_DEVSET);
 		ep->mdev = sb.st_dev;
