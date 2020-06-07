--- antiword.h.orig	2020-06-07 12:18:53.435545000 +0200
+++ antiword.h	2020-06-07 12:19:57.130061000 +0200
@@ -224,7 +224,7 @@
 #define ANTIWORD_DIR		".antiword"
 #define FONTNAMES_FILE		"fontnames"
 #else	/* All others */
-#define GLOBAL_ANTIWORD_DIR	"/usr/share/antiword"
+#define GLOBAL_ANTIWORD_DIR	"__PREFIX__/share/antiword"
 #define ANTIWORD_DIR		".antiword"
 #define FONTNAMES_FILE		"fontnames"
 #endif /* __dos */
