--- x265cli.cpp.orig	2026-04-19 06:29:17 UTC
+++ x265cli.cpp
@@ -1152,7 +1152,7 @@ namespace X265_NS {
         }
 
         rewind(zoneFile);
-        char **args = (char**)alloca(256 * sizeof(char *));
+        char **args = (char**)__builtin_alloca(256 * sizeof(char *));
         param->rc.zones = x265_zone_alloc(param->rc.zonefileCount, 1);;
         for (int i = 0; i < param->rc.zonefileCount; i++)
         {
@@ -1508,4 +1508,4 @@ namespace X265_NS {
 
 #ifdef __cplusplus
 }
-#endif
\ No newline at end of file
+#endif
