--- src/alloc.c.orig	2017-04-14 15:02:47 UTC
+++ src/alloc.c
@@ -476,7 +476,7 @@ static void *pure_alloc (size_t, int);
 /* Return PTR rounded up to the next multiple of ALIGNMENT.  */
 
 static void *
-ALIGN (void *ptr, int alignment)
+EMACS_ALIGN (void *ptr, int alignment)
 {
   return (void *) ROUNDUP ((uintptr_t) ptr, alignment);
 }
@@ -5173,7 +5173,7 @@ pure_alloc (size_t size, int type)
     {
       /* Allocate space for a Lisp object from the beginning of the free
 	 space with taking account of alignment.  */
-      result = ALIGN (purebeg + pure_bytes_used_lisp, GCALIGNMENT);
+      result = EMACS_ALIGN (purebeg + pure_bytes_used_lisp, GCALIGNMENT);
       pure_bytes_used_lisp = ((char *)result - (char *)purebeg) + size;
     }
   else
