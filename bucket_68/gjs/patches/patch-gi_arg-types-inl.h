--- gi/arg-types-inl.h.orig	2026-03-14 03:48:09 UTC
+++ gi/arg-types-inl.h
@@ -70,6 +70,18 @@ struct MarshallingInfo<bool> {
     static constexpr const char* name = "bool";
 };
 
+#if defined(__sun)
+// Fix for signed char (which is distinct from int8_t/char on OmniOS)
+template <>
+struct MarshallingInfo<signed char> {
+    using real_type = signed char;
+    using containing_tag = int32_t;
+    using jsvalue_pack_type = int32_t;
+    static constexpr GITypeTag gi_tag = GI_TYPE_TAG_INT8;
+    static constexpr const char* name = "int8";
+};
+#endif
+
 template <>
 struct MarshallingInfo<int8_t> {
     using real_type = int8_t;
