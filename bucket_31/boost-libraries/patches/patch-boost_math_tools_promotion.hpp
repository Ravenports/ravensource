Remove the guard; long double should be allowed as a type, even when
long double math functions are not present. Allows py-scipy to build.

--- boost/math/tools/promotion.hpp.orig	2025-08-06 18:49:11 UTC
+++ boost/math/tools/promotion.hpp
@@ -117,12 +117,6 @@ namespace boost
       template <class... Args>
       struct promote_args {
          using type = typename promote_args_permissive<Args...>::type;
-#if defined(BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS)
-         //
-         // Guard against use of long double if it's not supported:
-         //
-         static_assert((0 == boost::math::is_same<type, long double>::value), "Sorry, but this platform does not have sufficient long double support for the special functions to be reliably implemented.");
-#endif
       };
 
       template <class... Args>
