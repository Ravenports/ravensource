--- src/pipewire/pipewire.h.orig	2025-06-27 11:16:18 UTC
+++ src/pipewire/pipewire.h
@@ -50,9 +50,12 @@ extern "C" {
  * \{
  */
 void
-pw_init(int *argc, char **argv[]);
+pipewire_init(int *argc, char **argv[]);
 
-void pw_deinit(void);
+void pipewire_deinit(void);
+/* BSD has pw_init already */
+#define pw_init pipewire_init
+#define pw_deinit pipewire_deinit
 
 bool
 pw_debug_is_category_enabled(const char *name);
