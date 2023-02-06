--- cmake/FindHUNSPELL.cmake.orig	2023-01-11 22:49:57 UTC
+++ cmake/FindHUNSPELL.cmake
@@ -17,7 +17,7 @@ find_path(HUNSPELL_INCLUDE_DIRS
           HINTS ${PKG_HUNSPELL_INCLUDE_DIRS}
 )
 find_library(HUNSPELL_LIBRARIES
-             NAMES ${PKG_HUNSPELL_LIBRARIES} hunspell hunspell-1.6 hunspell-1.5 hunspell-1.4 hunspell-1.3 hunspell-1.2 libhunspell
+             NAMES ${PKG_HUNSPELL_LIBRARIES} hunspell hunspell-1.7 hunspell-1.6 hunspell-1.5 hunspell-1.4 hunspell-1.3 hunspell-1.2 libhunspell
              HINTS ${PKG_HUNSPELL_LIBRARY_DIRS}
 )
 
