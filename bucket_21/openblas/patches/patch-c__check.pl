--- c_check.pl.orig	2026-04-23 11:50:46 UTC
+++ c_check.pl
@@ -401,7 +401,7 @@ $linker_a = "";
 {
     $link = `$compiler_name $flags -c ctest2.c -o ctest2.o 2>&1 && $compiler_name $flags $openmp -v ctest2.o -o ctest2 2>&1 && rm -f ctest2.o ctest2 ctest2.exe`;
 
-    $link =~ s/\-Y\sP\,/\-Y/g;
+    $link =~ s/-Y\s*P,[^\s]*//g;
 
     @flags = split(/[\s\,\n]/, $link);
     # remove leading and trailing quotes from each flag.
