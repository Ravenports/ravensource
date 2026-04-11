--- monitor.c.orig	2023-05-31 08:25:59 UTC
+++ monitor.c
@@ -341,6 +341,19 @@ monitor_insert_directory(int fd, char *n
 			continue;
 		esc_name = escape_tag(e->d_name, 1);
 		snprintf(path_buf, sizeof(path_buf), "%s/%s", path, e->d_name);
+#if defined(__sun)
+		struct stat st;
+		type = TYPE_UNKNOWN;
+		if (stat(path_buf, &st) == 0)
+		{
+		    if (S_ISDIR(st.st_mode))
+			type = resolve_unknown_type(path_buf, dir_types);
+		    else if (S_ISREG(st.st_mode))
+			type = resolve_unknown_type(path_buf, dir_types);
+		    else if (S_ISLNK(st.st_mode))
+			type = resolve_unknown_type(path_buf, dir_types);
+		}
+#else
 		switch( e->d_type )
 		{
 			case DT_DIR:
@@ -351,6 +364,7 @@ monitor_insert_directory(int fd, char *n
 			default:
 				break;
 		}
+#endif
 		if( type == TYPE_DIR )
 		{
 			monitor_insert_directory(fd, esc_name, path_buf);
