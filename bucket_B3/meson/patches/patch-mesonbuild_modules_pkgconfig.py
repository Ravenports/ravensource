--- mesonbuild/modules/pkgconfig.py.orig	2021-01-06 10:39:48 UTC
+++ mesonbuild/modules/pkgconfig.py
@@ -530,10 +530,7 @@ class PkgConfigModule(ExtensionModule):
         pcfile = filebase + '.pc'
         pkgroot = kwargs.get('install_dir', default_install_dir)
         if pkgroot is None:
-            if mesonlib.is_freebsd():
-                pkgroot = os.path.join(state.environment.coredata.get_builtin_option('prefix'), 'libdata', 'pkgconfig')
-            else:
-                pkgroot = os.path.join(state.environment.coredata.get_builtin_option('libdir'), 'pkgconfig')
+            pkgroot = os.path.join(state.environment.coredata.get_builtin_option('libdir'), 'pkgconfig')
         if not isinstance(pkgroot, str):
             raise mesonlib.MesonException('Install_dir must be a string.')
         self.generate_pkgconfig_file(state, deps, subdirs, name, description, url,
