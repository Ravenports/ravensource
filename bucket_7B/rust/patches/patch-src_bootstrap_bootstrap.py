--- src/bootstrap/bootstrap.py.orig	2026-05-25 23:21:07 UTC
+++ src/bootstrap/bootstrap.py
@@ -324,6 +324,7 @@ def default_build_triple(verbose):
         "Darwin": "apple-darwin",
         "DragonFly": "unknown-dragonfly",
         "FreeBSD": "unknown-freebsd",
+        "MidnightBSD": "unknown-freebsd",
         "Haiku": "unknown-haiku",
         "NetBSD": "unknown-netbsd",
         "OpenBSD": "unknown-openbsd",
