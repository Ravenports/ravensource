--- src/core/Totp.cpp.orig	2026-10-21 20:21:09 UTC
+++ src/core/Totp.cpp
@@ -284,7 +284,8 @@ QString Totp::generateTotp(const QShared
         direction = 1;
         startpos = 0;
     }
-    quint32 digitsPower = pow(encoder.alphabet.size(), digits);
+    quint32 digitsPower = pow(static_cast<double>(encoder.alphabet.size()),
+		static_cast<int>(digits));
 
     quint64 password = binary % digitsPower;
     QString retval(int(digits), encoder.alphabet[0]);
