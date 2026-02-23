--- argp-help.c.orig	2022-05-03 07:41:05 UTC
+++ argp-help.c
@@ -1330,7 +1330,7 @@ hol_usage(struct hol* hol, argp_fmtstrea
     {
         unsigned nentries;
         struct hol_entry* entry;
-        char* short_no_arg_opts = alloca(strlen(hol->short_options) + 1);
+        char* short_no_arg_opts = __builtin_alloca(strlen(hol->short_options) + 1);
         char* snao_end = short_no_arg_opts;
 
         /* First we put a list of short options without arguments.  */
@@ -1597,7 +1597,7 @@ _help(const struct argp* argp,
     {
         int first_pattern = 1, more_patterns;
         size_t num_pattern_levels = argp_args_levels(argp);
-        char* pattern_levels = alloca(num_pattern_levels);
+        char* pattern_levels = __builtin_alloca(num_pattern_levels);
 
         memset(pattern_levels, 0, num_pattern_levels);
 
