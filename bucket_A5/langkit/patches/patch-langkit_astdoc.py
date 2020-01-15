--- langkit/astdoc.py.orig	2019-05-11 05:16:01 UTC
+++ langkit/astdoc.py
@@ -73,19 +73,7 @@ def format_doc(entity):
         doc = trim_docstring_lines(doc)
 
         # Run docutils and intercept its warnings and errors
-        with substitute_stdio() as (stdout, stderr):
-            formatted_doc = publish_parts(doc, writer_name='html')['html_body']
-            stdout.seek(0)
-            stderr.seek(0)
-            out = stdout.read().strip()
-            err = stderr.read().strip()
-
-        # Turn docutils' diagnostic into our own diagnostic system
-        with entity.diagnostic_context:
-            for output in (out, err):
-                check_source_language(
-                    not output, output, severity=Severity.warning,
-                    ok_for_codegen=True)
+        formatted_doc = publish_parts(doc, writer_name='html')['html_body']
 
         return '<div class="doc">{}</div>'.format(formatted_doc)
     else:
