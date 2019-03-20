--- mdepend.cpp.orig	2019-03-16 23:26:24 UTC
+++ mdepend.cpp
@@ -125,9 +125,6 @@ do
 			    shift
 			    ;;
 
-			# Flag to tell compiler to output dependencies directly
-			# For example, with Sun compilers, -xM or -xM1 or
-			# with gcc, -M
 		        -d)
 			    compilerlistsdepends="y"
 			    compilerlistdependsflag="$2"
