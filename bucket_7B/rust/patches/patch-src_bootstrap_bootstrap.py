--- src/bootstrap/bootstrap.py.orig	2025-10-28 16:34:16 UTC
+++ src/bootstrap/bootstrap.py
@@ -324,6 +324,7 @@ def default_build_triple(verbose):
         "Darwin": "apple-darwin",
         "DragonFly": "unknown-dragonfly",
         "FreeBSD": "unknown-freebsd",
+        "MidnightBSD": "unknown-freebsd",
         "Haiku": "unknown-haiku",
         "NetBSD": "unknown-netbsd",
         "OpenBSD": "unknown-openbsd",
