--- gi/arg-inl.h.orig	2026-03-14 03:48:09 UTC
+++ gi/arg-inl.h
@@ -125,6 +125,16 @@ constexpr decltype(auto) gjs_arg_member(
     }
 }
 
+#if defined(__sun)
+inline void gjs_arg_set(GIArgument* arg, signed char v) {
+    arg->v_int8 = v;
+}
+
+inline signed char gjs_arg_get(const GIArgument* arg, signed char) {
+    return arg->v_int8;
+}
+#endif
+
 template <typename TAG, typename = std::enable_if_t<
                             std::is_arithmetic_v<Gjs::Tag::RealT<TAG>>>>
 constexpr void gjs_arg_set(GIArgument* arg, Gjs::Tag::RealT<TAG> v) {
