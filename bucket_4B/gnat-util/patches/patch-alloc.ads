--- alloc.ads.orig
+++ alloc.ads
@@ -116,6 +116,9 @@ package Alloc is
    Rep_Table_Initial                : constant := 1000;       -- Repinfo
    Rep_Table_Increment              : constant := 200;
 
+   Rep_JSON_Table_Initial           : constant := 10;          -- Repinfo
+   Rep_JSON_Table_Increment         : constant := 200;
+
    Scope_Stack_Initial              : constant := 10;         -- Sem
    Scope_Stack_Increment            : constant := 200;
