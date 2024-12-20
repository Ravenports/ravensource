$NetBSD: patch-src_core_kmountpoint.cpp,v 1.1 2024/05/26 11:42:12 markd Exp $

statvfs has f_flag

--- src/core/kmountpoint.cpp.orig	2024-12-06 11:52:22 UTC
+++ src/core/kmountpoint.cpp
@@ -290,6 +290,7 @@ KMountPoint::List KMountPoint::currentMo
 
 #if GETMNTINFO_USES_STATVFS
     struct statvfs *mounted;
+#   define f_flags f_flag
 #else
     struct statfs *mounted;
 #endif
