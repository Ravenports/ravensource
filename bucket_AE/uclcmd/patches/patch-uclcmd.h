--- uclcmd.h.orig	2021-12-06 19:25:25 UTC
+++ uclcmd.h
@@ -134,6 +134,10 @@ int get_cmd_type(const ucl_object_t *obj
 int get_cmd_values(const ucl_object_t *obj, char *nodepath,
     const char *command_str, char *remaining_commands, int recurse);
 
+#ifndef __printflike
+#define __printflike(fmtarg, firstvararg) __attribute__((__nonnull__(fmtarg), __format__ (__printf__, fmtarg, firstvararg)))
+#endif
+
 void uclcmd_asprintf(char ** __restrict s, char const * __restrict fmt, ...)
     __printflike(2, 3);
 
