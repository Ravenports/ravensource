--- Source/WebCore/loader/DocumentLoader.cpp.orig	2026-04-10 09:30:55 UTC
+++ Source/WebCore/loader/DocumentLoader.cpp
@@ -53,6 +53,7 @@
 #include "DocumentWriter.h"
 #include "ElementChildIteratorInlines.h"
 #include "Event.h"
+#include "EventLoop.h"
 #include "EventNames.h"
 #include "ExtensionStyleSheets.h"
 #include "FormSubmission.h"
