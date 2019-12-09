--- glib/gmacros.h.orig	2019-11-19 17:51:31 UTC
+++ glib/gmacros.h
@@ -734,12 +734,12 @@
 #ifndef __GI_SCANNER__ /* The static assert macro really confuses the introspection parser */
 #define G_PASTE_ARGS(identifier1,identifier2) identifier1 ## identifier2
 #define G_PASTE(identifier1,identifier2)      G_PASTE_ARGS (identifier1, identifier2)
-#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
-#define G_STATIC_ASSERT(expr) _Static_assert (expr, "Expression evaluates to false")
-#elif (defined(__cplusplus) && __cplusplus >= 201103L) || \
+#if (defined(__cplusplus) && __cplusplus >= 201103L) || \
       (defined(__cplusplus) && defined (_MSC_VER) && (_MSC_VER >= 1600)) || \
       (defined (_MSC_VER) && (_MSC_VER >= 1800))
 #define G_STATIC_ASSERT(expr) static_assert (expr, "Expression evaluates to false")
+#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
+#define G_STATIC_ASSERT(expr) _Static_assert (expr, "Expression evaluates to false")
 #else
 #ifdef __COUNTER__
 #define G_STATIC_ASSERT(expr) typedef char G_PASTE (_GStaticAssertCompileTimeAssertion_, __COUNTER__)[(expr) ? 1 : -1] G_GNUC_UNUSED
