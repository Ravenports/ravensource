--- sql/sql_acl.cc.orig	2017-03-18 06:43:12 UTC
+++ sql/sql_acl.cc
@@ -3530,7 +3530,7 @@ static int replace_user_table(THD *thd,
       * An empty password is considered to be of mysql_native type.
     */
     
-    if (combo->plugin.str == NULL || combo->plugin.str == '\0')
+    if (combo->plugin.str == NULL || *combo->plugin.str == '\0')
     {
       if (combo->uses_identified_by_password_clause)
       {
