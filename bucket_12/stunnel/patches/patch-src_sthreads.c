--- src/sthreads.c.orig	2025-11-14 12:52:51 UTC
+++ src/sthreads.c
@@ -725,7 +725,7 @@ NOEXPORT size_t stack_num(size_t stack_s
     verify_area=(stack_size-STACK_RESERVE)&~(sizeof(TL)-1);
     verify_num=verify_area/sizeof(TL);
     test_value=(TL)0x1337deadbeef1337;
-    table=alloca(verify_area);
+    table=__built_alloca(verify_area);
 
     if(init) {
         for(i=0; i<verify_num; i++)
