--- gdb/s390-tdep.c.orig	2020-05-23 21:10:29 UTC
+++ gdb/s390-tdep.c
@@ -40,6 +40,10 @@
 #include "trad-frame.h"
 #include "value.h"
 
+#ifdef __sun__
+#undef CS
+#endif
+
 #include "features/s390-linux32.c"
 #include "features/s390x-linux64.c"
 
