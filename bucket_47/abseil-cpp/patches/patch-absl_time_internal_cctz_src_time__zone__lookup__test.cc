--- absl/time/internal/cctz/src/time_zone_lookup_test.cc.orig	2023-05-04 14:32:38 UTC
+++ absl/time/internal/cctz/src/time_zone_lookup_test.cc
@@ -1026,7 +1026,7 @@ TEST(MakeTime, SysSecondsLimits) {
     const time_zone cut = LoadZone("libc:UTC");
     const year_t max_tm_year = year_t{std::numeric_limits<int>::max()} + 1900;
     tp = convert(civil_second(max_tm_year, 12, 31, 23, 59, 59), cut);
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
     // The BSD gmtime_r() fails on extreme positive tm_year values.
 #else
     EXPECT_EQ("2147485547-12-31T23:59:59+00:00", format(RFC3339, tp, cut));
