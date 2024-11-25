--- lib/monkey/mk_core/mk_string.c.orig	2022-03-22 22:42:32 UTC
+++ lib/monkey/mk_core/mk_string.c
@@ -65,7 +65,7 @@ void *memmem(const void *haystack, size_
     free_needle_buffer = 0;
 
     if(1024 > haystacklen){
-        null_terminated_haystack_buffer = (uint8_t *)_alloca(haystacklen + 1);
+        null_terminated_haystack_buffer = (uint8_t *)__builtin_alloca(haystacklen + 1);
     }
     else
     {
@@ -75,7 +75,7 @@ void *memmem(const void *haystack, size_
 
     if(NULL != null_terminated_haystack_buffer){
         if(1024 > needlelen){
-            null_terminated_needle_buffer = (uint8_t*)_alloca(needlelen + 1);
+            null_terminated_needle_buffer = (uint8_t*)__builtin_alloca(needlelen + 1);
         }
         else
         {
