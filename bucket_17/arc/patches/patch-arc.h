--- arc.h.orig	2013-06-27 02:00:19 UTC
+++ arc.h
@@ -104,7 +104,7 @@ extern char     tmpchr[2];	/* Temporary
 #if	GEMDOS
 extern int      hold;		/* hold screen before exiting */
 #endif
-extern int      warn;		/* true to print warnings */
+extern int      arcwarn;	/* true to print warnings */
 extern int      note;		/* true to print comments */
 extern int      bose;		/* true to be verbose */
 extern int      nocomp;		/* true to suppress compression */
@@ -127,4 +127,8 @@ extern u_short	arctime;	/* archive time
 extern u_short	olddate;	/* old archive date stamp */
 extern u_short	oldtime;	/* old archive time stamp */
 extern int      dosquash;	/* squash instead of crunch */
+extern long     stdlen;		/* bytes to read */
+extern u_char   *outbuf;
+extern u_char   *outend;
+extern short    crcval;		/* CRC check value */
 #endif				/* DONT_DEFINE */
