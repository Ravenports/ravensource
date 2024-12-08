--- libmagic/softmagic.c.orig	2023-01-31 15:13:17 UTC
+++ libmagic/softmagic.c
@@ -500,7 +500,7 @@ check_fmt(struct magic_set *ms, const ch
 	return rv;
 }
 
-#if !defined(HAVE_STRNDUP) || defined(__aiws__) || defined(_AIX)
+#if 0
 # if defined(__aiws__) || defined(_AIX)
 #  define strndup aix_strndup	/* aix is broken */
 # endif
