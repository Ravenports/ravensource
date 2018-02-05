--- include/llvm/Support/Host.h.orig	2016-10-13 17:43:20 UTC
+++ include/llvm/Support/Host.h
@@ -20,6 +20,18 @@
 #include <endian.h>
 #elif defined(_AIX)
 #include <sys/machine.h>
+#elif defined(__sun) & defined(__SVR4)
+# ifndef BYTE_ORDER
+# define LITTLE_ENDIAN 1234
+# define BIG_ENDIAN 4321
+# include <sys/isa_defs.h>
+# ifdef _LITTLE_ENDIAN
+# define BYTE_ORDER LITTLE_ENDIAN
+# endif
+# ifdef _BIG_ENDIAN
+# define BYTE_ORDER BIG_ENDIAN
+# endif
+# endif /* BYTE_ORDER */
 #else
 #if !defined(BYTE_ORDER) && !defined(LLVM_ON_WIN32)
 #include <machine/endian.h>
