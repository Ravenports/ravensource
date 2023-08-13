--- toolkit/components/telemetry/pingsender/pingsender.cpp.orig	2023-07-07 14:39:18 UTC
+++ toolkit/components/telemetry/pingsender/pingsender.cpp
@@ -4,6 +4,7 @@
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 #include <cstdlib>
+#include <cstdint>
 #include <cstring>
 #include <ctime>
 #include <fstream>
