--- src/bootstrap/bootstrap.py.orig	2025-03-31 21:37:24 UTC
+++ src/bootstrap/bootstrap.py
@@ -317,6 +317,7 @@ def default_build_triple(verbose):
         "Darwin": "apple-darwin",
         "DragonFly": "unknown-dragonfly",
         "FreeBSD": "unknown-freebsd",
+        "MidnightBSD": "unknown-freebsd",
         "Haiku": "unknown-haiku",
         "NetBSD": "unknown-netbsd",
         "OpenBSD": "unknown-openbsd",
