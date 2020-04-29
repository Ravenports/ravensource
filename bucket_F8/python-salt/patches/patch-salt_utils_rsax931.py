--- salt/utils/rsax931.py.orig	2020-04-29 18:29:44 UTC
+++ salt/utils/rsax931.py
@@ -43,7 +43,7 @@ def _load_libcrypto():
             # This could be /opt/tools/lib (Global Zone)
             # or /opt/local/lib (non-Global Zone), thus the
             # two checks below
-            lib = glob.glob('/opt/local/lib/libcrypto.so*') + glob.glob('/opt/tools/lib/libcrypto.so*')
+            lib = glob.glob('/opt/local/lib/libcrypto.so*') + glob.glob('/opt/tools/lib/libcrypto.so*') + glob.glob('__PREFIX__/lib/libcrypto.so*')
             lib = lib[0] if len(lib) > 0 else None
         if not lib and salt.utils.platform.is_aix():
             if os.path.isdir('/opt/salt/lib'):
