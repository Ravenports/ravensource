--- ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py.orig	2025-09-22 21:16:17 UTC
+++ ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py
@@ -104,7 +104,7 @@ elif system == "Linux":
 
     info["os"] = "linux"
     info["linux_distro"] = distribution
-elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD"]:
+elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD", "MidnightBSD"]:
     info["os"] = "bsd"  # community builds
     version = os_version = sys.platform
 elif system == "Darwin":
