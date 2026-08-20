--- osdep-dragonfly.c.orig	2026-04-03 09:57:03 UTC
+++ osdep-dragonfly.c
@@ -28,6 +28,8 @@
 #include <string.h>
 #include <unistd.h>
 
+#include "compat.h"
+
 struct kinfo_proc	*cmp_procs(struct kinfo_proc *, struct kinfo_proc *);
 char			*osdep_get_name(int, char *);
 char			*osdep_get_cwd(int);
