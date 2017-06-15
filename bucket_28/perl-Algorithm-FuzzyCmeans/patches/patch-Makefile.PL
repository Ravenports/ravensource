--- Makefile.PL.orig	2009-10-02 12:05:15 UTC
+++ Makefile.PL
@@ -11,6 +11,5 @@ tests 't/*.t';
 author_tests 'xt';
 
 build_requires 'Test::More';
-use_test_base;
 auto_include;
 WriteAll;
