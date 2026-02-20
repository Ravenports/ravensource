--- include/spdlog/details/os-inl.h.orig	2026-01-04 16:06:01 UTC
+++ include/spdlog/details/os-inl.h
@@ -260,6 +260,22 @@ SPDLOG_INLINE int utc_minutes_offset(con
     auto offset_seconds = utc_time_t - local_time_t;
     return static_cast<int>(offset_seconds / 60);
 }
+#elif defined(__sun__)
+SPDLOG_INLINE int utc_minutes_offset(const std::tm &tm) {
+    // On OmniOS, 'timezone' is a global long representing seconds WEST of UTC.
+    // We negate it to get seconds EAST of UTC, matching tm_gmtoff behavior.
+    
+    // Ensure timezone info is initialized
+    static bool tz_initialized = []() { tzset(); return true; }();
+    
+    // Adjust for Daylight Saving Time if active in the provided tm
+    long offset_seconds = -timezone;
+    if (tm.tm_isdst > 0) {
+        offset_seconds += 3600; // Add 1 hour if DST is in effect
+    }
+    
+    return static_cast<int>(offset_seconds / 60);
+}
 #else
 // On unix simply use tm_gmtoff
 SPDLOG_INLINE int utc_minutes_offset(const std::tm &tm) {
