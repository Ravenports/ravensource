--- mesonbuild/modules/pkgconfig.py.orig	2023-02-23 22:07:07 UTC
+++ mesonbuild/modules/pkgconfig.py
@@ -696,7 +696,7 @@ class PkgConfigModule(NewExtensionModule
         pcfile = filebase + '.pc'
         pkgroot = pkgroot_name = kwargs['install_dir'] or default_install_dir
         if pkgroot is None:
-            if mesonlib.is_freebsd():
+            if False:
                 pkgroot = os.path.join(_as_str(state.environment.coredata.get_option(mesonlib.OptionKey('prefix'))), 'libdata', 'pkgconfig')
                 pkgroot_name = os.path.join('{prefix}', 'libdata', 'pkgconfig')
             elif mesonlib.is_haiku():
