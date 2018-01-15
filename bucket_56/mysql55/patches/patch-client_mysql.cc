--- client/mysql.cc.orig	2017-11-27 12:03:17 UTC
+++ client/mysql.cc
@@ -2671,7 +2671,7 @@ You can turn off this feature to get a q
         mysql_free_result(fields);
         break;
       }
-      field_names[i][num_fields*2]= '\0';
+      field_names[i][num_fields*2]= NULL;
       j=0;
       while ((sql_field=mysql_fetch_field(fields)))
       {
