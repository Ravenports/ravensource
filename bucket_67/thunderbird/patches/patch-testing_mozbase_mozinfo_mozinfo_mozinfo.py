--- testing/mozbase/mozinfo/mozinfo/mozinfo.py.orig	2025-05-12 17:23:32 UTC
+++ testing/mozbase/mozinfo/mozinfo/mozinfo.py
@@ -103,7 +103,7 @@ elif system == "Linux":
 
     info["os"] = "linux"
     info["linux_distro"] = distribution
-elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD"]:
+elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD", "MidnightBSD"]:
     info["os"] = "bsd"  # community builds
     version = os_version = sys.platform
 elif system == "Darwin":
