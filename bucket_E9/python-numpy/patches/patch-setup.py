--- setup.py.orig	2022-01-13 14:18:42 UTC
+++ setup.py
@@ -80,7 +80,7 @@ if os.path.exists('MANIFEST'):
 # so that it is in sys.modules
 import numpy.distutils.command.sdist
 import setuptools
-if int(setuptools.__version__.split('.')[0]) >= 60:
+if int(setuptools.__version__.split('.')[0]) >= 61:
     raise RuntimeError(
         "Setuptools version is '{}', version < '60.0.0' is required. "
         "See pyproject.toml".format(setuptools.__version__))
