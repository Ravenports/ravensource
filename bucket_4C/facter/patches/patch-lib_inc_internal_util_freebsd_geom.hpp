--- lib/inc/internal/util/freebsd/geom.hpp.orig	2018-12-03 19:36:37 UTC
+++ lib/inc/internal/util/freebsd/geom.hpp
@@ -6,6 +6,7 @@
 
 #include <string>
 #include <vector>
+#include <stdexcept>
 
 #include <libgeom.h>
 
