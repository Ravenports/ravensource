--- ctags/main/portable-scandir.c.orig	2025-07-04 09:31:37 UTC
+++ ctags/main/portable-scandir.c
@@ -195,7 +195,11 @@ scandir(const char *directory_name,
                 return -1;
             }
             copy->d_ino = entry->d_ino;
+#if defined(__DragonFly__)
+            copy->d_namlen = entry->d_namlen;
+#else
             copy->d_reclen = entry->d_reclen;
+#endif
             strcpy(copy->d_name, entry->d_name);
 
             /* Save the copy.  */
