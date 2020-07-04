--- recursiv.c.orig	2020-06-07 11:05:54.474327000 +0200
+++ recursiv.c	2020-06-07 11:06:12.324073000 +0200
@@ -76,10 +76,6 @@
 #define S_ISDIR(mode) (0040000&(mode))
 #endif
 
-/* TG 28.04.04 */
-#define S_IFDIR __S_IFDIR
-#define S_IFMT __S_IFMT
-
 char *file_list[max_list*2];
 int  fdx=0; /* index of file_List */
 extern int Numfiles;
