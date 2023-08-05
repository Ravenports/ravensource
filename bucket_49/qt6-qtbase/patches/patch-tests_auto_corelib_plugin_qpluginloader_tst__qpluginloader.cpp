--- tests/auto/corelib/plugin/qpluginloader/tst_qpluginloader.cpp.orig	2023-07-06 10:02:03 UTC
+++ tests/auto/corelib/plugin/qpluginloader/tst_qpluginloader.cpp
@@ -70,11 +70,7 @@
 #endif
 
 #if defined(Q_OF_ELF)
-#if __has_include(<elf.h>)
-# include <elf.h>
-#else
-# include <sys/elf.h>
-#endif
+#  include <libelf.h>
 #  include <memory>
 #  include <functional>
 
