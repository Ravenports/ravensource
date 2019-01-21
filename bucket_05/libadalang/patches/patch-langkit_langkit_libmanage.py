--- langkit/langkit/libmanage.py.orig	2018-04-25 09:45:20 UTC
+++ langkit/langkit/libmanage.py
@@ -750,6 +750,7 @@ class ManageScript(object):
         base_argv = ['gprinstall', '-p',
                      '-P{}'.format(project_file),
                      '--prefix={}'.format(self.dirs.install_dir()),
+                     '--project-subdir=lib/gnat',
                      '--build-var=LIBRARY_TYPE']
 
         # If this is a library, install sources in an unique location: there is
