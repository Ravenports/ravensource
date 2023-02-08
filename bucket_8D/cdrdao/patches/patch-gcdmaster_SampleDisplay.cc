--- gcdmaster/SampleDisplay.cc.orig	2023-02-03 14:46:06 UTC
+++ gcdmaster/SampleDisplay.cc
@@ -905,8 +905,6 @@ void SampleDisplay::updateSamples()
                 rcenter_ - pos1);
         }
 
-        if (&pixmap_ == 0)
-          std::cout << "null !!" << std::endl;
 
         if (0 && (gint) di < sampleEndX_) {
           pos = sampleBuf[len - 1].left() * halfHeight;
