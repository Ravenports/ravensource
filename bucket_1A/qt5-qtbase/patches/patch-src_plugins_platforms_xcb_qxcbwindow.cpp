--- src/plugins/platforms/xcb/qxcbwindow.cpp.orig	2023-03-23 19:06:47 UTC
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
