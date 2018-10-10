--- grub-core/fs/btrfs.c.orig	2018-10-07 17:22:25.917785000 +0200
+++ grub-core/fs/btrfs.c	2018-10-07 17:28:01.763075000 +0200
@@ -175,7 +175,7 @@
 {
   grub_int64_t sec;
   grub_uint32_t nanosec;
-} __attribute__ ((aligned (4)));
+} GRUB_PACKED;
 
 struct grub_btrfs_inode
 {
