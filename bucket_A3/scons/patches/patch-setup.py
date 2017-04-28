--- setup.py.orig	2016-11-03 18:02:48 UTC
+++ setup.py
@@ -76,7 +76,7 @@ else:
 
 import distutils
 import distutils.core
-import distutils.command.install
+import setuptools.command.install
 import distutils.command.install_data
 import distutils.command.install_lib
 import distutils.command.install_scripts
@@ -92,7 +92,7 @@ def get_build_version():
 
 distutils.msvccompiler.get_build_version = get_build_version
 
-_install = distutils.command.install.install
+_install = setuptools.command.install.install
 _install_data = distutils.command.install_data.install_data
 _install_lib = distutils.command.install_lib.install_lib
 _install_scripts = distutils.command.install_scripts.install_scripts
@@ -375,7 +375,7 @@ class install_data(_install_data):
             if is_win32:
                 dir = 'Doc'
             else:
-                dir = os.path.join('man', 'man1')
+                dir = os.path.join('share', 'man', 'man1')
             self.data_files = [(dir, man_pages)]
             man_dir = os.path.join(self.install_dir, dir)
             msg = "Installed SCons man pages into %s" % man_dir
