--- python/afdko/otfautohint/hinter.py.orig	2022-11-09 12:37:21 UTC
+++ python/afdko/otfautohint/hinter.py
@@ -2007,7 +2007,7 @@ class dimensionHinter(ABC):
                 lo = lo + 21
                 hi = lo - 21
             elif isG == 'high':
-                assert lo is not None and hi is not None
+                assert hi is not None
                 lo = hi
                 hi = lo - 20
             else:
