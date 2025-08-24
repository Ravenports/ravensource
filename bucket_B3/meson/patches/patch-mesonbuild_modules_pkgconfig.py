--- mesonbuild/modules/pkgconfig.py.orig	2025-08-24 17:28:31 UTC
+++ mesonbuild/modules/pkgconfig.py
@@ -716,7 +716,7 @@ class PkgConfigModule(NewExtensionModule
         pkgroot = pkgroot_name = kwargs['install_dir'] or default_install_dir
         if pkgroot is None:
             m = state.environment.machines.host
-            if m.is_freebsd():
+            if False:
                 pkgroot = os.path.join(_as_str(state.environment.coredata.optstore.get_value_for(OptionKey('prefix'))), 'libdata', 'pkgconfig')
                 pkgroot_name = os.path.join('{prefix}', 'libdata', 'pkgconfig')
             elif m.is_haiku():
