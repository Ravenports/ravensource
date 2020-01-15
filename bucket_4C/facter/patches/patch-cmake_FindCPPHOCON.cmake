--- cmake/FindCPPHOCON.cmake.orig	2019-12-14 20:55:09 UTC
+++ cmake/FindCPPHOCON.cmake
@@ -1,5 +1,5 @@
 include(FindDependency)
-find_dependency(CPPHOCON DISPLAY "cpp-hocon" HEADERS "hocon/config.hpp" LIBRARIES "libcpp-hocon.a")
+find_dependency(CPPHOCON DISPLAY "cpp-hocon" HEADERS "hocon/config.hpp" LIBRARIES "liblibcpp-hocon.so")
 
 include(FeatureSummary)
 set_package_properties(CPPHOCON PROPERTIES DESCRIPTION "A C++ parser for the HOCON configuration language" URL "https://github.com/puppetlabs/cpp-hocon")
