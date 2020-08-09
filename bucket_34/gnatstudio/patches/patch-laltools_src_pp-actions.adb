--- laltools/src/pp-actions.adb.orig	2020-01-22 06:48:11 UTC
+++ laltools/src/pp-actions.adb
@@ -614,6 +614,12 @@ package body Pp.Actions is
            when Ada_Prim_Type_Accessor => null,
             --  ???The above are not used
 
+           when Ada_Iterated_Assoc => null,
+           when Ada_Bracket_Aggregate => null,
+           when Ada_Bracket_Delta_Aggregate => null,
+           when Ada_Delta_Aggregate => null,
+           when Ada_Decl_Expr => null,
+
            when Ada_Ada_List => null,
            when Ada_Subp_Spec => null,
            when Ada_Aggregate_Assoc => null,
@@ -747,6 +753,7 @@ package body Pp.Actions is
            when Ada_Number_Decl =>
              L ("?~,# ~~ ^: constant ^2:=[# !]"),
            when Ada_Object_Decl |
+               Ada_Anonymous_Object_Decl |
                Ada_Extended_Return_Stmt_Object_Decl =>
              L ("?~,# ~~ ^:? ~~~? ~~~? ~~~ !? ^2:=[# ~~]~!", Aspects),
            when Ada_Package_Renaming_Decl =>
@@ -881,7 +888,7 @@ package body Pp.Actions is
            when Ada_Pragma_Argument_Assoc => null,
            when Ada_Pragma_Node => null,
            when Ada_Component_Clause => null, -- ?
-           when Ada_Renaming_Clause =>
+           when Ada_Renaming_Clause | Ada_Synthetic_Renaming_Clause =>
              L ("? renames[# ~~]~"),
            when Ada_Select_Stmt =>
              L ("select",
