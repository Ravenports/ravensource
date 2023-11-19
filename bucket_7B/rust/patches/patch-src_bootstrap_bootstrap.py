--- src/bootstrap/bootstrap.py.orig	2023-11-13 04:10:51 UTC
+++ src/bootstrap/bootstrap.py
@@ -265,6 +265,7 @@ def default_build_triple(verbose):
         'Darwin': 'apple-darwin',
         'DragonFly': 'unknown-dragonfly',
         'FreeBSD': 'unknown-freebsd',
+        'MidnightBSD': 'unknown-freebsd',
         'Haiku': 'unknown-haiku',
         'NetBSD': 'unknown-netbsd',
         'OpenBSD': 'unknown-openbsd',
