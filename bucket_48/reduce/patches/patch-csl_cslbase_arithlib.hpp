--- csl/cslbase/arithlib.hpp.orig	2023-08-18 15:27:13 UTC
+++ csl/cslbase/arithlib.hpp
@@ -3642,7 +3642,7 @@ inline int nlz(std::uint64_t x)
 {   return __builtin_clzll(x);  // Must use the 64-bit version of clz.
 }
 
-inline int popcount(std::uint64_t x)
+inline int my_popcount(std::uint64_t x)
 {   return __builtin_popcountll(x);
 }
 
@@ -3670,7 +3670,7 @@ inline int nlz(uint64_t x)
     return nlzTable[x % 67];
 }
 
-inline int popcount(std::uint64_t x)
+inline int my_popcount(std::uint64_t x)
 {   x = (x & 0x5555555555555555U) + ((x >> 1) & 0x5555555555555555U);
     x = (x & 0x3333333333333333U) + ((x >> 2) & 0x3333333333333333U);
     x = x + ((x >> 4) & 0x0f0f0f0f0f0f0f0fU);
@@ -7662,15 +7662,15 @@ inline std::size_t Logcount::op(std::uin
 {   std::size_t lena = numberSize(a);
     std::size_t r = 0;
     if (negative(a[lena-1]))
-    {   for (std::size_t i=0; i<lena; i++) r += popcount(~a[i]);
+    {   for (std::size_t i=0; i<lena; i++) r += my_popcount(~a[i]);
     }
-    else for (std::size_t i=0; i<lena; i++) r += popcount(a[i]);
+    else for (std::size_t i=0; i<lena; i++) r += my_popcount(a[i]);
     return r;
 }
 
 inline std::size_t Logcount::op(std::int64_t a)
-{   if (a < 0) return popcount(~a);
-    else return popcount(a);
+{   if (a < 0) return my_popcount(~a);
+    else return my_popcount(a);
 }
 
 inline bool Logbitp::op(std::uint64_t* a, std::size_t n)
