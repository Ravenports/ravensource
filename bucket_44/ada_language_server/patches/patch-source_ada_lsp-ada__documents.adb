--- source/ada/lsp-ada_documents.adb.orig	2021-06-09 23:01:34 UTC
+++ source/ada/lsp-ada_documents.adb
@@ -1496,6 +1496,7 @@ package body LSP.Ada_Documents is
          Result  : VSS.Strings.Virtual_String;
          Params  : constant Param_Spec_Array := Node.P_Params;
          Returns : constant Type_Expr := Node.F_Subp_Returns;
+         retstr  : constant VSS.Strings.Virtual_String := VSS.Strings.Conversions.To_Virtual_String (" return ");
 
       begin
          if Params'Length > 0 then
@@ -1510,16 +1511,21 @@ package body LSP.Ada_Documents is
                Init  : constant Expr := Param.F_Default_Expr;
                Item  : VSS.Strings.Virtual_String;
 
+               s1 : constant VSS.Strings.Virtual_String := VSS.Strings.Conversions.To_Virtual_String (" in ");
+               s2 : constant VSS.Strings.Virtual_String := VSS.Strings.Conversions.To_Virtual_String (" in out ");
+               s3 : constant VSS.Strings.Virtual_String := VSS.Strings.Conversions.To_Virtual_String (" out "); 
+               s4 : constant VSS.Strings.Virtual_String := VSS.Strings.Conversions.To_Virtual_String (" := ");
             begin
-               Item.Append (" :");
+               Item.Append (' ');
+               Item.Append (':');
 
                case Param.F_Mode is
                   when Ada_Mode_Default | Ada_Mode_In =>
-                     Item.Append (" in ");
+                     Item.Append (s1);
                   when Ada_Mode_In_Out =>
-                     Item.Append (" in out ");
+                     Item.Append (s2);
                   when Ada_Mode_Out =>
-                     Item.Append (" out ");
+                     Item.Append (s3);
                end case;
 
                Item.Append
@@ -1527,14 +1533,15 @@ package body LSP.Ada_Documents is
                     (To_Text (Param.F_Type_Expr)));
 
                if not Init.Is_Null then
-                  Item.Append (" := ");
+                  Item.Append (s4);
                   Item.Append
                     (VSS.Strings.To_Virtual_String (To_Text (Init)));
                end if;
 
                for J in Names.First_Child_Index .. Names.Last_Child_Index loop
                   if Result.Character_Length /= 1 then
-                     Result.Append ("; ");
+                     Result.Append (';');
+                     Result.Append (' ');
                   end if;
 
                   Result.Append
@@ -1551,7 +1558,7 @@ package body LSP.Ada_Documents is
 
          if not Returns.Is_Null then
             Is_Function := True;
-            Result.Append (" return ");
+            Result.Append (retstr);
             Result.Append (VSS.Strings.To_Virtual_String (To_Text (Returns)));
          end if;
 
