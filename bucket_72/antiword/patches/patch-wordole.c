CVE-2014-8123 patch
bGetPPS(): Prevent overflow of atPPSlist[].szName[]

--- wordole.c.orig	2005-08-26 21:49:57.000000000 +0200
+++ wordole.c	2020-06-07 12:25:28.344416000 +0200
@@ -259,6 +259,11 @@
 		}
 		tNameSize = (size_t)usGetWord(0x40, aucBytes);
 		tNameSize = (tNameSize + 1) / 2;
+		if (tNameSize >= sizeof(atPPSlist[0].szName)) {
+			werr(0, "PPS %d appears to be invalid.", iIndex);
+			atPPSlist = xfree(atPPSlist);
+			return FALSE;
+		}
 		vName2String(atPPSlist[iIndex].szName, aucBytes, tNameSize);
 		atPPSlist[iIndex].ucType = ucGetByte(0x42, aucBytes);
 		if (atPPSlist[iIndex].ucType == 5) {
