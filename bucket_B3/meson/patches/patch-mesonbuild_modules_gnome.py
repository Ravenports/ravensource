--- mesonbuild/modules/gnome.py.orig	2021-07-05 19:02:33 UTC
+++ mesonbuild/modules/gnome.py
@@ -1135,7 +1135,6 @@ class GnomeModule(ExtensionModule):
             check_kwargs = {'env': check_env,
                             'workdir': os.path.join(state.environment.get_build_dir(), state.subdir),
                             'depends': custom_target}
-            self.interpreter.add_test(state.current_node, check_args, check_kwargs, True)
         res = [custom_target, alias_target]
         if kwargs.get('install', True):
             res.append(state.backend.get_executable_serialisation(command + args))
