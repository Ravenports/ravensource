--- libmagic/softmagic.c.orig	2024-11-20 09:48:35 UTC
+++ libmagic/softmagic.c
@@ -511,7 +511,7 @@ check_fmt(struct magic_set *ms, const ch
 	return rv;
 }
 
-#if !defined(HAVE_STRNDUP) || defined(__aiws__) || defined(_AIX)
+#if 0
 # if defined(__aiws__) || defined(_AIX)
 #  define strndup aix_strndup	/* aix is broken */
 # endif
