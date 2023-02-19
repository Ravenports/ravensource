--- tools/gyp/pylib/gyp/generator/make.py.orig	2023-02-16 16:14:47 UTC
+++ tools/gyp/pylib/gyp/generator/make.py
@@ -2490,7 +2490,7 @@ def GenerateOutput(target_list, target_d
                 "flock_index": 2,
             }
         )
-    elif flavor == "freebsd":
+    elif flavor == "freebsd" or flavor == 'dragonflybsd' or flavor == 'netbsd':
         # Note: OpenBSD has sysutils/flock. lockf seems to be FreeBSD specific.
         header_params.update({"flock": "lockf"})
     elif flavor == "openbsd":
