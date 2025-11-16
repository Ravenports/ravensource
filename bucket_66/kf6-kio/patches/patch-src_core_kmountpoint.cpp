$NetBSD: patch-src_core_kmountpoint.cpp,v 1.1 2024/05/26 11:42:12 markd Exp $

statvfs has f_flag

--- src/core/kmountpoint.cpp.orig	2025-11-13 21:10:07 UTC
+++ src/core/kmountpoint.cpp
@@ -298,6 +298,7 @@ KMountPoint::List KMountPoint::currentMo
 
 #if GETMNTINFO_USES_STATVFS
     struct statvfs *mounted;
+#   define f_flags f_flag
 #else
     struct statfs *mounted;
 #endif
