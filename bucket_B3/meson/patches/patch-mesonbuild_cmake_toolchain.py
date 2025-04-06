--- mesonbuild/cmake/toolchain.py.orig	2025-04-06 19:57:59 UTC
+++ mesonbuild/cmake/toolchain.py
@@ -148,6 +148,7 @@ class CMakeToolchain:
             'linux': 'Linux',
             'windows': 'Windows',
             'freebsd': 'FreeBSD',
+            'midnightbsd': 'MidnightBSD',
             'darwin': 'Darwin',
         }
 
