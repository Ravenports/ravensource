--- ../elftoolchain-0.7.1/libelf/_libelf_config.h.orig	2015-02-24 19:17:47 UTC
+++ ../elftoolchain-0.7.1/libelf/_libelf_config.h
@@ -40,6 +40,12 @@
 
 #endif	/* __DragonFly__ */
 
+#if defined(__sun__)
+# define LIBELF_ARCH		EM_X86_64
+# define LIBELF_BYTEORDER	ELFDATA2LSB
+# define LIBELF_CLASS		ELFCLASS64
+#endif
+
 #ifdef __FreeBSD__
 
 /*
