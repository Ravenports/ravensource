--- ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py.orig	2024-11-28 18:48:51 UTC
+++ ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py
@@ -106,7 +106,7 @@ elif system == "Linux":
 
     info["os"] = "linux"
     info["linux_distro"] = distribution
-elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD"]:
+elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD", "MidnightBSD"]:
     info["os"] = "bsd"
     version = os_version = sys.platform
 elif system == "Darwin":
