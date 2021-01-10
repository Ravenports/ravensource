--- arcunp.c.orig	2013-06-27 02:00:19 UTC
+++ arcunp.c
@@ -120,7 +120,7 @@ unpack(f, t, hdr)		/* unpack an archive
 		break;
 
 	default:		/* unknown method */
-		if (warn) {
+		if (arcwarn) {
 			printf("I don't know how to unpack file %s\n", hdr->name);
 			printf("I think you need a newer version of ARC\n");
 			nerrs++;
@@ -132,7 +132,7 @@ unpack(f, t, hdr)		/* unpack an archive
 	/* cleanups common to all methods */
 
 	if (crcval != hdr->crc) {
-		if (warn || kludge) {
+		if (arcwarn || kludge) {
 			printf("WARNING: File %s fails CRC check\n", hdr->name);
 			nerrs++;
 		}
