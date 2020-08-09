From 9a818201243d9f4040807a0487f14ab08d7c24f5 Mon Sep 17 00:00:00 2001
From: Dmitriy Anisimkov <anisimko@adacore.com>
Date: Wed, 5 Feb 2020 15:58:58 +0600
Subject: [PATCH] Use GPR.Sinput.Reference_Name

T117-002

Prepare to hide Source_File table.

Change-Id: I3c7378061398e1e15c3a1ef18e25c525d437f4fe
---
 toolchains_editor/core/src/toolchains-parsers.adb | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

--- toolchains_editor/core/src/toolchains-parsers.adb
+++ toolchains_editor/core/src/toolchains-parsers.adb
@@ -672,7 +672,7 @@ package body Toolchains.Parsers is
       is
          Location : constant Source_Ptr := Location_Of (Node, Node_Data);
          File     : constant String := Get_Name_String
-           (Source_File.Table (Get_Source_File_Index (Location)).File_Name);
+           (Reference_Name (Get_Source_File_Index (Location)));
          Line     : constant Line_Number :=
            Get_Line_Number (Location);
          Col      : constant Column_Number := Get_Column_Number (Location);
