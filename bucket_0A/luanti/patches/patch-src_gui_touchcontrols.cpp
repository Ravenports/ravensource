--- src/gui/touchcontrols.cpp.orig	2026-02-08 11:42:38 UTC
+++ src/gui/touchcontrols.cpp
@@ -620,7 +620,7 @@ void TouchControls::translateEvent(const
 					(!m_fixed_joystick && distance_sq > touch_threshold_sq)) {
 				m_joystick_has_really_moved = true;
 
-				m_joystick_direction = atan2(dir.X, -dir.Y);
+				m_joystick_direction = atan2((float)dir.X, (float)-dir.Y);
 
 				const double distance = sqrt(distance_sq);
 				if (distance <= m_touchscreen_threshold) {
