--- src/bootstrap/bootstrap.py.orig	2024-04-09 17:20:09 UTC
+++ src/bootstrap/bootstrap.py
@@ -265,6 +265,7 @@ def default_build_triple(verbose):
         'Darwin': 'apple-darwin',
         'DragonFly': 'unknown-dragonfly',
         'FreeBSD': 'unknown-freebsd',
+        'MidnightBSD': 'unknown-freebsd',
         'Haiku': 'unknown-haiku',
         'NetBSD': 'unknown-netbsd',
         'OpenBSD': 'unknown-openbsd',
