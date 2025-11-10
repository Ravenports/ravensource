--- Modules/timemodule.c.orig	2025-10-07 09:34:52 UTC
+++ Modules/timemodule.c
@@ -185,7 +185,7 @@ py_clock(time_module_state *state, PyTim
 static int
 time_clockid_converter(PyObject *obj, clockid_t *p)
 {
-#ifdef _AIX
+#if defined(_AIX) || defined(__DragonFly__)
     long long clk_id = PyLong_AsLongLong(obj);
 #elif defined(__DragonFly__)
     long clk_id = PyLong_AsLong(obj);
