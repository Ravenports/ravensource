diff=1f4095efc7eb0d61d90e29b5cfdcb87f80e36914

--- src/code/x86-64-vm.lisp.orig	2020-04-27 07:01:37 UTC
+++ src/code/x86-64-vm.lisp
@@ -388,6 +388,7 @@
   (declare (ignorable code fixups))
   (unless (immobile-space-obj-p code)
     (return-from statically-link-code-obj code))
+  #+immobile-code
   (let* ((fdefns-start (+ code-constants-offset
                           (* code-slots-per-simple-fun (code-n-entries code))))
          (fdefns-count (code-n-named-calls code))
@@ -400,7 +401,7 @@
     ;;   that function is in immobile space and needs no trampoline.
     ;; * whether the replacement creates ambiguitity - if #'F and #'G are the same
     ;;   function, then substituting that function in for the fdefn of F and G
-    ;;   requires storing locations at which to replacement was done
+    ;;   requires storing locations at which replacement was done
     (dotimes (i fdefns-count)
       (let* ((fdefn (code-header-ref code (+ fdefns-start i)))
              (fun (when (fdefn-p fdefn) (fdefn-fun fdefn))))
