--- phonon/videowidget.h.orig	2023-11-02 14:02:07 UTC
+++ phonon/videowidget.h
@@ -55,7 +55,6 @@ class AbstractVideoOutput;
     {
         P_DECLARE_PRIVATE(VideoWidget)
         Q_OBJECT
-        Q_ENUMS(AspectRatio ScaleMode)
         /**
          * This property holds whether the video is shown using the complete
          * screen.
@@ -152,11 +151,13 @@ class AbstractVideoOutput;
 //X                  */
 //X                 AspectRatioSquare = 4,
             };
+            Q_ENUM(AspectRatio)
 
             enum ScaleMode {
                 FitInView = 0,
                 ScaleAndCrop = 1
             };
+            Q_ENUM(ScaleMode)
 
             /**
              * Constructs a new video widget with a \p parent.
