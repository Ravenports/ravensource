--- src/llvm-project/llvm/lib/Support/Unix/Path.inc.orig	2025-06-23 19:24:54 UTC
+++ src/llvm-project/llvm/lib/Support/Unix/Path.inc
@@ -37,6 +37,9 @@
 #if __has_include(<sys/clonefile.h>)
 #include <sys/clonefile.h>
 #endif
+#elif defined(__MidnightBSD__)
+#include <sys/auxv.h>
+#include <machine/elf.h>
 #elif defined(__FreeBSD__)
 #include <osreldate.h>
 #if __FreeBSD_version >= 1300057
@@ -197,6 +200,17 @@ std::string getMainExecutable(const char
     if (realpath(exe_path, link_path))
       return link_path;
   }
+#elif defined(__MidnightBSD__)
+  // Right now environ symbol is not being linked in on MBSD.  It
+  // appears that elf_aux_info is implemented in MBSD 3.0, so use that.
+  char exe_path[PATH_MAX];
+  if (elf_aux_info(AT_EXECPATH, exe_path, sizeof(exe_path)) == 0) {
+    char link_path[PATH_MAX];
+    if (realpath(exe_path, link_path))
+      return link_path;
+  }
+  if (getprogpath(exe_path, argv0) != NULL)
+    return exe_path;
 #elif defined(__FreeBSD__)
   // On FreeBSD if the exec path specified in ELF auxiliary vectors is
   // preferred, if available.  /proc/curproc/file and the KERN_PROC_PATHNAME
