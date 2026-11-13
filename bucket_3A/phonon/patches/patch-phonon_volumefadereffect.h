--- phonon/volumefadereffect.h.orig	2023-11-02 14:02:07 UTC
+++ phonon/volumefadereffect.h
@@ -50,7 +50,6 @@ namespace Phonon
         Q_OBJECT
         P_DECLARE_PRIVATE(VolumeFaderEffect)
         PHONON_HEIR(VolumeFaderEffect)
-        Q_ENUMS(FadeCurve)
         /**
          * This is the current volume of the output as voltage factor.
          * Setting this property changes the volume immediately.
@@ -121,6 +120,7 @@ namespace Phonon
                  */
                 Fade12Decibel
             };
+            Q_ENUM(FadeCurve)
 
             float volume() const;
             double volumeDecibel() const;
