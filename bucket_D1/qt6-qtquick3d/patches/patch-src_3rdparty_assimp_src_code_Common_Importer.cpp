--- src/3rdparty/assimp/src/code/Common/Importer.cpp.orig	2021-08-27 08:22:22 UTC
+++ src/3rdparty/assimp/src/code/Common/Importer.cpp
@@ -78,6 +78,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 #include <assimp/Profiler.h>
 #include <assimp/commonMetaData.h>
 
+#include <exception>
 #include <set>
 #include <memory>
 #include <cctype>
