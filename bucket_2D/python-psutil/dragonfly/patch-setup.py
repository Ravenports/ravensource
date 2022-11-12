--- setup.py.orig	2022-10-21 20:20:35 UTC
+++ setup.py
@@ -50,6 +50,7 @@ from _common import LINUX  # NOQA
 from _common import MACOS  # NOQA
 from _common import NETBSD  # NOQA
 from _common import OPENBSD  # NOQA
+from _common import DRAGONFLY  # NOQA
 from _common import POSIX  # NOQA
 from _common import SUNOS  # NOQA
 from _common import WINDOWS  # NOQA
@@ -260,6 +261,18 @@ elif NETBSD:
         ],
         define_macros=macros,
         libraries=["kvm"],
+        **py_limited_api)
+
+elif DRAGONFLY:
+    macros.append(("PSUTIL_DRAGONFLY", 1))
+    ext = Extension(
+        'psutil._psutil_bsd',
+        sources=sources + [
+            'psutil/_psutil_bsd.c',
+            'psutil/arch/bsd/dragonfly.c',
+        ],
+        define_macros=macros,
+        libraries=["kvm"],
         **py_limited_api)
 
 elif LINUX:
