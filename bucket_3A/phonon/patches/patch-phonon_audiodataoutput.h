--- phonon/audiodataoutput.h.orig	2023-11-02 14:02:07 UTC
+++ phonon/audiodataoutput.h
@@ -54,7 +54,6 @@ namespace Phonon
     {
         Q_OBJECT
         P_DECLARE_PRIVATE(AudioDataOutput)
-        Q_ENUMS(Channel)
         Q_PROPERTY(int dataSize READ dataSize WRITE setDataSize)
         PHONON_HEIR(AudioDataOutput)
         public:
@@ -70,6 +69,7 @@ namespace Phonon
                 RightSurroundChannel,
                 SubwooferChannel
             };
+            Q_ENUM(Channel)
 
             /**
              * Returns the currently used number of samples passed through
