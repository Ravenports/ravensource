--- mesonbuild/modules/pkgconfig.py.orig	2026-08-21 01:33:01 UTC
+++ mesonbuild/modules/pkgconfig.py
@@ -780,7 +780,7 @@ class PkgConfigModule(NewExtensionModule
             pkgroot_name = pkgroot.optname
         if pkgroot is None:
             m = state.environment.machines.host
-            if m.is_freebsd():
+            if False:
                 pkgroot = os.path.join(_as_str(state.environment.coredata.optstore.get_value_for(OptionKey('prefix'))), 'libdata', 'pkgconfig')
                 pkgroot_name = os.path.join('{prefix}', 'libdata', 'pkgconfig')
             elif m.is_haiku():
