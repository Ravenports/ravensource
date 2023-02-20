--- configure.py.orig	2023-02-16 16:14:34 UTC
+++ configure.py
@@ -45,7 +45,7 @@ from utils import SearchFiles
 parser = argparse.ArgumentParser()
 
 valid_os = ('win', 'mac', 'solaris', 'freebsd', 'openbsd', 'linux',
-            'android', 'aix', 'cloudabi', 'ios')
+            'android', 'aix', 'cloudabi', 'ios', 'netbsd')
 valid_arch = ('arm', 'arm64', 'ia32', 'mips', 'mipsel', 'mips64el', 'ppc',
               'ppc64', 'x64', 'x86', 'x86_64', 's390x', 'riscv64', 'loong64')
 valid_arm_float_abi = ('soft', 'softfp', 'hard')
