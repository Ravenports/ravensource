--- Makefile.PL.orig	2009-10-07 14:06:37 UTC
+++ Makefile.PL
@@ -10,6 +10,5 @@ tests 't/*.t';
 author_tests 'xt';
 
 build_requires 'Test::More';
-use_test_base;
 auto_include;
 WriteAll;
