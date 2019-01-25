--- setup.py.orig	2019-01-23 17:30:57 UTC
+++ setup.py
@@ -27,7 +27,7 @@ import distutils.command.build_scripts
 import distutils.command.install_scripts
 import distutils.command.install_lib
 import distutils.command.install_data
-import distutils.command.install
+import setuptools.command.install
 import distutils.core
 import distutils
 # import setuptools
@@ -77,7 +77,7 @@ else:
     is_win32 = 1
 
 
-_install = distutils.command.install.install
+_install = setuptools.command.install.install
 _install_data = distutils.command.install_data.install_data
 _install_lib = distutils.command.install_lib.install_lib
 _install_scripts = distutils.command.install_scripts.install_scripts
@@ -380,7 +380,7 @@ class install_data(_install_data):
             if is_win32:
                 dir = 'Doc'
             else:
-                dir = os.path.join('man', 'man1')
+                dir = os.path.join('share', 'man', 'man1')
             self.data_files = [(dir, man_pages)]
             man_dir = os.path.join(self.install_dir, dir)
             msg = "Installed SCons man pages into %s" % man_dir
