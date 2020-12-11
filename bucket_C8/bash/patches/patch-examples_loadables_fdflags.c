--- examples/loadables/fdflags.c.orig	2019-03-01 19:25:23 UTC
+++ examples/loadables/fdflags.c
@@ -109,6 +109,8 @@ static const struct
 
 #ifdef O_CLOEXEC
   { "cloexec",	O_CLOEXEC	},
+#else
+#define O_CLOEXEC 0
 #endif
 };
 
