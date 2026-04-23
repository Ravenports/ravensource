$NetBSD: patch-hacks_glx_xshadertoy-compile.pl,v 1.1 2026/01/16 14:53:05 hauke Exp $

Supply the correct path to bash(1).

--- hacks/glx/xshadertoy-compile.pl.orig	2026-03-09 23:22:51 UTC
+++ hacks/glx/xshadertoy-compile.pl
@@ -111,7 +111,7 @@ sub compile($@) {
   $title =~ s@^.*/@@gs;
 
   my $year = (localtime)[5] + 1900;
-  my $head = '#!/bin/bash
+  my $head = '#!@BASH@
 # XScreenSaver, Copyright © ' . $year . ' Jamie Zawinski <jwz@jwz.org>
 #
 # Permission to use, copy, modify, distribute, and sell this software and its
