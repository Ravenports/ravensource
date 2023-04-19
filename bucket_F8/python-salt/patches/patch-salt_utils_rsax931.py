--- salt/utils/rsax931.py.orig	2023-04-18 21:05:02 UTC
+++ salt/utils/rsax931.py
@@ -68,7 +68,7 @@ def _find_libcrypto():
                 # This could be /opt/tools/lib (Global Zone) or
                 # /opt/local/lib (non-Global Zone), thus the two checks
                 # below
-                lib = glob.glob("/opt/saltstack/salt/run/libcrypto.so*")
+                lib = glob.glob('__PREFIX__/lib/libcrypto.so*')
                 lib = lib or glob.glob("/opt/local/lib/libcrypto.so*")
                 lib = lib or glob.glob("/opt/tools/lib/libcrypto.so*")
                 lib = lib[0] if lib else None
