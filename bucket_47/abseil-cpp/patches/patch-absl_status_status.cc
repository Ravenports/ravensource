--- absl/status/status.cc.orig	2023-08-07 18:40:00 UTC
+++ absl/status/status.cc
@@ -13,7 +13,7 @@
 // limitations under the License.
 #include "absl/status/status.h"
 
-#include <errno.h>
+#include <sys/errno.h>
 
 #include <cassert>
 #include <utility>
@@ -464,15 +464,19 @@ StatusCode ErrnoToStatusCode(int error_n
     case EFAULT:        // Bad address
     case EILSEQ:        // Illegal byte sequence
     case ENOPROTOOPT:   // Protocol not available
+#ifdef ENOSTR
     case ENOSTR:        // Not a STREAM
+#endif
     case ENOTSOCK:      // Not a socket
     case ENOTTY:        // Inappropriate I/O control operation
     case EPROTOTYPE:    // Protocol wrong type for socket
     case ESPIPE:        // Invalid seek
       return StatusCode::kInvalidArgument;
     case ETIMEDOUT:  // Connection timed out
+#ifdef ETIME
     case ETIME:      // Timer expired
       return StatusCode::kDeadlineExceeded;
+#endif
     case ENODEV:  // No such device
     case ENOENT:  // No such file or directory
 #ifdef ENOMEDIUM
@@ -530,9 +534,13 @@ StatusCode ErrnoToStatusCode(int error_n
     case EMLINK:   // Too many links
     case ENFILE:   // Too many open files in system
     case ENOBUFS:  // No buffer space available
+#ifdef ENODATA
     case ENODATA:  // No message is available on the STREAM read queue
+#endif
     case ENOMEM:   // Not enough space
+#ifdef ENOSR
     case ENOSR:    // No STREAM resources
+#endif
 #ifdef EUSERS
     case EUSERS:  // Too many users
 #endif
