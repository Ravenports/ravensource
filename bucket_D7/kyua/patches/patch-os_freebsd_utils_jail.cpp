--- os/freebsd/utils/jail.cpp.orig	2025-03-29 21:43:20 UTC
+++ os/freebsd/utils/jail.cpp
@@ -27,6 +27,7 @@
 // OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 #include "os/freebsd/utils/jail.hpp"
+#include <cstring>
 
 extern "C" {
 #include <limits.h>
