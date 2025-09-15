--- hw/ppc/mac_newworld.c.orig	2025-08-26 18:32:38 UTC
+++ hw/ppc/mac_newworld.c
@@ -76,6 +76,11 @@
 #include "hw/sysbus.h"
 #include "trace.h"
 
+/* FreeBSD headers define this */
+#ifdef round_page
+#undef round_page
+#endif
+
 #define MAX_IDE_BUS 2
 #define CFG_ADDR 0xf0000510
 #define TBFREQ (25UL * 1000UL * 1000UL)
