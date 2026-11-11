--- tests/auto/corelib/plugin/qpluginloader/tst_qpluginloader.cpp.orig	2026-06-04 16:29:11 UTC
+++ tests/auto/corelib/plugin/qpluginloader/tst_qpluginloader.cpp
@@ -83,11 +83,7 @@ using namespace Qt::StringLiterals;
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
 
