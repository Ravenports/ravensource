--- setup.py.orig	2020-02-18 17:45:01 UTC
+++ setup.py
@@ -40,6 +40,7 @@ from _common import LINUX  # NOQA
 from _common import MACOS  # NOQA
 from _common import NETBSD  # NOQA
 from _common import OPENBSD  # NOQA
+from _common import DRAGONFLY  # NOQA
 from _common import POSIX  # NOQA
 from _common import SUNOS  # NOQA
 from _common import WINDOWS  # NOQA
@@ -213,6 +214,17 @@ elif NETBSD:
         ],
         define_macros=macros,
         libraries=["kvm"])
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
+        libraries=["kvm"])
 
 elif LINUX:
     def get_ethtool_macro():
