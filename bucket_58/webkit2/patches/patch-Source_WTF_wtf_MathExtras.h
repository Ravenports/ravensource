--- Source/WTF/wtf/MathExtras.h.orig	2026-02-19 21:54:13 UTC
+++ Source/WTF/wtf/MathExtras.h
@@ -425,7 +425,7 @@ inline void doubleToInteger(double d, un
         value = 0;
     else {
         // -2^{64} < fmodValue < 2^{64}.
-        double fmodValue = fmod(trunc(d), maxPlusOne<unsigned long long>);
+        double fmodValue = fmod(trunc(d), static_cast<double>(maxPlusOne<unsigned long long>));
         if (fmodValue >= 0) {
             // 0 <= fmodValue < 2^{64}.
             // 0 <= value < 2^{64}. This cast causes no loss.
