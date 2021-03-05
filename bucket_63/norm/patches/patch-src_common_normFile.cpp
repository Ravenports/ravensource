--- src/common/normFile.cpp.orig	2021-03-05 19:54:19 UTC
+++ src/common/normFile.cpp
@@ -13,7 +13,11 @@
 #include <unistd.h>
 // Most don't have the dirfd() function
 #ifndef HAVE_DIRFD
+# ifdef __sun
+static inline int dirfd(DIR *dir) {return (dir->d_fd);}
+# else
 static inline int dirfd(DIR *dir) {return (dir->dd_fd);}
+# endif
 #endif // HAVE_DIRFD    
 #endif // if/else WIN32
 
