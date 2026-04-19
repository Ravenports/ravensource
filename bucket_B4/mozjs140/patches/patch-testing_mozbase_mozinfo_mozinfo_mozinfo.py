--- ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py.orig	2026-03-17 09:42:17.000000000 -0000
+++ ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py
@@ -104,7 +104,7 @@ elif system == "Linux":
 
     info["os"] = "linux"
     info["linux_distro"] = distribution
-elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD"]:
+elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD", "MidnightBSD"]:
     info["os"] = "bsd"  # community builds
     version = os_version = sys.platform
 elif system == "Darwin":
