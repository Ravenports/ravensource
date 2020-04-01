--- config/config-backends.h.orig	2020-03-29 20:21:15 UTC
+++ config/config-backends.h
@@ -44,3 +44,8 @@ void config_hal_fini(void);
 int config_wscons_init(void);
 void config_wscons_fini(void);
 #endif
+
+#ifdef CONFIG_DEVD
+int config_devd_init(void);
+void config_devd_fini(void);
+#endif
