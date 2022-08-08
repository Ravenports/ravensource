--- mesonbuild/modules/pkgconfig.py.orig	2022-06-19 19:10:14 UTC
+++ mesonbuild/modules/pkgconfig.py
@@ -593,10 +593,6 @@ class PkgConfigModule(ExtensionModule):
         pcfile = filebase + '.pc'
         pkgroot = pkgroot_name = kwargs.get('install_dir', default_install_dir)
         if pkgroot is None:
-            if mesonlib.is_freebsd():
-                pkgroot = os.path.join(state.environment.coredata.get_option(mesonlib.OptionKey('prefix')), 'libdata', 'pkgconfig')
-                pkgroot_name = os.path.join('{prefix}', 'libdata', 'pkgconfig')
-            else:
                 pkgroot = os.path.join(state.environment.coredata.get_option(mesonlib.OptionKey('libdir')), 'pkgconfig')
                 pkgroot_name = os.path.join('{libdir}', 'pkgconfig')
         if not isinstance(pkgroot, str):
