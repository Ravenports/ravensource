--- ad-indices.adb.orig	2021-09-04 16:03:27 UTC
+++ ad-indices.adb
@@ -41,13 +41,10 @@
 pragma License (GPL);
 
 with Ada.Characters.Handling;
-with Ada.Finalization;
-with Ada.Strings.Maps;
-with Ada.Strings.Unbounded;
 with Ada.Strings.Wide_Unbounded;
 with Ada.Unchecked_Deallocation;
+with System;
 
-with Asis;
 with Asis.Declarations;
 with Asis.Elements;
 
@@ -55,13 +52,10 @@ with Asis2.Declarations;
 with Asis2.Naming;
 with Asis2.Spans;
 
-with AD.Crossrefs;
 with AD.Exclusions;
-with AD.Expressions;
 with AD.Messages;
 with AD.Options;
 with AD.Predicates;
-with AD.Printers;
 with AD.Text_Utilities;
 
 with GAL.ADT.Hash_Tables;
@@ -625,8 +619,9 @@ package body AD.Indices is
             Quit : in out Boolean)
          is
             pragma Warnings (Off, Quit); --  silence -gnatwa
+	     use type System.Address;
          begin
-            if Item.all'Access /= Idx then
+            if Item.all'Address /= Idx.all'Address then
                AD.Printers.XRef_Index
                  (Printer,
                   ASU.To_String (Item.File_Name),
