Disable libssp -- it causes segfaults on several platforms, likly some
kind of missing os-specific support or consideration.

--- buildtools/wafsamba/samba_autoconf.py.orig	2024-07-03 08:51:36 UTC
+++ buildtools/wafsamba/samba_autoconf.py
@@ -719,44 +719,6 @@ def SAMBA_CONFIG_H(conf, path=None):
     if not IN_LAUNCH_DIR(conf):
         return
 
-    # we need to build real code that can't be optimized away to test
-    stack_protect_list = ['-fstack-protector-strong', '-fstack-protector']
-    for stack_protect_flag in stack_protect_list:
-        flag_supported = conf.check(fragment='''
-                                    #include <stdio.h>
-
-                                    int main(void)
-                                    {
-                                        char t[100000];
-                                        while (fgets(t, sizeof(t), stdin));
-                                        return 0;
-                                    }
-                                    ''',
-                                    execute=0,
-                                    cflags=[ '-Werror', '-Wp,-D_FORTIFY_SOURCE=2', stack_protect_flag],
-                                    mandatory=False,
-                                    msg='Checking if compiler accepts %s' % (stack_protect_flag))
-        if flag_supported:
-            conf.ADD_CFLAGS('%s' % (stack_protect_flag))
-            break
-
-    flag_supported = conf.check(fragment='''
-                                #include <stdio.h>
-
-                                int main(void)
-                                {
-                                    char t[100000];
-                                    while (fgets(t, sizeof(t), stdin));
-                                    return 0;
-                                }
-                                ''',
-                                execute=0,
-                                cflags=[ '-Werror', '-fstack-clash-protection'],
-                                mandatory=False,
-                                msg='Checking if compiler accepts -fstack-clash-protection')
-    if flag_supported:
-        conf.ADD_CFLAGS('-fstack-clash-protection')
-
     if Options.options.debug:
         conf.ADD_CFLAGS('-g', testflags=True)
 
