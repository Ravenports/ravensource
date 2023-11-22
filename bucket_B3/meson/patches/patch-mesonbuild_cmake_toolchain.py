--- mesonbuild/cmake/toolchain.py.orig	2023-10-26 16:04:24 UTC
+++ mesonbuild/cmake/toolchain.py
@@ -158,6 +158,7 @@ class CMakeToolchain:
             'linux': 'Linux',
             'windows': 'Windows',
             'freebsd': 'FreeBSD',
+            'midnightbsd': 'MidnightBSD',
             'darwin': 'Darwin',
         }
 
