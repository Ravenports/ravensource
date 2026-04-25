--- src/main/printutils.c.orig	2026-04-07 10:15:01 UTC
+++ src/main/printutils.c
@@ -752,9 +752,6 @@ const char *EncodeString(SEXP s, int w,
 			*/
 			for(int j = 0; j < res; j++) *q++ = *p++;
 		    } else {
-# if !defined (__STDC_ISO_10646__) && !defined (Win32)
-			Unicode_warning = TRUE;
-# endif
 			if(k > 0xffff)
 			    snprintf(buf, 13, "\\U{%06x}", k);
 			else
