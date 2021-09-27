--- src/3rdparty/assimp/src/include/assimp/Importer.hpp.orig	2021-08-27 08:22:22 UTC
+++ src/3rdparty/assimp/src/include/assimp/Importer.hpp
@@ -59,6 +59,8 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 // Public ASSIMP data structures
 #include <assimp/types.h>
 
+#include <exception>
+
 namespace Assimp {
 // =======================================================================
 // Public interface to Assimp
