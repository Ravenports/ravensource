--- mesonbuild/modules/pkgconfig.py.orig	2022-10-24 19:25:24 UTC
+++ mesonbuild/modules/pkgconfig.py
@@ -696,10 +696,6 @@ class PkgConfigModule(NewExtensionModule
         pcfile = filebase + '.pc'
         pkgroot = pkgroot_name = kwargs['install_dir'] or default_install_dir
         if pkgroot is None:
-            if mesonlib.is_freebsd():
-                pkgroot = os.path.join(_as_str(state.environment.coredata.get_option(mesonlib.OptionKey('prefix'))), 'libdata', 'pkgconfig')
-                pkgroot_name = os.path.join('{prefix}', 'libdata', 'pkgconfig')
-            else:
                 pkgroot = os.path.join(_as_str(state.environment.coredata.get_option(mesonlib.OptionKey('libdir'))), 'pkgconfig')
                 pkgroot_name = os.path.join('{libdir}', 'pkgconfig')
         relocatable = state.get_option('relocatable', module='pkgconfig')
