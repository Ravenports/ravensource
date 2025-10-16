--- src/corelib/plugin/qelfparser_p.cpp.orig	2025-08-11 04:54:51 UTC
+++ src/corelib/plugin/qelfparser_p.cpp
@@ -12,12 +12,12 @@
 #include <qnumeric.h>
 #include <qsysinfo.h>
 
-#if __has_include(<elf.h>)
-#  include <elf.h>
-#elif __has_include(<sys/elf.h>)
-#  include <sys/elf.h>
-#else
-#  error "Need ELF header to parse plugins."
+#include <libelf.h>
+#ifndef ELFMAG
+#define	ELFMAG		"\177ELF"
+#endif
+#ifndef SELFMAG
+#define SELFMAG		4
 #endif
 
 QT_BEGIN_NAMESPACE
