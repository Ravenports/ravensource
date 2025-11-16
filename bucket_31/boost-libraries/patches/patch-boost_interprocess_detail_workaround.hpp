--- boost/interprocess/detail/workaround.hpp.orig	2025-08-06 18:49:10 UTC
+++ boost/interprocess/detail/workaround.hpp
@@ -170,7 +170,7 @@
    //////////////////////////////////////////////////////
    //posix_fallocate
    //////////////////////////////////////////////////////
-   #if (_XOPEN_SOURCE >= 600 || _POSIX_C_SOURCE >= 200112L)
+   #if !defined __sun && (_XOPEN_SOURCE >= 600 || _POSIX_C_SOURCE >= 200112L)
    #define BOOST_INTERPROCESS_POSIX_FALLOCATE
    #endif
 
