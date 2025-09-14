--- cursor/cursor.h.orig	2025-09-01 22:44:21 UTC
+++ cursor/cursor.h
@@ -161,7 +161,7 @@ typedef struct xcint_image_t {
 } __attribute__((packed)) xcint_image_t;
 
 /* shape_to_id.c */
-const int cursor_shape_to_id(const char *name);
+int cursor_shape_to_id(const char *name);
 
 /* parse_cursor_file.c */
 int parse_cursor_file(xcb_cursor_context_t *c, const int fd, xcint_image_t **images, int *nimg);
