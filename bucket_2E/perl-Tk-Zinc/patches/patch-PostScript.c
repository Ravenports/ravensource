--- PostScript.c.orig	2020-11-25 19:23:17 UTC
+++ PostScript.c
@@ -305,7 +305,7 @@ ZnPostScriptCmd(ZnWInfo        *wi,
   ps_info.prolog = 1;
   Tcl_InitHashTable(&ps_info.fontTable, TCL_STRING_KEYS);
   result = Tk_ConfigureWidget(wi->interp, wi->win, config_specs,
-                              argc-2, (CONST char **) argv+2,
+                              argc-2, (Tcl_Obj * const*) argv+2,
                               (char *) &ps_info,
                               TK_CONFIG_ARGV_ONLY|TK_CONFIG_OBJS);
   if (result != TCL_OK) {
