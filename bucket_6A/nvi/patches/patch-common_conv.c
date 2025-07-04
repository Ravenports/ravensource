--- common/conv.c.orig	2007-11-18 16:41:42 UTC
+++ common/conv.c
@@ -210,7 +210,8 @@ int
 default_int2char(SCR *sp, const CHAR_T * str, ssize_t len, CONVWIN *cw, 
 		size_t *tolen, char **pdst, char *enc)
 {
-    int i, j, offset = 0;
+    int i, offset = 0;
+    size_t j;
     char **tostr = (char **)&cw->bp1;
     size_t  *blen = &cw->blen1;
     mbstate_t mbs;
@@ -322,11 +323,16 @@ conv_init (SCR *orig, SCR *sp)
     else {
 	setlocale(LC_ALL, "");
 #ifdef USE_WIDECHAR
-	sp->conv.sys2int = cs_char2int;
-	sp->conv.int2sys = cs_int2char;
-	sp->conv.file2int = fe_char2int;
-	sp->conv.int2file = fe_int2char;
-	sp->conv.input2int = ie_char2int;
+	if (!strcmp(LANGCODESET, "ANSI_X3.4-1968")) {
+	    sp->conv.file2int = sp->conv.input2int = sp->conv.sys2int = raw2int;
+	    sp->conv.int2sys = sp->conv.int2file = int2raw;
+	} else {
+	    sp->conv.sys2int = cs_char2int;
+	    sp->conv.int2sys = cs_int2char;
+	    sp->conv.file2int = fe_char2int;
+	    sp->conv.int2file = fe_int2char;
+	    sp->conv.input2int = ie_char2int;
+	}
 #endif
 #ifdef USE_ICONV
 	o_set(sp, O_FILEENCODING, OS_STRDUP, nl_langinfo(CODESET), 0);
