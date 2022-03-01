--- lib/tests/main.cc.orig	2020-06-22 13:08:22 UTC
+++ lib/tests/main.cc
@@ -1,4 +1,5 @@
 #define CATCH_CONFIG_RUNNER
+#include <signal.h>
 #include <catch.hpp>
 
 int main(int argc, char **argv)
