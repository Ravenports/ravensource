--- easysnmp/interface.c.orig	2022-07-16 15:53:20 UTC
+++ easysnmp/interface.c
@@ -261,8 +261,9 @@ void __libraries_init()
                        NETSNMP_OID_OUTPUT_SUFFIX);
 }
 
-void __libraries_free()
+void __libraries_free(void *module)
 {
+    (void)module;
     snmp_shutdown(APPNAME);
 }
 
