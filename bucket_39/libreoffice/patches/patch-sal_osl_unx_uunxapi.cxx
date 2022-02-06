--- sal/osl/unx/uunxapi.cxx.orig	2022-01-26 14:35:29 UTC
+++ sal/osl/unx/uunxapi.cxx
@@ -599,14 +599,22 @@ std::string UnixErrnoString(int nErrno)
         case EBFONT:
             return "EBFONT";
 #endif
+#ifdef ENOSTR
         case ENOSTR:
             return "ENOSTR";
+#endif
+#ifdef ENODATA
         case ENODATA:
             return "ENODATA";
+#endif
+#if defined(ETIME) && (!defined(ETIMEDOUT) || ETIME != ETIMEDOUT)
         case ETIME:
             return "ETIME";
+#endif
+#ifdef ENOSR
         case ENOSR:
             return "ENOSR";
+#endif
 #ifdef ENONET
         case ENONET:
             return "ENONET";
