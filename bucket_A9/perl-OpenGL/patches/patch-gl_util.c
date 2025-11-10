--- gl_util.c.orig	2025-04-14 04:33:29 UTC
+++ gl_util.c
@@ -759,6 +759,12 @@ int gl_component_count(GLenum format, GL
 
 /* 18 */
 #ifdef GL_EXT_cmyka
+# ifndef GL_CMYK
+#  define GL_CMYK GL_CMYK_EXT
+# endif
+# ifndef GL_CMYKA
+#  define GL_CMYKA GL_CMYKA_EXT
+# endif
 		case GL_CMYK:
 			n = 4; break;
 		case GL_CMYKA:
