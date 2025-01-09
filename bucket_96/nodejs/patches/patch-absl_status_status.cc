--- deps/v8/third_party/abseil-cpp/absl/status/status.cc.orig	2025-01-07 13:00:24 UTC
+++ deps/v8/third_party/abseil-cpp/absl/status/status.cc
@@ -13,7 +13,7 @@
 // limitations under the License.
 #include "absl/status/status.h"
 
-#include <errno.h>
+#include <sys/errno.h>
 
 #include <atomic>
 #include <cstddef>
