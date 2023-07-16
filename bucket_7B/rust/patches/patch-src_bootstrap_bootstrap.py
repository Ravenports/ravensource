--- src/bootstrap/bootstrap.py.orig	2023-07-12 03:32:40 UTC
+++ src/bootstrap/bootstrap.py
@@ -264,6 +264,7 @@ def default_build_triple(verbose):
         'Darwin': 'apple-darwin',
         'DragonFly': 'unknown-dragonfly',
         'FreeBSD': 'unknown-freebsd',
+        'MidnightBSD': 'unknown-freebsd',
         'Haiku': 'unknown-haiku',
         'NetBSD': 'unknown-netbsd',
         'OpenBSD': 'unknown-openbsd'
