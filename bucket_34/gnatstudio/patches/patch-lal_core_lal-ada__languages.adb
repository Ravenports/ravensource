From 158d754604c284b4c23b4e4793ce969366a1dffb Mon Sep 17 00:00:00 2001
From: Anthony Leonardo Gracio <leonardo@.adacore.com>
Date: Fri, 29 Apr 2022 15:38:18 +0000
Subject: [PATCH] V429-030: Adapt to new Format_Vector API

Change-Id: I737ad812fc4c85617bb71fc49a3dde1547967b8e
---
 lal/core/lal-ada_languages.adb | 2 --
 1 file changed, 2 deletions(-)

--- lal/core/lal-ada_languages.adb.orig
+++ lal/core/lal-ada_languages.adb
@@ -130,9 +130,7 @@ package body LAL.Ada_Languages is
            (Cmd       => Lang.Pp_Command_Line,
             Input     => Input,
             Node      => Root,
-            In_Range  => From_Range,
             Output    => Output,
-            Out_Range => To_Range,
             Messages  => Errors);
       exception
          when E : others =>
