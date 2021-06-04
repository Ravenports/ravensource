--- meson_post_install.py.orig	2019-04-23 17:16:09.000000000 +0200
+++ meson_post_install.py	2021-06-03 15:47:58.660402000 +0200
@@ -9,8 +9,8 @@
 # FIXME: meson will not track the creation of these directories
 #        https://github.com/mesonbuild/meson/blob/master/mesonbuild/scripts/uninstall.py#L39
 dst_dirs = [
-  (os.path.join(localstatedir, 'lib', 'AccountsService', 'icons'), 0o775),
-  (os.path.join(localstatedir, 'lib', 'AccountsService', 'users'), 0o700),
+  (os.path.join(localstatedir, 'db', 'AccountsService', 'icons'), 0o775),
+  (os.path.join(localstatedir, 'db', 'AccountsService', 'users'), 0o700),
 ]
 
 for (dst_dir, dst_dir_mode) in dst_dirs:
