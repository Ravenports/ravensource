--- src/main/printutils.c.orig	2021-04-19 22:02:06 UTC
+++ src/main/printutils.c
@@ -751,9 +751,6 @@ const char *EncodeString(SEXP s, int w,
 			*/
 			for(int j = 0; j < res; j++) *q++ = *p++;
 		    } else {
-# if !defined (__STDC_ISO_10646__) && !defined (Win32)
-			if(!use_ucs) Unicode_warning = TRUE;
-# endif
 			if(k > 0xffff)
 			    snprintf(buf, 13, "\\U{%06x}", k);
 			else
