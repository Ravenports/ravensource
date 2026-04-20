--- src/libserver/symcache/symcache_impl.cxx.orig	2026-01-08 13:17:41 UTC
+++ src/libserver/symcache/symcache_impl.cxx
@@ -1030,7 +1030,7 @@ auto symcache::counters() const -> ucl_o
 {
 	auto *top = ucl_object_typed_new(UCL_ARRAY);
 	constexpr const auto round_float = [](const auto x, const int digits) -> auto {
-		const auto power10 = ::pow(10, digits);
+		const auto power10 = ::pow(10.0, digits);
 		return (::floor(x * power10) / power10);
 	};
 
