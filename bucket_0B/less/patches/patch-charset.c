--- charset.c.orig	2020-06-14 03:34:49 UTC
+++ charset.c
@@ -432,6 +432,10 @@ binary_char(c)
 control_char(c)
 	LWCHAR c;
 {
+#ifdef COLOR_LESS
+	if (c == ESC)
+		return 0;
+#endif
 	c &= 0377;
 	return (chardef[c] & IS_CONTROL_CHAR);
 }
@@ -447,6 +451,20 @@ prchar(c)
 	/* {{ This buffer can be overrun if LESSBINFMT is a long string. }} */
 	static char buf[32];
 
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
@@ -470,6 +488,7 @@ prchar(c)
 #endif
 	else
 		SNPRINTF1(buf, sizeof(buf), binfmt, c);
+#endif
 	return (buf);
 }
 
