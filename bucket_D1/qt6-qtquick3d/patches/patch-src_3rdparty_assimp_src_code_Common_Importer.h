--- src/3rdparty/assimp/src/code/Common/Importer.h.orig	2021-06-18 13:08:36 UTC
+++ src/3rdparty/assimp/src/code/Common/Importer.h
@@ -44,6 +44,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 #ifndef INCLUDED_AI_IMPORTER_H
 #define INCLUDED_AI_IMPORTER_H
 
+#include <exception>
 #include <map>
 #include <vector>
 #include <string>
