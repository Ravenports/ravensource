* Skip the detection of root rights requirement, the assumption that presence
* of KMS drivers removes the root requirement is only valid for Linux

--- hw/xfree86/xorg-wrapper.c.orig	2024-10-29 16:09:01 UTC
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
@@ -191,7 +191,7 @@ static int on_console(int fd)
 
 int main(int argc, char *argv[])
 {
-#ifdef WITH_LIBDRM
+#if defined(WITH_LIBDRM) && defined(__linux__)
     struct drm_mode_card_res res;
 #endif
     char buf[PATH_MAX];
@@ -230,7 +230,7 @@ int main(int argc, char *argv[])
         }
     }
 
-#ifdef WITH_LIBDRM
+#if defined(WITH_LIBDRM) && defined(__linux__)
     /* Detect if we need root rights, except when overridden by the config */
     if (needs_root_rights == -1) {
         for (i = 0; i < 16; i++) {
@@ -256,6 +256,8 @@ int main(int argc, char *argv[])
         gid_t realgid = getgid();
         uid_t realuid = getuid();
 
+#if !defined(__NetBSD__)
+	/* setresgid and setresuid are not implemented on NetBSD */
         if (setresgid(-1, realgid, realgid) != 0) {
             fprintf(stderr, "%s: Could not drop setgid privileges: %s\n",
                 progname, strerror(errno));
@@ -266,6 +268,7 @@ int main(int argc, char *argv[])
                 progname, strerror(errno));
             exit(1);
         }
+#endif
     }
 
     snprintf(buf, sizeof(buf), "%s/Xorg", SUID_WRAPPER_DIR);
