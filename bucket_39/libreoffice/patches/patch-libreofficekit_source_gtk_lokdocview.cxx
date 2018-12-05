--- libreofficekit/source/gtk/lokdocview.cxx.orig	2018-10-30 16:55:21 UTC
+++ libreofficekit/source/gtk/lokdocview.cxx
@@ -3218,6 +3218,7 @@ static void lok_doc_view_class_init (LOK
                      G_TYPE_STRING);
 
     /**
+     * LOKDocView::ruler:
      * The key ruler related properties on change are reported by this.
      *
      * The payload format is:
@@ -3244,6 +3245,7 @@ static void lok_doc_view_class_init (LOK
                      G_TYPE_STRING);
 
     /**
+     * LOKDocView::invalidate-header:
      * The column/row header is no more valid because of a column/row insertion
      * or a similar event. Clients must query a new column/row header set.
      *
