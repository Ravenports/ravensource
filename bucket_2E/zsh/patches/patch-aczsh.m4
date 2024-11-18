--- aczsh.m4.orig	2022-05-08 06:18:22 UTC
+++ aczsh.m4
@@ -44,7 +44,7 @@ AC_DEFUN(zsh_64_BIT_TYPE,
 #include <sys/types.h>
 #endif
 
-main()
+int main()
 {
   $1 foo = 0; 
   int bar = (int) foo;
@@ -146,7 +146,7 @@ char *zsh_gl_sym_addr ;
 #define RTLD_GLOBAL 0
 #endif
 
-main()
+int main()
 {
     void *handle1, *handle2;
     void *(*zsh_getaddr1)(), *(*zsh_getaddr2)();
@@ -229,7 +229,7 @@ char *zsh_gl_sym_addr ;
 #endif
 
 
-main()
+int main()
 {
     void *handle1, *handle2;
     int (*fred1)(), (*fred2)();
@@ -304,7 +304,7 @@ char *zsh_gl_sym_addr ;
 #define RTLD_GLOBAL 0
 #endif
 
-main()
+int main()
 {
     void *handle;
     int (*barneysym)();
@@ -374,7 +374,7 @@ char *zsh_gl_sym_addr ;
 #define RTLD_GLOBAL 0
 #endif
 
-main()
+int main()
 {
     void *handle;
     int (*barneysym)();
@@ -448,7 +448,7 @@ char *zsh_gl_sym_addr ;
 #define RTLD_GLOBAL 0
 #endif
 
-main()
+int main()
 {
     void *handle;
     int (*barneysym)();
@@ -516,7 +516,7 @@ char *zsh_gl_sym_addr ;
 #define RTLD_GLOBAL 0
 #endif
 
-main()
+int main()
 {
     void *handle;
     int (*fredsym)();
