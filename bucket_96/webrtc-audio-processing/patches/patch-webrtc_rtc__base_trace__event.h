--- webrtc/rtc_base/trace_event.h.orig	2025-01-22 22:32:18 UTC
+++ webrtc/rtc_base/trace_event.h
@@ -11,6 +11,7 @@
 #ifndef RTC_BASE_TRACE_EVENT_H_
 #define RTC_BASE_TRACE_EVENT_H_
 
+#include <cstdint>
 #if defined(RTC_DISABLE_TRACE_EVENTS)
 #define RTC_TRACE_EVENTS_ENABLED 0
 #else
