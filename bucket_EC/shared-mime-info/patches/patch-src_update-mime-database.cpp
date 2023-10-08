--- src/update-mime-database.cpp.orig	2023-10-07 11:16:03 UTC
+++ src/update-mime-database.cpp
@@ -2158,7 +2158,7 @@ static void check_in_path_xdg_data(const
 
 	env = getenv("XDG_DATA_DIRS");
 	if (!env)
-		env = "/usr/local/share/"PATH_SEPARATOR"/usr/share/";
+		env = "/usr/local/share/";
 	dirs = g_strsplit(env, PATH_SEPARATOR, 0);
 	g_return_if_fail(dirs != NULL);
 	for (n = 0; dirs[n]; n++)
