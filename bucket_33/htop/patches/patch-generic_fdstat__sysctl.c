--- generic/fdstat_sysctl.c.orig	2024-01-10 09:54:15 UTC
+++ generic/fdstat_sysctl.c
@@ -65,9 +65,9 @@ void Generic_getFileDescriptors_sysctl(d
 #if defined(HTOP_DARWIN)
    Generic_getFileDescriptors_sysctl_internal(
       "kern.maxfiles", "kern.num_files", 0, 0, used, max);
-#elif defined(HTOP_DRAGONFLY)
+#elif defined(HTOP_DRAGONFLYBSD)
    Generic_getFileDescriptors_sysctl_internal(
-      "kern.maxfiles", NULL, 0, sizeof(struct kinfo_file), used, max);
+      "kern.maxfiles", "kern.openfiles", 0, 0, used, max);
 #elif defined(HTOP_FREEBSD)
    Generic_getFileDescriptors_sysctl_internal(
       "kern.maxfiles", "kern.openfiles", 0, 0, used, max);
