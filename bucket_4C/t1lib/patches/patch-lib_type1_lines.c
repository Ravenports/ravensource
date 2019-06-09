--- lib/type1/lines.c.orig	2007-12-23 16:49:42.000000000 +0100
+++ lib/type1/lines.c	2019-06-06 15:25:33.521481000 +0200
@@ -67,6 +67,10 @@
 None.
 */
  
+#define  BITS         (sizeof(LONG)*8)
+#define  HIGHTEST(p)  (((p)>>(BITS-2)) != 0)  /* includes sign bit */
+#define  TOOBIG(xy)   ((xy < 0) ? HIGHTEST(-xy) : HIGHTEST(xy))
+
 /*
 :h2.StepLine() - Produces Run Ends for a Line After Checks
  
@@ -84,6 +88,9 @@
        IfTrace4((LineDebug > 0), ".....StepLine: (%d,%d) to (%d,%d)\n",
                                             x1, y1, x2, y2);
  
+      if (TOOBIG(x1) || TOOBIG(x2) || TOOBIG(y1) || TOOBIG(y2))
+              abort("Lines this big not supported", 49);
+
        dy = y2 - y1;
  
 /*
