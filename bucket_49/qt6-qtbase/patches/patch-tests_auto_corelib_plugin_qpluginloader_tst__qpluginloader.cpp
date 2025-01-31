--- tests/auto/corelib/plugin/qpluginloader/tst_qpluginloader.cpp.orig	2024-11-14 11:02:40 UTC
+++ tests/auto/corelib/plugin/qpluginloader/tst_qpluginloader.cpp
@@ -74,11 +74,7 @@ using namespace Qt::StringLiterals;
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
 
