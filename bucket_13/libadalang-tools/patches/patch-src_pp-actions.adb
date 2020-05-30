From fd784d6fdfbb7dcbcb9b23d8aff15a369f6cff06 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Romain=20B=C3=A9guet?= <beguet@adacore.com>
Date: Wed, 20 May 2020 14:23:33 +0200
Subject: [PATCH] Revert "Revert "T519-017: stub Ada 2020 handling""

This reverts commit ec9333afdabeb1caab038de10d2a615515baf4ab.
Stable branch is now bumped.

Change-Id: Ifde8a4ed00a67149be5b33c22dfedbc0e7318455
---
 src/pp-actions.adb | 8 ++++++++
 1 file changed, 8 insertions(+)

--- src/pp-actions.adb
+++ src/pp-actions.adb
@@ -614,6 +614,14 @@ package body Pp.Actions is
            when Ada_Prim_Type_Accessor => null,
             --  ???The above are not used
 
+           when Ada_Iterated_Assoc => null,
+           when Ada_Bracket_Aggregate => null,
+           when Ada_Bracket_Delta_Aggregate => null,
+           when Ada_Delta_Aggregate => null,
+           when Ada_Decl_Expr => null,
+           --  ??? Ada 2020 related expressions, needs to be implemented. See
+           --  T519-017.
+
            when Ada_Ada_List => null,
            when Ada_Subp_Spec => null,
            when Ada_Aggregate_Assoc => null,
