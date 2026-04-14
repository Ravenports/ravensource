SunOS uses __BYTE_ORDER, BSD* uses _BYTE_ORDER.
However, There are no big endian platforms in Ravenports, so just remove the
check completely.

--- src/oss.c.orig	2011-02-23 01:51:00 UTC
+++ src/oss.c
@@ -259,11 +259,7 @@ static int open_oss(ca_context *c, struc
                 val = AFMT_S16_NE;
                 break;
         case CA_SAMPLE_S16RE:
-#if __BYTE_ORDER == __LITTLE_ENDIAN
                 val = AFMT_S16_BE;
-#else
-                val = AFMT_S16_LE;
-#endif
                 break;
         }
 
