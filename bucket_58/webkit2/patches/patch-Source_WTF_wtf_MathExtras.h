--- Source/WTF/wtf/MathExtras.h.orig	2026-04-07 13:12:48 UTC
+++ Source/WTF/wtf/MathExtras.h
@@ -424,7 +424,7 @@ inline void doubleToInteger(double d, un
         value = 0;
     else {
         // -2^{64} < fmodValue < 2^{64}.
-        double fmodValue = fmod(trunc(d), maxPlusOne<unsigned long long>);
+        double fmodValue = fmod(trunc(d), static_cast<double>(maxPlusOne<unsigned long long>));
         if (fmodValue >= 0) {
             // 0 <= fmodValue < 2^{64}.
             // 0 <= value < 2^{64}. This cast causes no loss.
