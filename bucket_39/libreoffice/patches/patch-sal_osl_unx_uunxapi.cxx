--- sal/osl/unx/uunxapi.cxx.orig	2025-03-21 15:34:31 UTC
+++ sal/osl/unx/uunxapi.cxx
@@ -615,6 +615,7 @@ std::string UnixErrnoString(int nErrno)
 #pragma clang diagnostic ignored "-Wdeprecated-pragma"
 #endif
 #endif
+#ifdef ENOSTR
         case ENOSTR:
 #if defined __clang__
 #if __has_warning("-Wdeprecated-pragma")
@@ -622,12 +623,14 @@ std::string UnixErrnoString(int nErrno)
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
@@ -635,12 +638,14 @@ std::string UnixErrnoString(int nErrno)
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
@@ -648,12 +653,14 @@ std::string UnixErrnoString(int nErrno)
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
@@ -661,6 +668,7 @@ std::string UnixErrnoString(int nErrno)
 #endif
 #endif
             return "ENOSR";
+#endif
 #ifdef ENONET
         case ENONET:
             return "ENONET";
