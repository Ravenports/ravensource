Fixes use on python 3.6
Taken-from: http://pkgs.fedoraproject.org/cgit/rpms/libxml2.git/tree/libxml2-2.9.4-remove-pyverify_fd.patch

--- python/types.c.orig	2016-06-07 10:04:14 UTC
+++ python/types.c
@@ -31,8 +31,6 @@ libxml_PyFileGet(PyObject *f) {
     const char *mode;
 
     fd = PyObject_AsFileDescriptor(f);
-    if (!_PyVerify_fd(fd))
-        return(NULL);
     /*
      * Get the flags on the fd to understand how it was opened
      */
