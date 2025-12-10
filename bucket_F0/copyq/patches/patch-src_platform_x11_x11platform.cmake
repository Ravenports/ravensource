--- src/platform/x11/x11platform.cmake.orig	2025-10-22 07:58:33 UTC
+++ src/platform/x11/x11platform.cmake
@@ -42,7 +42,7 @@ if (WITH_X11)
         if (QT_VERSION VERSION_GREATER_EQUAL "6.10.0")
             find_package(${copyq_qt} ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS GuiPrivate)
         endif()
-        list(APPEND copyq_LIBRARIES Qt::GuiPrivate)
+        list(APPEND copyq_LIBRARIES Qt::Gui)
     else()
         list(APPEND copyq_qt_modules X11Extras)
     endif()
