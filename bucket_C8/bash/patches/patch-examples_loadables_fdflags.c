--- examples/loadables/fdflags.c.orig	2017-02-02 16:40:42 UTC
+++ examples/loadables/fdflags.c
@@ -73,6 +73,8 @@ static const struct
 #endif
 #ifdef O_CLOEXEC
   { "cloexec",	O_CLOEXEC	},
+#else
+#define O_CLOEXEC 0
 #endif
 };
 
