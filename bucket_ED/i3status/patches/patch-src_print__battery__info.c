--- src/print_battery_info.c.orig	2021-11-09 07:27:11 UTC
+++ src/print_battery_info.c
@@ -593,7 +593,7 @@ void print_battery_info(battery_info_ctx
         ctx->format_percentage = "%.00f%s";
     }
 #endif
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__OpenBSD__)
+#if defined(__OpenBSD__)
     /* These OSes report battery time in minutes. */
     hide_seconds = true;
 #endif
