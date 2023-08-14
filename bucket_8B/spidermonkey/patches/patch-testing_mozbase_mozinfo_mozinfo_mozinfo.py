--- ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py.orig	2023-07-24 16:54:16 UTC
+++ ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py
@@ -137,7 +137,7 @@ elif system == "Linux":
 
     info["os"] = "linux"
     info["linux_distro"] = distribution
-elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD"]:
+elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD", "MidnightBSD"]:
     info["os"] = "bsd"
     version = os_version = sys.platform
 elif system == "Darwin":
