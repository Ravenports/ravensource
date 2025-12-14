--- plug-ins/python/python-eval.py.orig	2025-10-05 17:14:02 UTC
+++ plug-ins/python/python-eval.py
@@ -41,6 +41,7 @@ def code_eval(procedure, run_mode, code,
     try:
       exec(code, globals())
     except Exception as error:
+      print("###  evaluated code failure  ###\n" + code)
       retval = Gimp.PDBStatusType.CALLING_ERROR
       gerror = GLib.Error(traceback.format_exc())
 
