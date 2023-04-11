--- hw/xfree86/xorg-wrapper.c.orig	2023-03-29 12:55:03 UTC
+++ hw/xfree86/xorg-wrapper.c
@@ -39,7 +39,7 @@
 #include <sys/sysmacros.h>
 #endif
 #include <sys/types.h>
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 #include <sys/consio.h>
 #endif
 #include <unistd.h>
@@ -170,7 +170,7 @@ static int on_console(int fd)
     r = fstat(fd, &st);
     if (r == 0 && S_ISCHR(st.st_mode) && major(st.st_rdev) == 4)
       return 1;
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
     int idx;
 
     if (ioctl(fd, VT_GETINDEX, &idx) != -1)
@@ -230,6 +230,7 @@ int main(int argc, char *argv[])
         }
     }
 
+#if !defined(__DragonFly__)
 #ifdef WITH_LIBDRM
     /* Detect if we need root rights, except when overridden by the config */
     if (needs_root_rights == -1) {
@@ -250,6 +251,7 @@ int main(int argc, char *argv[])
         }
     }
 #endif
+#endif
 
     /* If we've found cards, and all cards support kms, drop root rights */
     if (needs_root_rights == 0 || (total_cards && kms_cards == total_cards)) {
