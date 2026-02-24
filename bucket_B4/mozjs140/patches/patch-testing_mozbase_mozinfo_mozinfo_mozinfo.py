--- ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py.orig	2026-02-13 16:59:15 UTC
+++ ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py
@@ -104,7 +104,7 @@ elif system == "Linux":
 
     info["os"] = "linux"
     info["linux_distro"] = distribution
-elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD"]:
+elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD", "MidnightBSD"]:
     info["os"] = "bsd"  # community builds
     version = os_version = sys.platform
 elif system == "Darwin":
