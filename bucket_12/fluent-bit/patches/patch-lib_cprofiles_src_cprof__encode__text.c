--- lib/cprofiles/src/cprof_encode_text.c.orig	2024-11-27 17:22:52 UTC
+++ lib/cprofiles/src/cprof_encode_text.c
@@ -1909,7 +1909,7 @@ static int encode_cprof_resource_profile
                 struct cprof_resource_profiles *instance) {
     int result;
     struct cfl_list             *iterator;
-    struct cprof_scope_profile *scope_profile;
+    struct cprof_scope_profiles *scope_profiles;
 
     result = encode_string(context,
                             CFL_TRUE,
@@ -1958,11 +1958,11 @@ static int encode_cprof_resource_profile
 
         cfl_list_foreach(iterator,
                          &instance->scope_profiles) {
-            scope_profile = cfl_list_entry(
+            scope_profiles = cfl_list_entry(
                                 iterator,
                                 struct cprof_scope_profiles, _head);
 
-            result = encode_cprof_scope_profiles(context, scope_profile);
+            result = encode_cprof_scope_profiles(context, scope_profiles);
 
             if (result != CPROF_ENCODE_TEXT_SUCCESS) {
                 return result;
