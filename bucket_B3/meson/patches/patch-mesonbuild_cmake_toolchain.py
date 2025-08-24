--- mesonbuild/cmake/toolchain.py.orig	2025-08-24 17:28:31 UTC
+++ mesonbuild/cmake/toolchain.py
@@ -149,6 +149,7 @@ class CMakeToolchain:
             'linux': 'Linux',
             'windows': 'Windows',
             'freebsd': 'FreeBSD',
+            'midnightbsd': 'MidnightBSD',
             'darwin': 'Darwin',
         }
 
