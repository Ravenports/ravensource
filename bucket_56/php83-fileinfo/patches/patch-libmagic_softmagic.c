--- libmagic/softmagic.c.orig	2023-11-21 14:40:35 UTC
+++ libmagic/softmagic.c
@@ -508,7 +508,7 @@ check_fmt(struct magic_set *ms, const ch
 	return rv;
 }
 
-#if !defined(HAVE_STRNDUP) || defined(__aiws__) || defined(_AIX)
+#if 0
 # if defined(__aiws__) || defined(_AIX)
 #  define strndup aix_strndup	/* aix is broken */
 # endif
