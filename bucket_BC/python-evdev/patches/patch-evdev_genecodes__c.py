--- src/evdev/genecodes_c.py.orig	2025-02-02 20:25:21 UTC
+++ src/evdev/genecodes_c.py
@@ -36,7 +36,7 @@ uname = " ".join((uname[0], *uname[2:]))
 # -----------------------------------------------------------------------------
 template_ecodes = r"""
 #include <Python.h>
-#ifdef __FreeBSD__
+#if 0
 #include <dev/evdev/input.h>
 #include <dev/evdev/uinput.h>
 #else
