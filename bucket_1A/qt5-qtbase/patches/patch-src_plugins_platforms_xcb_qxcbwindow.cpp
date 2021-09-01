--- src/plugins/platforms/xcb/qxcbwindow.cpp.orig	2020-10-27 08:02:11 UTC
+++ src/plugins/platforms/xcb/qxcbwindow.cpp
@@ -698,7 +698,7 @@ void QXcbWindow::show()
         if (isTransient(window())) {
             const QWindow *tp = window()->transientParent();
             if (tp && tp->handle())
-                transientXcbParent = static_cast<const QXcbWindow *>(tp->handle())->winId();
+                transientXcbParent = tp->handle()->winId();
             // Default to client leader if there is no transient parent, else modal dialogs can
             // be hidden by their parents.
             if (!transientXcbParent)
