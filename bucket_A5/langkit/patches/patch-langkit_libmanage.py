--- langkit/libmanage.py.orig	2019-05-11 05:16:01 UTC
+++ langkit/libmanage.py
@@ -826,6 +826,7 @@ class ManageScript(object):
         base_argv = ['gprinstall', '-p',
                      '-P{}'.format(project_file),
                      '--prefix={}'.format(self.dirs.install_dir()),
+                     '--project-subdir=lib/gnat',
                      '--build-var=LIBRARY_TYPE',
                      '--build-var={}_LIBRARY_TYPE'.format(project_name)]
 
