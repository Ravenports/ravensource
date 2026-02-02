Toggle symbol visibility, otherwise certain symbols are marked as local
which are actually supposed to be used (e.g. by gjs):

void js::UnsafeTraceManuallyBarrieredEdge<jsid>(JSTracer*, jsid*, char const*)
void JS::TraceEdge<JSObject*>(JSTracer*, JS::Heap<JSObject*>*, char const*)
void js::UnsafeTraceManuallyBarrieredEdge<JSObject*>(JSTracer*, JSObject**, char const*)
void js::UnsafeTraceManuallyBarrieredEdge<JS::Value>(JSTracer*, JS::Value*, char const*)

--- ../../config/gcc_hidden.h.orig	2026-01-06 21:09:41 UTC
+++ ../../config/gcc_hidden.h
@@ -3,4 +3,4 @@
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 /* Begin all files as hidden visibility */
-#pragma GCC visibility push(hidden)
+#pragma GCC visibility push(default)
