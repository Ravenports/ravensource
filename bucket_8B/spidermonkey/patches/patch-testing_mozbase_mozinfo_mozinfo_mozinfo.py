--- ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py.orig	2023-09-12 04:32:33 UTC
+++ ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py
@@ -137,7 +137,7 @@ elif system == "Linux":
 
     info["os"] = "linux"
     info["linux_distro"] = distribution
-elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD"]:
+elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD", "MidnightBSD"]:
     info["os"] = "bsd"
     version = os_version = sys.platform
 elif system == "Darwin":
