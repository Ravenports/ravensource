--- lib/inc/internal/util/freebsd/geom.hpp.orig	2019-02-02 20:53:13 UTC
+++ lib/inc/internal/util/freebsd/geom.hpp
@@ -6,6 +6,7 @@
 
 #include <string>
 #include <vector>
+#include <stdexcept>
 
 #include <libgeom.h>
 
