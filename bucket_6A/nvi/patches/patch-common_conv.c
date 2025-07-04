--- common/conv.c.orig	2025-07-04 16:57:38 UTC
+++ common/conv.c
@@ -61,29 +61,6 @@ raw2int(SCR *sp, const char * str, ssize
 }
 
 #define CONV_BUFFER_SIZE    512
-/* fill the buffer with codeset encoding of string pointed to by str
- * left has the number of bytes left in str and is adjusted
- * len contains the number of bytes put in the buffer
- */
-#ifdef USE_ICONV
-#define CONVERT(str, left, src, len)				    	\
-    do {								\
-	size_t outleft;							\
-	char *bp = buffer;						\
-	outleft = CONV_BUFFER_SIZE;					\
-	errno = 0;							\
-	if (iconv(id, (char **)&str, &left, &bp, &outleft) == -1 /*&&	\
-		errno != E2BIG*/)					\
-	    goto err;							\
-	if ((len = CONV_BUFFER_SIZE - outleft) == 0) {			\
-	    error = -left;						\
-	    goto err;							\
-	}				    				\
-	src = buffer;							\
-    } while (0)
-#else
-#define CONVERT(str, left, src, len)
-#endif
 
 int 
 default_char2int(SCR *sp, const char * str, ssize_t len, CONVWIN *cw, 
@@ -109,7 +86,29 @@ default_char2int(SCR *sp, const char * s
 	id = iconv_open(nl_langinfo(CODESET), enc);
 	if (id == (iconv_t)-1)
 	    goto err;
-	CONVERT(str, left, src, len);
+        /*
+         * fill the buffer with codeset encoding of string pointed to by str
+         * left has the number of bytes left in str and is adjusted
+         * len contains the number of bytes put in the buffer (CONVERT macro)
+         */
+	errno = 0;
+	do {
+	    size_t outleft = CONV_BUFFER_SIZE;
+	    char *pbuffer = buffer;
+# if defined __sun__
+	    if (iconv(id, (const char **)&str, &left, &pbuffer, &outleft) == -1)
+# else
+	    if (iconv(id, (char **)&str, &left, &pbuffer, &outleft) == -1)
+# endif
+	    {
+	        goto err;
+	    }
+	    if ((len = CONV_BUFFER_SIZE - outleft) == 0) {
+	        error = -left;
+	        goto err;
+	    }
+	    src = buffer;
+	} while (0);
     }
 #endif
 
@@ -125,7 +124,27 @@ default_char2int(SCR *sp, const char * s
 	    BINC_RETW(NULL, *tostr, *blen, nlen);
 	}
 	if (id != (iconv_t)-1 && j == len && left) {
-	    CONVERT(str, left, src, len);
+#ifdef USE_ICONV
+	    /* CONVERT macro */
+	   errno = 0;
+	    do {
+		size_t outleft = CONV_BUFFER_SIZE;
+		char *pbuffer = buffer;
+# if defined __sun__
+		if (iconv(id, (const char **)&str, &left, &pbuffer, &outleft) == -1)
+# else
+		if (iconv(id, (char **)&str, &left, &pbuffer, &outleft) == -1)
+# endif
+		{
+		    goto err;
+		}
+		if ((len = CONV_BUFFER_SIZE - outleft) == 0) {
+		    error = -left;
+		    goto err;
+		}
+		src = buffer;
+	    } while (0);
+#endif
 	    j = 0;
 	}
     }
@@ -210,7 +229,8 @@ int
 default_int2char(SCR *sp, const CHAR_T * str, ssize_t len, CONVWIN *cw, 
 		size_t *tolen, char **pdst, char *enc)
 {
-    int i, j, offset = 0;
+    int i, offset = 0;
+    size_t j;
     char **tostr = (char **)&cw->bp1;
     size_t  *blen = &cw->blen1;
     mbstate_t mbs;
@@ -221,32 +241,6 @@ default_int2char(SCR *sp, const CHAR_T *
     char	buffer[CONV_BUFFER_SIZE];
     iconv_t	id = (iconv_t)-1;
 
-/* convert first len bytes of buffer and append it to cw->bp
- * len is adjusted => 0
- * offset contains the offset in cw->bp and is adjusted
- * cw->bp is grown as required
- */
-#ifdef USE_ICONV
-#define CONVERT2(len, cw, offset)					\
-    do {								\
-	char *bp = buffer;						\
-	while (len != 0) {						\
-	    size_t outleft = cw->blen1 - offset;			\
-	    char *obp = (char *)cw->bp1 + offset;		    	\
-	    if (cw->blen1 < offset + MB_CUR_MAX) {		    	\
-		nlen += 256;						\
-		BINC_RETC(NULL, cw->bp1, cw->blen1, nlen);		\
-	    }						    		\
-	    errno = 0;						    	\
-	    if (iconv(id, &bp, &len, &obp, &outleft) == -1 && 	        \
-		    errno != E2BIG)					\
-		goto err;						\
-	    offset = cw->blen1 - outleft;			        \
-	}							        \
-    } while (0)
-#else
-#define CONVERT2(len, cw, offset)
-#endif
 
 
     MEMSET(&mbs, 0, 1);
@@ -268,7 +262,32 @@ default_int2char(SCR *sp, const CHAR_T *
 	j += n;
 	if (buflen < j + MB_CUR_MAX) {
 	    if (id != (iconv_t)-1) {
-		CONVERT2(j, cw, offset);
+#ifdef USE_ICONV
+		/* convert first len bytes of buffer and append it to cw->bp
+		 * len (aka j) is adjusted => 0
+		 * offset contains the offset in cw->bp and is adjusted
+		 * cw->bp is grown as required
+		 */
+		errno = 0;
+		do {
+#  if defined(__sun__)
+		    const char *pbuffer = buffer;
+#  else
+		    char *pbuffer = buffer;
+#  endif
+		    while (j != 0) {
+			size_t outleft = cw->blen1 - offset;
+			char *obp = (char *)cw->bp1 + offset;
+			if (cw->blen1 < offset + MB_CUR_MAX) {
+			    nlen += 256;
+			    BINC_RETC(NULL, cw->bp1, cw->blen1, nlen);
+			}
+			if (iconv(id, &pbuffer, &j, &obp, &outleft) == -1 && errno != E2BIG)
+			    goto err;
+			offset = cw->blen1 - outleft;
+		    }
+		} while(0);
+#endif
 	    } else {
 		nlen += 256;
 		BINC_RETC(NULL, *tostr, *blen, nlen);
@@ -282,7 +301,28 @@ default_int2char(SCR *sp, const CHAR_T *
     *tolen = j;
 
     if (id != (iconv_t)-1) {
-	CONVERT2(j, cw, offset);
+#ifdef USE_ICONV
+	/* CONVERT2 macro */
+	errno = 0;
+	do {
+#  if defined(__sun__)
+	    const char *pbuffer = buffer;
+#  else
+	    char *pbuffer = buffer;
+#  endif
+	    while (j != 0) {
+		size_t outleft = cw->blen1 - offset;
+		char *obp = (char *)cw->bp1 + offset;
+		if (cw->blen1 < offset + MB_CUR_MAX) {
+		    nlen += 256;
+		    BINC_RETC(NULL, cw->bp1, cw->blen1, nlen);
+		}
+		if (iconv(id, &pbuffer, &j, &obp, &outleft) == -1 && errno != E2BIG)
+		    goto err;
+		offset = cw->blen1 - outleft;
+	    }
+	} while(0);
+#endif
 	*tolen = offset;
     }
 
@@ -322,11 +362,16 @@ conv_init (SCR *orig, SCR *sp)
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
