--- boost/interprocess/detail/workaround.hpp.orig	2026-08-05 17:09:10 UTC
+++ boost/interprocess/detail/workaround.hpp
@@ -178,9 +178,11 @@
    //////////////////////////////////////////////////////
    //posix_fallocate
    //////////////////////////////////////////////////////
+# if !defined __sun
    #if ( defined(_XOPEN_SOURCE) && (_XOPEN_SOURCE >= 600) ) || ( defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200112L) )
    #define BOOST_INTERPROCESS_POSIX_FALLOCATE
    #endif
+# endif
 
 #endif   //!defined(BOOST_INTERPROCESS_WINDOWS)
 
