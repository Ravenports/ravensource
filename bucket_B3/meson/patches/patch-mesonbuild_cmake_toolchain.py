--- mesonbuild/cmake/toolchain.py.orig	2024-02-26 20:51:28 UTC
+++ mesonbuild/cmake/toolchain.py
@@ -148,6 +148,7 @@ class CMakeToolchain:
             'linux': 'Linux',
             'windows': 'Windows',
             'freebsd': 'FreeBSD',
+            'midnightbsd': 'MidnightBSD',
             'darwin': 'Darwin',
         }
 
