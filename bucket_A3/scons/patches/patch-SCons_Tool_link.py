--- SCons/Tool/link.py.orig	2020-07-05 19:56:34 UTC
+++ SCons/Tool/link.py
@@ -297,8 +297,8 @@ def _setup_versioned_lib_variables(env,
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
