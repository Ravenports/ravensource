Disable libssp -- it causes segfaults on several platforms, likly some
kind of missing os-specific support or consideration.

--- buildtools/wafsamba/samba_autoconf.py.orig	2018-07-12 05:51:30 UTC
+++ buildtools/wafsamba/samba_autoconf.py
@@ -673,25 +673,6 @@ def SAMBA_CONFIG_H(conf, path=None):
     if not IN_LAUNCH_DIR(conf):
         return
 
-    # we need to build real code that can't be optimized away to test
-    if conf.check(fragment='''
-        #include <stdio.h>
-
-        int main(void)
-        {
-            char t[100000];
-            while (fgets(t, sizeof(t), stdin));
-            return 0;
-        }
-        ''',
-        execute=0,
-        ccflags='-fstack-protector',
-        ldflags='-fstack-protector',
-        mandatory=False,
-        msg='Checking if toolchain accepts -fstack-protector'):
-            conf.ADD_CFLAGS('-fstack-protector')
-            conf.ADD_LDFLAGS('-fstack-protector')
-
     if Options.options.debug:
         conf.ADD_CFLAGS('-g', testflags=True)
 
