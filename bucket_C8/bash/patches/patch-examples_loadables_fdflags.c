--- examples/loadables/fdflags.c.orig	2023-11-27 23:53:21 UTC
+++ examples/loadables/fdflags.c
@@ -121,6 +121,8 @@ static const struct
 
 #ifdef O_CLOEXEC
   { "cloexec",	O_CLOEXEC	},
+#else
+#define O_CLOEXEC 0
 #endif
 };
 
