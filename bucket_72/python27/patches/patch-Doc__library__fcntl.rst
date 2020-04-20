--- ./Doc/library/fcntl.rst.orig	2020-04-19 21:13:39 UTC
+++ ./Doc/library/fcntl.rst
@@ -52,7 +52,6 @@ The module defines the following functio
    operations are typically defined in the library module :mod:`termios` and the
    argument handling is even more complicated.
 
-   The op parameter is limited to values that can fit in 32-bits.
    Additional constants of interest for use as the *op* argument can be
    found in the :mod:`termios` module, under the same names as used in
    the relevant C header files.
