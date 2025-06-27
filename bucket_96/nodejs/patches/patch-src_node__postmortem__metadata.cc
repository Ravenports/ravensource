--- src/node_postmortem_metadata.cc.orig	2025-06-24 19:38:46 UTC
+++ src/node_postmortem_metadata.cc
@@ -13,6 +13,10 @@
 #define NODEDBG_OFFSET(Class, Member, Type) \
     NODEDBG_SYMBOL(offset_ ## Class ## __ ## Member ## __ ## Type)
 
+// Some systems provide macros for the types as well, which get expanded
+// by the nested macros here.
+#undef uintptr_t
+
 // These are the constants describing Node internal structures. Every constant
 // should use the format described above.  These constants are declared as
 // global integers so that they'll be present in the generated node binary. They
