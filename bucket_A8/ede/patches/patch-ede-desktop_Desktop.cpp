--- ede-desktop/Desktop.cpp.orig	2014-06-21 21:24:22 UTC
+++ ede-desktop/Desktop.cpp
@@ -321,6 +321,7 @@ void Desktop::read_desktop_folder(const
 		if(DOT_OR_DOTDOT(d->d_name))
 			continue;
 
+#if !defined(__sun)
 		if(d->d_type > 0) {
 			if(d->d_type != DT_REG && d->d_type != DT_LNK && d->d_type != DT_DIR)
 				continue;
@@ -329,6 +330,7 @@ void Desktop::read_desktop_folder(const
 			path += E_DIR_SEPARATOR;
 			path += d->d_name;
 		} else {
+#endif
 			/* 
 			 * If we got here, it means d_type isn't set and we must do it via file_test() which could be much slower.
 			 * By POSIX standard, only d_name must be set, but many modern *nixes set all dirent members correctly. Except Slackware ;)
@@ -341,7 +343,9 @@ void Desktop::read_desktop_folder(const
 			     file_test(path.c_str(), FILE_TEST_IS_DIR)     ||
 			     file_test(path.c_str(), FILE_TEST_IS_SYMLINK)))
 				continue;
+#if !defined(__sun)
 		}
+#endif
 
 		DesktopIcon *o = read_desktop_file(path.c_str(), (const char*)d->d_name, &pos);
 		if(o) add(o);
