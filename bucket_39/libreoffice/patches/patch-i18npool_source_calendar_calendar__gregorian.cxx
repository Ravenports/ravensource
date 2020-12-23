--- i18npool/source/calendar/calendar_gregorian.cxx.orig	2020-08-12 13:23:59 UTC
+++ i18npool/source/calendar/calendar_gregorian.cxx
@@ -347,7 +347,13 @@ Calendar_gregorian::setLocalDateTime( do
             "Calendar_gregorian::setLocalDateTime: " << std::fixed << fM << " rounded to " << fR);
     int32_t nZoneOffset, nDSTOffset;
     UErrorCode status = U_ZERO_ERROR;
-    body->getTimeZone().getOffset( fR, TRUE, nZoneOffset, nDSTOffset, status );
+    body->getTimeZone().getOffset( fR,
+#if U_ICU_VERSION_MAJOR_NUM >= 68
+    true,
+#else
+    TRUE,
+#endif
+    nZoneOffset, nDSTOffset, status );
     if ( !U_SUCCESS(status) ) throw ERROR;
     status = U_ZERO_ERROR;
     body->setTime( fR - (nZoneOffset + nDSTOffset), status );
