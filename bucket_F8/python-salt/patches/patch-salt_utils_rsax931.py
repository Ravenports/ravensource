--- salt/utils/rsax931.py.orig	2018-08-03 14:17:17.391935000 +0200
+++ salt/utils/rsax931.py	2018-08-03 14:18:20.948802000 +0200
@@ -43,7 +43,7 @@
             # This could be /opt/tools/lib (Global Zone)
             # or /opt/local/lib (non-Global Zone), thus the
             # two checks below
-            lib = glob.glob('/opt/local/lib/libcrypto.so*') + glob.glob('/opt/tools/lib/libcrypto.so*')
+            lib = glob.glob('/opt/local/lib/libcrypto.so*') + glob.glob('/opt/tools/lib/libcrypto.so*') + glob.glob('__PREFIX__/lib/libcrypto.so*')
             lib = lib[0] if len(lib) > 0 else None
         if lib:
             return cdll.LoadLibrary(lib)
