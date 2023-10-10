https://github.com/AdaCore/gnatcoll-bindings/issues/18

Fixes build with python 3.11+

--- python/python_support.c.orig	2023-01-04 08:36:46 UTC
+++ python/python_support.c
@@ -813,13 +813,13 @@ PyAPI_FUNC(PyObject *) PyFile_FromString
 PyCodeObject*
 ada_pyframe_get_code (PyFrameObject* obj)
 {
-   return obj->f_code;
+   return PyFrame_GetCode (obj);
 }
 
 PyFrameObject*
 ada_pyframe_get_back (PyFrameObject* obj)
 {
-   return obj->f_back;
+   return PyFrame_GetBack (obj);
 }
 
 PyObject*
