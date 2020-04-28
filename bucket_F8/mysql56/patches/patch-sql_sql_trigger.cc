--- sql/sql_trigger.cc.orig	2020-03-09 10:37:59 UTC
+++ sql/sql_trigger.cc
@@ -199,32 +199,32 @@ static File_option triggers_file_paramet
 {
   {
     { C_STRING_WITH_LEN("triggers") },
-    my_offsetof(class Table_triggers_list, definitions_list),
+    static_cast<int>(my_offsetof(class Table_triggers_list, definitions_list)),
     FILE_OPTIONS_STRLIST
   },
   {
     { C_STRING_WITH_LEN("sql_modes") },
-    my_offsetof(class Table_triggers_list, definition_modes_list),
+    static_cast<int>(my_offsetof(class Table_triggers_list, definition_modes_list)),
     FILE_OPTIONS_ULLLIST
   },
   {
     { C_STRING_WITH_LEN("definers") },
-    my_offsetof(class Table_triggers_list, definers_list),
+    static_cast<int>(my_offsetof(class Table_triggers_list, definers_list)),
     FILE_OPTIONS_STRLIST
   },
   {
     { C_STRING_WITH_LEN("client_cs_names") },
-    my_offsetof(class Table_triggers_list, client_cs_names),
+    static_cast<int>(my_offsetof(class Table_triggers_list, client_cs_names)),
     FILE_OPTIONS_STRLIST
   },
   {
     { C_STRING_WITH_LEN("connection_cl_names") },
-    my_offsetof(class Table_triggers_list, connection_cl_names),
+    static_cast<int>(my_offsetof(class Table_triggers_list, connection_cl_names)),
     FILE_OPTIONS_STRLIST
   },
   {
     { C_STRING_WITH_LEN("db_cl_names") },
-    my_offsetof(class Table_triggers_list, db_cl_names),
+    static_cast<int>(my_offsetof(class Table_triggers_list, db_cl_names)),
     FILE_OPTIONS_STRLIST
   },
   { { 0, 0 }, 0, FILE_OPTIONS_STRING }
@@ -233,7 +233,7 @@ static File_option triggers_file_paramet
 File_option sql_modes_parameters=
 {
   { C_STRING_WITH_LEN("sql_modes") },
-  my_offsetof(class Table_triggers_list, definition_modes_list),
+  static_cast<int>(my_offsetof(class Table_triggers_list, definition_modes_list)),
   FILE_OPTIONS_ULLLIST
 };
 
