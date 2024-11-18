--- src/enchant.c.orig	2017-02-08 22:24:36 UTC
+++ src/enchant.c
@@ -988,7 +988,8 @@ enchant_dict_suggest (EnchantDict * dict
 	/* Check for suggestions from personal dictionary */
 	if(session->personal)
 		{
-			pwl_suggs = enchant_pwl_suggest(session->personal, word, len, dict_suggs, &n_pwl_suggs);
+			pwl_suggs = enchant_pwl_suggest(session->personal, word, len,
+				(const char * const*)dict_suggs, &n_pwl_suggs);
 			if(pwl_suggs)
 				{
 					suggsT = enchant_dict_get_good_suggestions(dict, pwl_suggs, n_pwl_suggs, &n_suggsT);
@@ -1592,7 +1593,7 @@ enchant_load_provider_ordering (EnchantB
 	for (iter = conf_dirs; iter; iter = iter->next)
 		{
 			char *ordering_file;
-			ordering_file = g_build_filename (iter->data, "enchant.ordering", NULL);
+			ordering_file = g_build_filename (iter->data, "enchant1.ordering", NULL);
 			enchant_load_ordering_from_file (broker, ordering_file);
 			g_free (ordering_file);	
 		}
