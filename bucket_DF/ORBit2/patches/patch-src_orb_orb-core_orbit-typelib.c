--- src/orb/orb-core/orbit-typelib.c.orig	2010-02-09 12:05:35 UTC
+++ src/orb/orb-core/orbit-typelib.c
@@ -218,6 +218,7 @@ ORBit_get_typelib_paths (void)
 	paths = g_ptr_array_sized_new (8);
 
 	g_ptr_array_add (paths, g_strdup (ORBIT_TYPELIB_DIR));
+	add_if_unique(paths, "%%LOCALBASE%%", TRUE);
 
 	if ((path = g_getenv ("ORBIT_TYPELIB_PATH"))) {
 		char **strv;
