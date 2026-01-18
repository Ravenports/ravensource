--- agent/kernel.h.orig	2025-12-23 16:54:18 UTC
+++ agent/kernel.h
@@ -17,7 +17,7 @@
 
 extern int      init_kmem(const char *);
 extern void     free_kmem(void);
-#ifdef HAVE_KVM_H
+#if defined(HAVE_KVM_H) && !defined(__DragonFly__) 
 extern int      klookup(unsigned long, void *, size_t);
 #define NETSNMP_KLOOKUP(x,y,z) klookup((unsigned long) x,y,z)
 #else
