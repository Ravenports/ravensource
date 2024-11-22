--- lib/cprofiles/src/cprof_profile.c.orig	2024-11-17 03:19:24 UTC
+++ lib/cprofiles/src/cprof_profile.c
@@ -98,7 +98,7 @@ void cprof_profile_destroy(struct cprof_
     struct cfl_list             *iterator_backup;
     struct cprof_attribute_unit *attribute_unit;
     struct cprof_value_type     *value_type;
-    struct cprof_mapping        *location;
+    struct cprof_location       *location;
     struct cprof_function       *function;
     struct cfl_list             *iterator;
     struct cprof_mapping        *mapping;
@@ -307,4 +307,4 @@ int cprof_profile_add_comment(struct cpr
     profile->comments_count++;
 
     return 0;
-}
\ No newline at end of file
+}
