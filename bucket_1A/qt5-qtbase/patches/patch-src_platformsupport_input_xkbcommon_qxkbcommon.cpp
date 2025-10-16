--- src/platformsupport/input/xkbcommon/qxkbcommon.cpp.orig	2023-04-24 13:43:14 UTC
+++ src/platformsupport/input/xkbcommon/qxkbcommon.cpp
@@ -273,10 +273,14 @@ static constexpr const auto KeyTbl = qMa
         Xkb2Qt<XKB_KEY_dead_small_schwa,        Qt::Key_Dead_Small_Schwa>,
         Xkb2Qt<XKB_KEY_dead_capital_schwa,      Qt::Key_Dead_Capital_Schwa>,
         Xkb2Qt<XKB_KEY_dead_greek,              Qt::Key_Dead_Greek>,
+/* The following four XKB_KEY_dead keys got removed in libxkbcommon 1.6.0
+   The define check is kind of version check here. */
+#ifdef XKB_KEY_dead_lowline
         Xkb2Qt<XKB_KEY_dead_lowline,            Qt::Key_Dead_Lowline>,
         Xkb2Qt<XKB_KEY_dead_aboveverticalline,  Qt::Key_Dead_Aboveverticalline>,
         Xkb2Qt<XKB_KEY_dead_belowverticalline,  Qt::Key_Dead_Belowverticalline>,
         Xkb2Qt<XKB_KEY_dead_longsolidusoverlay, Qt::Key_Dead_Longsolidusoverlay>,
+#endif
 
         // Special keys from X.org - This include multimedia keys,
         // wireless/bluetooth/uwb keys, special launcher keys, etc.
