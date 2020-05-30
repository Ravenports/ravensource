--- langkit/libmanage.py.orig	2020-05-29 13:42:27 UTC
+++ langkit/libmanage.py
@@ -950,6 +950,7 @@ class ManageScript(object):
         base_argv = ['gprinstall', '-p',
                      '-P{}'.format(project_file),
                      '--prefix={}'.format(self.dirs.install_dir()),
+                     '--project-subdir=lib/gnat',
                      '--build-var=LIBRARY_TYPE',
                      '--build-var={}_LIBRARY_TYPE'.format(project_name)]
 
