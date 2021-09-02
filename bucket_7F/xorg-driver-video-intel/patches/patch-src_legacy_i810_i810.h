--- src/legacy/i810/i810.h.orig	2018-12-03 09:01:25 UTC
+++ src/legacy/i810/i810.h
@@ -322,6 +322,5 @@ extern void I810InitMC(ScreenPtr pScreen
 extern const OptionInfoRec *I810AvailableOptions(int chipid, int busid);
 
 extern const int I810CopyROP[16];
-const int I810PatternROP[16];
 
 #endif /* _I810_H_ */
