--- src/update-mime-database.cpp.orig	2023-11-12 08:52:33 UTC
+++ src/update-mime-database.cpp
@@ -2159,7 +2159,7 @@ static void check_in_path_xdg_data(const
 
 	env = getenv("XDG_DATA_DIRS");
 	if (!env)
-		env = "/usr/local/share/" PATH_SEPARATOR "/usr/share/";
+		env = "/usr/local/share/";
 	dirs = g_strsplit(env, PATH_SEPARATOR, 0);
 	g_return_if_fail(dirs != NULL);
 	for (n = 0; dirs[n]; n++)
