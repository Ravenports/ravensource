--- protolib/src/common/protoFile.cpp.orig	2018-07-20 22:12:15 UTC
+++ protolib/src/common/protoFile.cpp
@@ -13,7 +13,7 @@
 #include <unistd.h>
 // Most don't have the dirfd() function
 #ifndef HAVE_DIRFD
-static inline int dirfd(DIR *dir) {return (dir->dd_fd);}
+static inline int dirfd(DIR *dir) {return (dir->d_fd);}
 #endif // HAVE_DIRFD    
 #endif // if/else WIN32
 
