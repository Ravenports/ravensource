--- tests/auto/corelib/plugin/qpluginloader/tst_qpluginloader.cpp.orig	2024-03-19 15:46:43 UTC
+++ tests/auto/corelib/plugin/qpluginloader/tst_qpluginloader.cpp
@@ -72,11 +72,7 @@ using namespace Qt::StringLiterals;
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
 
