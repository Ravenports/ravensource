--- setup.py.orig	2021-09-28 21:11:31 UTC
+++ setup.py
@@ -30,6 +30,6 @@ setup(name="miniupnpc",
       cmdclass={'build_ext': make_then_build_ext},
       ext_modules=[
          Extension(name="miniupnpc", sources=["src/miniupnpcmodule.c"],
-                   include_dirs=['include'], extra_objects=EXT)
+                   include_dirs=['include'], libraries=["miniupnpc"])
       ])
 
