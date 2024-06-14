--- setup.py.orig	2024-01-15 00:34:23 UTC
+++ setup.py
@@ -30,6 +30,6 @@ setup(name="miniupnpc",
       cmdclass={'build_ext': make_then_build_ext},
       ext_modules=[
          Extension(name="miniupnpc", sources=["src/miniupnpcmodule.c"],
-                   include_dirs=['include'], extra_objects=EXT)
+                   include_dirs=['include'], libraries=["miniupnpc"])
       ])
 
