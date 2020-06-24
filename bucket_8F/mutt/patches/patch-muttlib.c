--- muttlib.c.orig	2020-06-23 18:13:58 UTC
+++ muttlib.c
@@ -930,16 +930,15 @@ void _mutt_buffer_mktemp (BUFFER *buf, c
 void _mutt_mktemp (char *s, size_t slen, const char *prefix, const char *suffix,
                    const char *src, int line)
 {
-  size_t n = snprintf (s, slen, "%s/%s-%s-%d-%d-%ld%ld%s%s",
-                       NONULL (Tempdir), NONULL (prefix), NONULL (Hostname),
-                       (int) getuid (), (int) getpid (), random (), random (),
-                       suffix ? "." : "", NONULL (suffix));
+  size_t n = snprintf (s, slen, "%s/mutt-%s-XXXXXXXX", NONULL (Tempdir), NONULL (Hostname));
   if (n >= slen)
     dprint (1, (debugfile, "%s:%d: ERROR: insufficient buffer space to hold temporary filename! slen=%zu but need %zu\n",
                 src, line, slen, n));
-  dprint (3, (debugfile, "%s:%d: mutt_mktemp returns \"%s\".\n", src, line, s));
-  if (unlink (s) && errno != ENOENT)
-    dprint (1, (debugfile, "%s:%d: ERROR: unlink(\"%s\"): %s (errno %d)\n", src, line, s, strerror (errno), errno));
+  if (mktemp (s)) { 
+    dprint (3, (debugfile, "%s:%d: mutt_mktemp returns \"%s\".\n", src, line, s));
+  } else {
+    dprint (1, (debugfile, "%s:%d: ERROR: mktemp(\"%s\"): %s (errno %d)\n", src, line, s, strerror (errno), errno));
+  }
 }
 
 /* these characters must be escaped in regular expressions */
@@ -1667,7 +1666,16 @@ void mutt_FormatString (char *dest,		/*
       if (*src == '?')
       {
 	flags |= MUTT_FORMAT_OPTIONAL;
-	src++;
+	ch = *(++src); /* save the character to switch on */
+	cp = prefix;
+	++src;
+	count = 0;
+	while (count < sizeof (prefix) && *src != '?')
+	{
+	  *cp++ = *src++;
+	  count++;
+	}
+	*cp = 0;
       }
       else
       {
@@ -1683,12 +1691,12 @@ void mutt_FormatString (char *dest,		/*
 	  count++;
 	}
 	*cp = 0;
-      }
 
-      if (!*src)
-	break; /* bad format */
+	if (!*src)
+	  break; /* bad format */
 
-      ch = *src++; /* save the character to switch on */
+	ch = *src++; /* save the character to switch on */
+      }
 
       if (flags & MUTT_FORMAT_OPTIONAL)
       {
@@ -1701,6 +1709,12 @@ void mutt_FormatString (char *dest,		/*
 	count = 0;
         while (count < sizeof (ifstring) && *src && *src != '?' && *src != '&')
 	{
+	  if (*src == '\\')
+	  {
+	    src++;
+	    if (!*src)
+	      break;
+	  }
           *cp++ = *src++;
 	  count++;
 	}
@@ -1713,7 +1727,13 @@ void mutt_FormatString (char *dest,		/*
 	count = 0;
 	while (count < sizeof (elsestring) && *src && *src != '?')
 	{
-	  *cp++ = *src++;
+	  if (*src == '\\')
+	  {
+	    src++;
+	    if (!*src)
+	      break;
+	  }
+          *cp++ = *src++;
 	  count++;
 	}
 	*cp = 0;
