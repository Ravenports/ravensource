--- src/enchant.c.orig	2017-02-08 22:24:36 UTC
+++ src/enchant.c
@@ -1592,7 +1592,7 @@ enchant_load_provider_ordering (EnchantB
 	for (iter = conf_dirs; iter; iter = iter->next)
 		{
 			char *ordering_file;
-			ordering_file = g_build_filename (iter->data, "enchant.ordering", NULL);
+			ordering_file = g_build_filename (iter->data, "enchant1.ordering", NULL);
 			enchant_load_ordering_from_file (broker, ordering_file);
 			g_free (ordering_file);	
 		}
