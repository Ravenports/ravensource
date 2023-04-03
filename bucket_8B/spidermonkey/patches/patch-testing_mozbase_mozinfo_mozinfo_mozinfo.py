--- ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py.orig	2023-03-09 23:59:37 UTC
+++ ../../testing/mozbase/mozinfo/mozinfo/mozinfo.py
@@ -133,7 +133,7 @@ elif system == "Linux":
 
     info["os"] = "linux"
     info["linux_distro"] = distribution
-elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD"]:
+elif system in ["DragonFly", "FreeBSD", "NetBSD", "OpenBSD", "MidnightBSD"]:
     info["os"] = "bsd"
     version = os_version = sys.platform
 elif system == "Darwin":
