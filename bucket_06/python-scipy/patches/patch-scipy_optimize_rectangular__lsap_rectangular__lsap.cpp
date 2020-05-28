--- scipy/optimize/rectangular_lsap/rectangular_lsap.cpp.orig	2019-12-13 00:12:50 UTC
+++ scipy/optimize/rectangular_lsap/rectangular_lsap.cpp
@@ -43,6 +43,7 @@ Author: PM Larsen
 #include <algorithm>
 #include <cmath>
 #include <vector>
+#include <cstdint>
 
 static int
 augmenting_path(int nc, std::vector<double>& cost, std::vector<double>& u,
