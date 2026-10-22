--- src/libserver/symcache/symcache_impl.cxx.orig	2026-10-10 21:41:28 UTC
+++ src/libserver/symcache/symcache_impl.cxx
@@ -1262,7 +1262,7 @@ auto symcache::counters() const -> ucl_o
 {
 	auto *top = ucl_object_typed_new(UCL_ARRAY);
 	constexpr const auto round_float = [](const auto x, const int digits) -> auto {
-		const auto power10 = ::pow(10, digits);
+		const auto power10 = ::pow(10.0, digits);
 		return (::round(x * power10) / power10);
 	};
 
