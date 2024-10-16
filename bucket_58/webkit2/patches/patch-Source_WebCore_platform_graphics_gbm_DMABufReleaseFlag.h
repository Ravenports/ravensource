--- Source/WebCore/platform/graphics/gbm/DMABufReleaseFlag.h.orig	2024-08-19 06:28:39 UTC
+++ Source/WebCore/platform/graphics/gbm/DMABufReleaseFlag.h
@@ -26,7 +26,9 @@
 
 #pragma once
 
+#if !defined(__DragonFly__) && !defined(__NetBSD__) && !defined(__MidnightBSD__)
 #include <sys/eventfd.h>
+#endif
 #include <wtf/Noncopyable.h>
 #include <wtf/SafeStrerror.h>
 #include <wtf/text/CString.h>
@@ -45,7 +47,11 @@ struct DMABufReleaseFlag {
 
     enum InitializeTag { Initialize };
     DMABufReleaseFlag(InitializeTag)
+#if !defined(__DragonFly__) && !defined(__NetBSD__) && !defined(__MidnightBSD__)
         : fd { eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK), UnixFileDescriptor::Adopt }
+#else
+        : fd { -1, UnixFileDescriptor::Adopt }
+#endif
     { }
 
     ~DMABufReleaseFlag() = default;
