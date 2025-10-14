--- sslib/init.ss.orig	2014-06-21 23:24:09.000000000 +0200
+++ sslib/init.ss	2025-10-14 21:13:53.531133000 +0200
@@ -256,7 +256,7 @@
            (cars (car unz))
            (cdrs (cdr unz)))
       (apply proc cars)
-      (apply map (cons proc cdrs)) )]))
+      (apply for-each (cons proc cdrs)) )]))
 
 (define (list-tail x k)
   (if (zero? k)
