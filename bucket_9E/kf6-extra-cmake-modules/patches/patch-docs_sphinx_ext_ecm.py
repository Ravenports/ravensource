From 888ee3e04e73ce93a83df4804856190fb35ff8d6 Mon Sep 17 00:00:00 2001
From: Heiko Becker <mail@heiko-becker.de>
Date: Thu, 31 Jul 2025 18:53:18 +0200
Subject: [PATCH] Move away from removed docutils error handling helpers

The previously deprecated SafeString and ErrorString classes and the
whole error_reporting module has been removed with docutils 0.22 [1].
They were only needed with python 2 to envoid encoding errors when
handling exceptions though, with python 3 they are no longer needed.

[1] https://docutils.sourceforge.io/RELEASE-NOTES.html#release-0-22-2025-07-29
---
 docs/sphinx/ext/ecm.py | 17 ++++++-----------
 1 file changed, 6 insertions(+), 11 deletions(-)

--- docs/sphinx/ext/ecm.py.orig	2025-08-01 10:28:40 UTC
+++ docs/sphinx/ext/ecm.py
@@ -41,11 +41,6 @@ QtHelpBuilder.build_keywords = new_build
 
 from docutils.parsers.rst import Directive, directives
 from docutils.transforms import Transform
-try:
-    from docutils.utils.error_reporting import SafeString, ErrorString
-except ImportError:
-    # error_reporting was not in utils before version 0.11:
-    from docutils.error_reporting import SafeString, ErrorString
 
 from docutils import io, nodes
 
@@ -80,13 +75,13 @@ class ECMModule(Directive):
             f = io.FileInput(source_path=path, encoding=encoding,
                              error_handler=e_handler)
         except UnicodeEncodeError:
-            raise self.severe('Problems with "%s" directive path:\n'
-                              'Cannot encode input file path "%s" '
-                              '(wrong locale?).' %
-                              (self.name, SafeString(path)))
+            msg = ('Problems with "%s" directive path:\n'
+                   'Cannot encode input file path "%s" '
+                   '(wrong locale?).' % (self.name, path))
+            raise self.severe(msg)
         except IOError as error:
-            raise self.severe('Problems with "%s" directive path:\n%s.' %
-                      (self.name, ErrorString(error)))
+            msg = 'Problems with "%s" directive path:\n%s.' % (self.name, error)
+            raise self.severe(msg)
         raw_lines = f.read().splitlines()
         f.close()
         rst = None
