--- pkg_resources/__init__.py.orig	2020-05-17 02:30:06 UTC
+++ pkg_resources/__init__.py
@@ -83,7 +83,6 @@ __import__('pkg_resources.extern.packagi
 __import__('pkg_resources.extern.packaging.specifiers')
 __import__('pkg_resources.extern.packaging.requirements')
 __import__('pkg_resources.extern.packaging.markers')
-__import__('pkg_resources.py2_warn')
 
 
 __metaclass__ = type
