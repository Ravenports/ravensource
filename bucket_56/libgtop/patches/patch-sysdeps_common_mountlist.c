--- sysdeps/common/mountlist.c.orig	2019-02-04 20:15:22 UTC
+++ sysdeps/common/mountlist.c
@@ -106,7 +106,7 @@ static struct mount_entry *read_filesyst
 #endif
 
 
-#if defined (MOUNTED_GETMNTINFO) && !defined (__NetBSD__) && !defined (__OpenBSD__) && !defined(__FreeBSD__)
+#if defined (MOUNTED_GETMNTINFO) && !defined (__NetBSD__) && !defined (__OpenBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 static const char *
 fstype_to_string (short t)
 {
@@ -298,7 +298,11 @@ read_filesystem_list (void)
 
 #ifdef MOUNTED_GETMNTINFO	/* 4.4BSD.  */
   {
+#if defined(STAT_STATVFS) && !defined(__DragonFly__)
+    struct statvfs *fsp;
+#else
     struct statfs *fsp;
+#endif
     int entries;
 
     entries = getmntinfo (&fsp, MNT_NOWAIT);
@@ -309,7 +313,7 @@ read_filesystem_list (void)
 	me = (struct mount_entry *) g_malloc (sizeof (struct mount_entry));
 	me->me_devname = g_strdup (fsp->f_mntfromname);
 	me->me_mountdir = g_strdup (fsp->f_mntonname);
-#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 	me->me_type = g_strdup (fsp->f_fstypename);
 #else
 	me->me_type = g_strdup (fstype_to_string (fsp->f_type));
