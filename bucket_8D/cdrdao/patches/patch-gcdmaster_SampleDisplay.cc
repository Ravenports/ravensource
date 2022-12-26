--- gcdmaster/SampleDisplay.cc.orig	2018-05-16 10:25:12 UTC
+++ gcdmaster/SampleDisplay.cc
@@ -1025,8 +1025,6 @@ void SampleDisplay::updateSamples()
 
 	}
 
-	if (&pixmap_ == 0)
-	  std::cout << "null !!" << std::endl;
 
 	if (0 && (gint)di < sampleEndX_) {
 	  pos = sampleBuf[len -1].left() * halfHeight;
