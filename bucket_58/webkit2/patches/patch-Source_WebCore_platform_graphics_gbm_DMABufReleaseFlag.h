--- Source/WebCore/platform/graphics/gbm/DMABufReleaseFlag.h.orig	2023-09-19 08:27:49 UTC
+++ Source/WebCore/platform/graphics/gbm/DMABufReleaseFlag.h
@@ -26,7 +26,9 @@
 
 #pragma once
 
+#if !defined(__DragonFly__) && !defined(__NetBSD__) && !defined(__MidnightBSD__)
 #include <sys/eventfd.h>
+#endif
 #include <wtf/Noncopyable.h>
 #include <wtf/SafeStrerror.h>
 #include <wtf/text/CString.h>
@@ -42,7 +44,11 @@ struct DMABufReleaseFlag {
     enum InitializeTag { Initialize };
     DMABufReleaseFlag(InitializeTag)
     {
+#if !defined(__DragonFly__) && !defined(__NetBSD__) && !defined(__MidnightBSD__)
         fd = { eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK), UnixFileDescriptor::Adopt };
+#else
+	fd = { -1, UnixFileDescriptor::Adopt };
+#endif
     }
 
     ~DMABufReleaseFlag() = default;
