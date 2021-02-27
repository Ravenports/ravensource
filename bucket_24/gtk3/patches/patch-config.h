--- config.h.in.orig	2021-02-23 14:32:24 UTC
+++ config.h.in
@@ -10,6 +10,9 @@
 /* Disable deprecation warnings from glib */
 #undef GLIB_DISABLE_DEPRECATION_WARNINGS
 
+/* Define if we're using atk-bridge-2.0 */
+#undef HAVE_ATK_BRIDGE
+
 /* Define to 1 if you have the `bind_textdomain_codeset' function. */
 #undef HAVE_BIND_TEXTDOMAIN_CODESET
 
