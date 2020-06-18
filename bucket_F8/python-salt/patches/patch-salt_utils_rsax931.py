--- salt/utils/rsax931.py.orig	2020-06-18 09:31:44.611887000 +0200
+++ salt/utils/rsax931.py	2020-06-18 09:34:12.705293000 +0200
@@ -43,7 +43,8 @@
                 # This could be /opt/tools/lib (Global Zone) or
                 # /opt/local/lib (non-Global Zone), thus the two checks
                 # below
-                lib = glob.glob("/opt/local/lib/libcrypto.so*")
+		lib = glob.glob('__PREFIX__/lib/libcrypto.so*')
+                lib = lib or glob.glob("/opt/local/lib/libcrypto.so*")
                 lib = lib or glob.glob("/opt/tools/lib/libcrypto.so*")
                 lib = lib[0] if lib else None
             elif salt.utils.platform.is_aix():
