--- modules/filter/tex.cpp.orig	2011-07-02 21:09:09 UTC
+++ modules/filter/tex.cpp
@@ -174,7 +174,7 @@ namespace {
 
     if (c == '{') {
 
-      if (top.in_what == Parm || top.in_what == Opt || top.do_check == '\0')
+      if (top.in_what == Parm || top.in_what == Opt || *top.do_check == '\0')
 	push_command(Parm);
 
       top.in_what = Parm;
