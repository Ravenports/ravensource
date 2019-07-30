--- engine/SCons/Tool/link.py.orig	2019-07-21 00:04:50 UTC
+++ engine/SCons/Tool/link.py
@@ -291,8 +291,8 @@ def _setup_versioned_lib_variables(env,
             env['_SHLIBVERSIONFLAGS'] = '$SHLIBVERSIONFLAGS -h $_SHLIBSONAME'
             env['_LDMODULEVERSIONFLAGS'] = '$LDMODULEVERSIONFLAGS -h $_LDMODULESONAME'
         else:
-            env['_SHLIBVERSIONFLAGS'] = '$SHLIBVERSIONFLAGS -Wl,-soname=$_SHLIBSONAME'
-            env['_LDMODULEVERSIONFLAGS'] = '$LDMODULEVERSIONFLAGS -Wl,-soname=$_LDMODULESONAME'
+            env['_SHLIBVERSIONFLAGS'] = '$SHLIBVERSIONFLAGS -Wl,-soname,$_SHLIBSONAME'
+            env['_LDMODULEVERSIONFLAGS'] = '$LDMODULEVERSIONFLAGS -Wl,-soname,$_LDMODULESONAME'
         env['_SHLIBSONAME'] = '${ShLibSonameGenerator(__env__,TARGET)}'
         env['_LDMODULESONAME'] = '${LdModSonameGenerator(__env__,TARGET)}'
         env['ShLibSonameGenerator'] = SCons.Tool.ShLibSonameGenerator
