--- mesonbuild/cmake/toolchain.py.orig	2024-05-30 17:10:13 UTC
+++ mesonbuild/cmake/toolchain.py
@@ -148,6 +148,7 @@ class CMakeToolchain:
             'linux': 'Linux',
             'windows': 'Windows',
             'freebsd': 'FreeBSD',
+            'midnightbsd': 'MidnightBSD',
             'darwin': 'Darwin',
         }
 
