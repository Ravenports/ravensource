--- configure.py.orig	2025-06-24 19:38:42 UTC
+++ configure.py
@@ -45,6 +45,7 @@ from utils import SearchFiles
 parser = argparse.ArgumentParser()
 
 valid_os = ('win', 'mac', 'solaris', 'freebsd', 'openbsd', 'linux',
+            'netbsd',
             'android', 'aix', 'cloudabi', 'os400', 'ios', 'openharmony')
 valid_arch = ('arm', 'arm64', 'ia32', 'mips', 'mipsel', 'mips64el',
               'ppc64', 'x64', 'x86', 'x86_64', 's390x', 'riscv64', 'loong64')
