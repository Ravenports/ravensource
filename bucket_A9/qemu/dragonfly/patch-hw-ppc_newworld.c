--- hw/ppc/mac_newworld.c.orig	2026-04-21 19:36:26 UTC
+++ hw/ppc/mac_newworld.c
@@ -76,6 +76,11 @@
 #include "hw/core/sysbus.h"
 #include "trace.h"
 
+/* FreeBSD headers define this */
+#ifdef round_page
+#undef round_page
+#endif
+
 #define MAX_IDE_BUS 2
 #define CFG_ADDR 0xf0000510
 #define TBFREQ (25UL * 1000UL * 1000UL)
