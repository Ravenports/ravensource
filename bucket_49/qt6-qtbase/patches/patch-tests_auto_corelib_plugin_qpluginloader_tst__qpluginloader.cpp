--- tests/auto/corelib/plugin/qpluginloader/tst_qpluginloader.cpp.orig	2025-05-28 10:22:57 UTC
+++ tests/auto/corelib/plugin/qpluginloader/tst_qpluginloader.cpp
@@ -78,11 +78,7 @@ using namespace Qt::StringLiterals;
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
 
