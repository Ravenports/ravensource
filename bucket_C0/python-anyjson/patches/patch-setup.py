--- setup.py.orig	2012-06-21 22:59:59 UTC
+++ setup.py
@@ -2,8 +2,6 @@ import os
 import sys
 
 extra = {}
-if sys.version_info >= (3, 0):
-    extra.update(use_2to3=True)
 
 try:
     from setuptools import setup, find_packages
