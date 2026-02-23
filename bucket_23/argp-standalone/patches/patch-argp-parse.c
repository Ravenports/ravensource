--- argp-parse.c.orig	2022-05-03 07:41:05 UTC
+++ argp-parse.c
@@ -1229,8 +1229,8 @@ __argp_parse(
     if (!(flags & ARGP_NO_HELP))
     /* Add our own options.  */
     {
-        struct argp_child* child = alloca(4 * sizeof(struct argp_child));
-        struct argp* top_argp = alloca(sizeof(struct argp));
+        struct argp_child* child = __builtin_alloca(4 * sizeof(struct argp_child));
+        struct argp* top_argp = __builtin_alloca(sizeof(struct argp));
 
         /* TOP_ARGP has no options, it just serves to group the user & default
      argps.  */
