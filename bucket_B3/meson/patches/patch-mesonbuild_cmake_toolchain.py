--- mesonbuild/cmake/toolchain.py.orig	2026-10-25 23:27:56 UTC
+++ mesonbuild/cmake/toolchain.py
@@ -149,6 +149,7 @@ class CMakeToolchain:
             'linux': 'Linux',
             'windows': 'Windows',
             'freebsd': 'FreeBSD',
+            'midnightbsd': 'MidnightBSD',
             'darwin': 'Darwin',
         }
 
