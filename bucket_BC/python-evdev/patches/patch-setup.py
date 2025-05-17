--- setup.py.orig	2025-05-01 19:14:34 UTC
+++ setup.py
@@ -26,7 +26,7 @@ def create_ecodes(headers=None, reproduc
             include_paths.update(c_inc_path.split(":"))
 
         include_paths.add("/usr/include")
-        if platform.system().lower() == "freebsd":
+        if platform.system().lower() == "nothing":
             files = ["dev/evdev/input.h", "dev/evdev/input-event-codes.h", "dev/evdev/uinput.h"]
         else:
             files = ["linux/input.h", "linux/input-event-codes.h", "linux/uinput.h"]
