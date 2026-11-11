--- src/corelib/global/qfloat16.h.orig	2026-06-04 16:29:11 UTC
+++ src/corelib/global/qfloat16.h
@@ -111,7 +111,11 @@ public:
     // Support for std::numeric_limits<qfloat16>
 #ifdef __STDCPP_FLOAT16_T__
 private:
+#if QFLOAT16_IS_NATIVE
     using Bounds = std::numeric_limits<NativeType>;
+#else
+    using Bounds = std::numeric_limits<float>;
+#endif
 public:
     static constexpr qfloat16 _limit_epsilon()    noexcept { return Bounds::epsilon(); }
     static constexpr qfloat16 _limit_min()        noexcept { return Bounds::min(); }
