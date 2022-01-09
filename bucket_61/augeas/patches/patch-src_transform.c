security_context_t dropped by gnulib.
(Then why does the submodule point to a snapshot of gnulib that doesn't support it???)

--- src/transform.c.orig	2021-10-24 07:01:19 UTC
+++ src/transform.c
@@ -917,8 +917,6 @@ static int transfer_file_attrs(FILE *fro
                                const char **err_status) {
     struct stat st;
     int ret = 0;
-    int selinux_enabled = (is_selinux_enabled() > 0);
-    security_context_t con = NULL;
 
     int from_fd;
     int to_fd = fileno(to);
@@ -935,12 +933,6 @@ static int transfer_file_attrs(FILE *fro
         *err_status = "replace_stat";
         return -1;
     }
-    if (selinux_enabled) {
-        if (fgetfilecon(from_fd, &con) < 0 && errno != ENOTSUP) {
-            *err_status = "replace_getfilecon";
-            return -1;
-        }
-    }
 
     if (fchown(to_fd, st.st_uid, st.st_gid) < 0) {
         *err_status = "replace_chown";
@@ -950,13 +942,6 @@ static int transfer_file_attrs(FILE *fro
         *err_status = "replace_chmod";
         return -1;
     }
-    if (selinux_enabled && con != NULL) {
-        if (fsetfilecon(to_fd, con) < 0 && errno != ENOTSUP) {
-            *err_status = "replace_setfilecon";
-            return -1;
-        }
-        freecon(con);
-    }
     return 0;
 }
 
