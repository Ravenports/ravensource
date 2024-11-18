--- src/pwl.c.orig	2017-02-08 22:24:36 UTC
+++ src/pwl.c
@@ -736,7 +736,7 @@ char** enchant_pwl_suggest(EnchantPWL *p
 	EnchantSuggList sugg_list;
 	int max_dist;
 
-	max_dist = suggs? best_distance(suggs, word, len) : ENCHANT_PWL_MAX_ERRORS;
+	max_dist = suggs? best_distance((char **)suggs, word, len) : ENCHANT_PWL_MAX_ERRORS;
 	if(max_dist > ENCHANT_PWL_MAX_ERRORS)
 		max_dist = ENCHANT_PWL_MAX_ERRORS;
 
