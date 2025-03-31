--- cmake/VersionScript.cmake.orig	2020-08-09 18:42:53 UTC
+++ cmake/VersionScript.cmake
@@ -17,7 +17,7 @@
 #    misrepresented as being the original software.
 # 3. This notice may not be removed or altered from any source distribution.
 
-cmake_minimum_required(VERSION 2.8)
+cmake_minimum_required(VERSION 3.5)
 
 # CMake script that reads a VERSION file and the current git history and the calls configure_file().
 # This is used by version_file() in VersionString.cmake
