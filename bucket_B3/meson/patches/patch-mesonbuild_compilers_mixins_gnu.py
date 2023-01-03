Do not default to -z ignore on SunOS, it breaks for example -fstack-protector.

--- mesonbuild/compilers/mixins/gnu.py.orig	2022-12-10 16:38:19 UTC
+++ mesonbuild/compilers/mixins/gnu.py
@@ -380,7 +380,7 @@ class GnuLikeCompiler(Compiler, metaclas
                                    'b_ndebug', 'b_staticpic', 'b_pie']}
         if not (self.info.is_windows() or self.info.is_cygwin() or self.info.is_openbsd()):
             self.base_options.add(OptionKey('b_lundef'))
-        if not self.info.is_windows() or self.info.is_cygwin():
+        if not (self.info.is_windows() or self.info.is_sunos()) or self.info.is_cygwin():
             self.base_options.add(OptionKey('b_asneeded'))
         if not self.info.is_hurd():
             self.base_options.add(OptionKey('b_sanitize'))
