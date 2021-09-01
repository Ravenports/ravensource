--- mesonbuild/linkers/detect.py.orig	2021-08-18 11:22:15 UTC
+++ mesonbuild/linkers/detect.py
@@ -141,6 +141,12 @@ def guess_nix_linker(env: 'Environment',
         check_args = comp_class.LINKER_PREFIX + ['--version'] + extra_args
 
     override = []  # type: T.List[str]
+    # sunos-only patch, hardcode to solaris (detection is broken)
+    linker = SolarisDynamicLinker(
+        compiler, for_machine, comp_class.LINKER_PREFIX, override,
+        version='unknown version')
+    return linker
+
     value = env.lookup_binary_entry(for_machine, comp_class.language + '_ld')
     if value is not None:
         override = comp_class.use_linker_args(value[0])
