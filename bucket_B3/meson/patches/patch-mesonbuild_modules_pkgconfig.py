--- mesonbuild/modules/pkgconfig.py.orig	2022-04-23 09:53:34 UTC
+++ mesonbuild/modules/pkgconfig.py
@@ -583,10 +583,6 @@ class PkgConfigModule(ExtensionModule):
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
