--- mesonbuild/modules/pkgconfig.py.orig	2021-04-27 06:50:21 UTC
+++ mesonbuild/modules/pkgconfig.py
@@ -539,10 +539,7 @@ class PkgConfigModule(ExtensionModule):
         pcfile = filebase + '.pc'
         pkgroot = kwargs.get('install_dir', default_install_dir)
         if pkgroot is None:
-            if mesonlib.is_freebsd():
-                pkgroot = os.path.join(state.environment.coredata.get_option(mesonlib.OptionKey('prefix')), 'libdata', 'pkgconfig')
-            else:
-                pkgroot = os.path.join(state.environment.coredata.get_option(mesonlib.OptionKey('libdir')), 'pkgconfig')
+            pkgroot = os.path.join(state.environment.coredata.get_option(mesonlib.OptionKey('libdir')), 'pkgconfig')
         if not isinstance(pkgroot, str):
             raise mesonlib.MesonException('Install_dir must be a string.')
         self.generate_pkgconfig_file(state, deps, subdirs, name, description, url,
