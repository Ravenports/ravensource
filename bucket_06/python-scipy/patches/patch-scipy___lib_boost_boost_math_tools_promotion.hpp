Remove the guard; long double should be allowed as a type, even when
long double math functions are not present.

--- scipy/_lib/boost/boost/math/tools/promotion.hpp.orig	1970-01-01 00:00:00 UTC
+++ scipy/_lib/boost/boost/math/tools/promotion.hpp
@@ -141,12 +141,6 @@ namespace boost
             >::type
          >::type type;
 
-#ifdef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
-         //
-         // Guard against use of long double if it's not supported:
-         //
-         BOOST_STATIC_ASSERT_MSG((0 == ::boost::is_same<type, long double>::value), "Sorry, but this platform does not have sufficient long double support for the special functions to be reliably implemented.");
-#endif
       };
 
       //
