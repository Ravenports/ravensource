--- ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py.orig	2026-11-17 21:34:47 UTC
+++ ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py
@@ -95,7 +95,7 @@ elif system == "Linux":
 
     info["os"] = "linux"
     info["linux_distro"] = distribution
-elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD"]:
+elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD", "MidnightBSD"]:
     info["os"] = "bsd"  # community builds
     version = os_version = sys.platform
 elif system == "Darwin":
