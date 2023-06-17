--- charset.c.orig	2023-05-03 18:43:01 UTC
+++ charset.c
@@ -525,6 +525,10 @@ public int binary_char(LWCHAR c)
  */
 public int control_char(LWCHAR c)
 {
+#ifdef COLOR_LESS
+	if (c == ESC)
+		return 0;
+#endif
 	c &= 0377;
 	return (chardef[c] & IS_CONTROL_CHAR);
 }
@@ -538,6 +542,20 @@ public char * prchar(LWCHAR c)
 	/* {{ This buffer can be overrun if LESSBINFMT is a long string. }} */
 	static char buf[MAX_PRCHAR_LEN+1];
 
+#ifdef COLOR_LESS
+	if(c == ESC)
+		sprintf(buf, "%c", ESC);
+	else
+	{
+		c &= 0377;
+		if (!control_char(c))
+			sprintf(buf, "%c", c);
+		else if (!control_char(c ^ 0100))
+			sprintf(buf, "^%c", c ^ 0100);
+		else
+			sprintf(buf, binfmt, c);
+	}
+#else
 	c &= 0377;
 	if ((c < 128 || !utf_mode) && !control_char(c))
 		SNPRINTF1(buf, sizeof(buf), "%c", (int) c);
@@ -561,6 +579,7 @@ public char * prchar(LWCHAR c)
 #endif
 	else
 		SNPRINTF1(buf, sizeof(buf), binfmt, c);
+#endif
 	return (buf);
 }
 
