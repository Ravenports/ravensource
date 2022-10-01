--- examples/loadables/fdflags.c.orig	2022-07-26 14:16:57 UTC
+++ examples/loadables/fdflags.c
@@ -109,6 +109,8 @@ static const struct
 
 #ifdef O_CLOEXEC
   { "cloexec",	O_CLOEXEC	},
+#else
+#define O_CLOEXEC 0
 #endif
 };
 
