--- lib/string.in.h.orig	2022-02-26 16:22:13 UTC
+++ lib/string.in.h
@@ -569,12 +569,6 @@ _GL_FUNCDECL_RPL (strndup, char *,
                   _GL_ATTRIBUTE_MALLOC _GL_ATTRIBUTE_DEALLOC_FREE);
 _GL_CXXALIAS_RPL (strndup, char *, (char const *__s, size_t __n));
 # else
-#  if !@HAVE_DECL_STRNDUP@ || __GNUC__ >= 11
-_GL_FUNCDECL_SYS (strndup, char *,
-                  (char const *__s, size_t __n)
-                  _GL_ARG_NONNULL ((1))
-                  _GL_ATTRIBUTE_MALLOC _GL_ATTRIBUTE_DEALLOC_FREE);
-#  endif
 _GL_CXXALIAS_SYS (strndup, char *, (char const *__s, size_t __n));
 # endif
 _GL_CXXALIASWARN (strndup);
