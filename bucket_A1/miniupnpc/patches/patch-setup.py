--- setup.py.orig	2024-06-22 22:28:04 UTC
+++ setup.py
@@ -32,6 +32,6 @@ setup(name="miniupnpc",
       cmdclass={'build_ext': make_then_build_ext},
       ext_modules=[
          Extension(name="miniupnpc", sources=["src/miniupnpcmodule.c"],
-                   include_dirs=['include'], extra_objects=EXT)
+                   include_dirs=['include'], libraries=["miniupnpc"])
       ])
 
