--- evdev/genecodes_c.py.orig	2025-01-20 22:19:18 UTC
+++ evdev/genecodes_c.py
@@ -33,7 +33,7 @@ uname = " ".join((uname[0], *uname[2:]))
 # -----------------------------------------------------------------------------
 template_ecodes = r"""
 #include <Python.h>
-#ifdef __FreeBSD__
+#if 0
 #include <dev/evdev/input.h>
 #else
 #include <linux/input.h>
