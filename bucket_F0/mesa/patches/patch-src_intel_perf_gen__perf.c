$NetBSD: patch-src_intel_perf_gen__perf.c,v 1.1 2019/08/24 20:11:19 nia Exp $

SunOS does not have d_type in DIR structure.

--- src/intel/perf/gen_perf.c.orig	2019-11-20 16:57:32 UTC
+++ src/intel/perf/gen_perf.c
@@ -394,6 +394,9 @@ get_sysfs_dev_dir(struct gen_perf_config
    DIR *drmdir;
    struct dirent *drm_entry;
    int len;
+#ifdef __sun
+   struct stat s;
+#endif
 
    perf->sysfs_dev_dir[0] = '\0';
 
@@ -425,8 +428,14 @@ get_sysfs_dev_dir(struct gen_perf_config
    }
 
    while ((drm_entry = readdir(drmdir))) {
+#ifdef __sun
+      stat(drm_entry->d_name, &s);
+      if ((s.st_mode == S_IFDIR ||
+           s.st_mode == S_IFLNK) &&
+#else
       if ((drm_entry->d_type == DT_DIR ||
            drm_entry->d_type == DT_LNK) &&
+#endif
           strncmp(drm_entry->d_name, "card", 4) == 0)
       {
          len = snprintf(perf->sysfs_dev_dir,
@@ -527,6 +536,9 @@ enumerate_sysfs_metrics(struct gen_perf_
    struct dirent *metric_entry;
    char buf[256];
    int len;
+#ifdef __sun
+   struct stat s;
+#endif
 
    len = snprintf(buf, sizeof(buf), "%s/metrics", perf->sysfs_dev_dir);
    if (len < 0 || len >= sizeof(buf)) {
@@ -543,8 +555,14 @@ enumerate_sysfs_metrics(struct gen_perf_
    while ((metric_entry = readdir(metricsdir))) {
       struct hash_entry *entry;
 
+#ifdef __sun
+      stat(metric_entry->d_name, &s);
+      if ((s.st_mode != S_IFDIR &&
+           s.st_mode != S_IFLNK) ||
+#else
       if ((metric_entry->d_type != DT_DIR &&
            metric_entry->d_type != DT_LNK) ||
+#endif
           metric_entry->d_name[0] == '.')
          continue;
 
