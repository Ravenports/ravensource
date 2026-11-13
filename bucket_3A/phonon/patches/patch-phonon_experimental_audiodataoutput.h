--- phonon/experimental/audiodataoutput.h.orig	2023-11-02 14:02:07 UTC
+++ phonon/experimental/audiodataoutput.h
@@ -60,7 +60,6 @@ namespace Experimental
     {
         Q_OBJECT
         P_DECLARE_PRIVATE(AudioDataOutput)
-        Q_ENUMS(Channel Format)
         Q_PROPERTY(Format format READ format WRITE setFormat)
         Q_PROPERTY(int dataSize READ dataSize WRITE setDataSize)
         PHONON_HEIR(AudioDataOutput)
@@ -77,6 +76,7 @@ namespace Experimental
                 RightSurroundChannel,
                 SubwooferChannel
             };
+            Q_ENUM(Channel)
 
             /**
              * Used for telling the object whether you want 16 bit Integers or
@@ -100,6 +100,7 @@ namespace Experimental
                  */
                 FloatFormat = 2
             };
+            Q_ENUM(Format)
 
             /**
              * Returns the currently used format.
