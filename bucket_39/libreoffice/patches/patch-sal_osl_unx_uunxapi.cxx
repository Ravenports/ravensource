--- sal/osl/unx/uunxapi.cxx.orig	2026-04-09 16:07:27 UTC
+++ sal/osl/unx/uunxapi.cxx
@@ -618,6 +618,7 @@ std::string UnixErrnoString(int nErrno)
 #pragma clang diagnostic ignored "-Wdeprecated-pragma"
 #endif
 #endif
+#ifdef ENOSTR
         case ENOSTR:
 #if defined __clang__
 #if __has_warning("-Wdeprecated-pragma")
@@ -625,12 +626,14 @@ std::string UnixErrnoString(int nErrno)
 #endif
 #endif
             return "ENOSTR";
+#endif
 #if defined __clang__
 #if __has_warning("-Wdeprecated-pragma")
 #pragma clang diagnostic push
 #pragma clang diagnostic ignored "-Wdeprecated-pragma"
 #endif
 #endif
+#ifdef ENODATA
         case ENODATA:
 #if defined __clang__
 #if __has_warning("-Wdeprecated-pragma")
@@ -638,12 +641,14 @@ std::string UnixErrnoString(int nErrno)
 #endif
 #endif
             return "ENODATA";
+#endif
 #if defined __clang__
 #if __has_warning("-Wdeprecated-pragma")
 #pragma clang diagnostic push
 #pragma clang diagnostic ignored "-Wdeprecated-pragma"
 #endif
 #endif
+#if defined(ETIME) && (!defined(ETIMEDOUT) || ETIME != ETIMEDOUT)
         case ETIME:
 #if defined __clang__
 #if __has_warning("-Wdeprecated-pragma")
@@ -651,12 +656,14 @@ std::string UnixErrnoString(int nErrno)
 #endif
 #endif
             return "ETIME";
+#endif
 #if defined __clang__
 #if __has_warning("-Wdeprecated-pragma")
 #pragma clang diagnostic push
 #pragma clang diagnostic ignored "-Wdeprecated-pragma"
 #endif
 #endif
+#ifdef ENOSR
         case ENOSR:
 #if defined __clang__
 #if __has_warning("-Wdeprecated-pragma")
@@ -664,6 +671,7 @@ std::string UnixErrnoString(int nErrno)
 #endif
 #endif
             return "ENOSR";
+#endif
 #ifdef ENONET
         case ENONET:
             return "ENONET";
