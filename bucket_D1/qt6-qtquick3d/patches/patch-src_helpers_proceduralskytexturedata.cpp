--- src/helpers/proceduralskytexturedata.cpp.orig	2025-11-13 21:08:45 UTC
+++ src/helpers/proceduralskytexturedata.cpp
@@ -408,11 +408,11 @@ QByteArray ProceduralSkyTextureData::gen
     sunLinear.g *= m_sunEnergy;
     sunLinear.b *= m_sunEnergy;
 
-    QVector3D sun(0, 0, -1);
+    QVector3D xsun(0, 0, -1);
 
-    sun = QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), m_sunLatitude) * sun;
-    sun = QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), m_sunLongitude) * sun;
-    sun.normalize();
+    xsun = QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), m_sunLatitude) * xsun;
+    xsun = QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), m_sunLongitude) * xsun;
+    xsun.normalize();
 
     auto clamp = [](float value, float min, float max) {
         if (value < min)
@@ -474,7 +474,7 @@ QByteArray ProceduralSkyTextureData::gen
                 color.g *= m_skyEnergy;
                 color.b *= m_skyEnergy;
 
-                float sunAngle = qRadiansToDegrees(qAcos(clamp(QVector3D::dotProduct(sun, normal), -1.0f, 1.0f)));
+                float sunAngle = qRadiansToDegrees(qAcos(clamp(QVector3D::dotProduct(xsun, normal), -1.0f, 1.0f)));
                 if (sunAngle < m_sunAngleMin) {
                     color = color.blend(sunLinear);
                 } else if (sunAngle < m_sunAngleMax) {
