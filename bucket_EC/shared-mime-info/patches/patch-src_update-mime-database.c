--- src/update-mime-database.c.orig	2020-12-31 19:12:16 UTC
+++ src/update-mime-database.c
@@ -636,7 +636,8 @@ static void remove_old(Type *type, xmlNo
 		}
 	}
 
-	xmlFree(lang);
+	if (lang)
+		xmlFree(lang);
 }
 
 /* 'node' is a <mime-type> node from a source file, whose type is 'type'.
@@ -2174,7 +2175,7 @@ static void check_in_path_xdg_data(const
 
 	env = getenv("XDG_DATA_DIRS");
 	if (!env)
-		env = "/usr/local/share/"PATH_SEPARATOR"/usr/share/";
+		env = "/usr/local/share/";
 	dirs = g_strsplit(env, PATH_SEPARATOR, 0);
 	g_return_if_fail(dirs != NULL);
 	for (n = 0; dirs[n]; n++)
