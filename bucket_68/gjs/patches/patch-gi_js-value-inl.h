--- gi/js-value-inl.h.orig	2026-03-14 03:48:09 UTC
+++ gi/js-value-inl.h
@@ -106,6 +106,22 @@ inline bool js_value_to_c<unsigned short
     return JS::ToUint32(cx, value, out);
 }
 
+#if defined(__sun)
+template <>
+GJS_JSAPI_RETURN_CONVENTION
+inline bool js_value_to_c<char>(JSContext* cx, JS::HandleValue value,
+                                int32_t* out) {
+    return JS::ToInt32(cx, value, out);
+}
+
+template <>
+GJS_JSAPI_RETURN_CONVENTION
+inline bool js_value_to_c<char>(JSContext* cx, JS::HandleValue value,
+                                uint32_t* out) {
+    return JS::ToUint32(cx, value, out);
+}
+#endif
+
 template <>
 GJS_JSAPI_RETURN_CONVENTION
 inline bool js_value_to_c<uint32_t>(JSContext* cx, JS::HandleValue value,
