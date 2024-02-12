--- src/bootstrap/bootstrap.py.orig	2024-02-04 13:18:05 UTC
+++ src/bootstrap/bootstrap.py
@@ -265,6 +265,7 @@ def default_build_triple(verbose):
         'Darwin': 'apple-darwin',
         'DragonFly': 'unknown-dragonfly',
         'FreeBSD': 'unknown-freebsd',
+        'MidnightBSD': 'unknown-freebsd',
         'Haiku': 'unknown-haiku',
         'NetBSD': 'unknown-netbsd',
         'OpenBSD': 'unknown-openbsd',
