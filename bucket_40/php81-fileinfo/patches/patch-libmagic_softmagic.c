--- libmagic/softmagic.c.orig	2022-02-16 01:00:24 UTC
+++ libmagic/softmagic.c
@@ -500,7 +500,7 @@ check_fmt(struct magic_set *ms, const ch
 	return rv;
 }
 
-#if !defined(HAVE_STRNDUP) || defined(__aiws__) || defined(_AIX)
+#if 0
 # if defined(__aiws__) || defined(_AIX)
 #  define strndup aix_strndup	/* aix is broken */
 # endif
