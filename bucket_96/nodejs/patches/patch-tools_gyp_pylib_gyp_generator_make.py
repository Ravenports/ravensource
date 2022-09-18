--- tools/gyp/pylib/gyp/generator/make.py.orig	2022-07-06 19:06:50 UTC
+++ tools/gyp/pylib/gyp/generator/make.py
@@ -2476,7 +2476,7 @@ def GenerateOutput(target_list, target_d
                 "flock_index": 2,
             }
         )
-    elif flavor == "freebsd":
+    elif flavor == "freebsd" or flavor == 'dragonflybsd' or flavor == 'netbsd':
         # Note: OpenBSD has sysutils/flock. lockf seems to be FreeBSD specific.
         header_params.update({"flock": "lockf"})
     elif flavor == "openbsd":
