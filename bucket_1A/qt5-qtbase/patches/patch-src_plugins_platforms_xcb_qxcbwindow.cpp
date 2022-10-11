--- src/plugins/platforms/xcb/qxcbwindow.cpp.orig	2022-06-24 10:42:02 UTC
+++ src/plugins/platforms/xcb/qxcbwindow.cpp
@@ -706,7 +706,7 @@ void QXcbWindow::show()
         if (isTransient(window())) {
             const QWindow *tp = window()->transientParent();
             if (tp && tp->handle())
-                transientXcbParent = static_cast<const QXcbWindow *>(tp->handle())->winId();
+                transientXcbParent = tp->handle()->winId();
             // Default to client leader if there is no transient parent, else modal dialogs can
             // be hidden by their parents.
             if (!transientXcbParent)
