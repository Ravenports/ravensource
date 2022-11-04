--- lib/string.in.h.orig	2022-04-07 02:15:05 UTC
+++ lib/string.in.h
@@ -569,7 +569,7 @@ _GL_FUNCDECL_RPL (strndup, char *,
                   _GL_ATTRIBUTE_MALLOC _GL_ATTRIBUTE_DEALLOC_FREE);
 _GL_CXXALIAS_RPL (strndup, char *, (char const *__s, size_t __n));
 # else
-#  if !@HAVE_DECL_STRNDUP@ || __GNUC__ >= 11
+#  if !@HAVE_DECL_STRNDUP@ || (__GNUC__ >= 11 && !defined strndup)
 _GL_FUNCDECL_SYS (strndup, char *,
                   (char const *__s, size_t __n)
                   _GL_ARG_NONNULL ((1))
@@ -579,7 +579,7 @@ _GL_CXXALIAS_SYS (strndup, char *, (char
 # endif
 _GL_CXXALIASWARN (strndup);
 #else
-# if __GNUC__ >= 11
+# if __GNUC__ >= 11 && !defined strndup
 /* For -Wmismatched-dealloc: Associate strndup with free or rpl_free.  */
 _GL_FUNCDECL_SYS (strndup, char *,
                   (char const *__s, size_t __n)
