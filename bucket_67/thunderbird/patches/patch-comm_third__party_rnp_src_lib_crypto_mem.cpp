--- comm/third_party/rnp/src/lib/crypto/mem.cpp.orig	2026-03-26 02:21:02 UTC
+++ comm/third_party/rnp/src/lib/crypto/mem.cpp
@@ -25,6 +25,7 @@
  */
 
 #include <cstdio>
+#include <cstring>
 #include "mem.h"
 #include "logging.h"
 #include <botan/ffi.h>
@@ -65,4 +66,4 @@ hex_decode(const char *hex, uint8_t *buf
     }
     return buf_len;
 }
-} // namespace rnp
\ No newline at end of file
+} // namespace rnp
