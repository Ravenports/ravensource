--- csl/cslbase/arith08.cpp.orig	2023-01-02 21:45:46 UTC
+++ csl/cslbase/arith08.cpp
@@ -880,13 +880,13 @@ inline int nlz(uint64_t x)
 #ifndef POPCOUNT_DEFINED
 #ifdef __GNUC__
 
-inline int popcount(uint64_t x)
+inline int my_popcount(uint64_t x)
 {   return __builtin_popcountll(x);
 }
 
 #else // __GNUC__
 
-inline int popcount(uint64_t x)
+inline int my_popcount(uint64_t x)
 {   x = (x & 0x5555555555555555U) + (x >> 1 & 0x5555555555555555U);
     x = (x & 0x3333333333333333U) + (x >> 2 & 0x3333333333333333U);
     x = x + (x >> 4) & 0x0f0f0f0f0f0f0f0fU;
@@ -902,19 +902,19 @@ static LispObject Llogcount(LispObject e
 {   SingleValued fn;
     if (is_fixnum(a))
     {   intptr_t n = int_of_fixnum(a);
-        if (a >= 0) return fixnum_of_int(popcount(n));
-        else return fixnum_of_int(popcount(~n));
+        if (a >= 0) return fixnum_of_int(my_popcount(n));
+        else return fixnum_of_int(my_popcount(~n));
     }
     else if (is_bignum(a))
     {   size_t len = (length_of_header(numhdr(a)) - CELL)/4;
         int n = 0;
         if ((int32_t)bignum_digits(a)[len-1] < 0)
         {   for (size_t i=0; i<len; i++)
-                n += popcount(~bignum_digits(a)[i]);
+                n += my_popcount(~bignum_digits(a)[i]);
         }
         else
         {   for (size_t i=0; i<len; i++)
-                n += popcount(bignum_digits(a)[i]);
+                n += my_popcount(bignum_digits(a)[i]);
         }
         return fixnum_of_int(n);
     }
