--- deps/v8/third_party/abseil-cpp/absl/status/status.cc.orig	2025-07-15 17:11:19 UTC
+++ deps/v8/third_party/abseil-cpp/absl/status/status.cc
@@ -13,7 +13,7 @@
 // limitations under the License.
 #include "absl/status/status.h"
 
-#include <errno.h>
+#include <sys/errno.h>
 
 #include <atomic>
 #include <cstddef>
