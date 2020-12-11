--- src/util.cpp.orig	2020-11-30 06:30:26 UTC
+++ src/util.cpp
@@ -125,53 +125,16 @@ int confirm4 (const std::string& questio
   return 0;
 }
 
-// Handle the generation of UUIDs on FreeBSD in a separate implementation
-// of the uuid () function, since the API is quite different from Linux's.
-// Also, uuid_unparse_lower is not needed on FreeBSD, because the string
-// representation is always lowercase anyway.
-// For the implementation details, refer to
-// http://svnweb.freebsd.org/base/head/sys/kern/kern_uuid.c
-#if defined(FREEBSD) || defined(OPENBSD)
-const std::string uuid ()
-{
-  uuid_t id;
-  uint32_t status;
-  char *buffer (0);
-  uuid_create (&id, &status);
-  uuid_to_string (&id, &buffer, &status);
-
-  std::string res (buffer);
-  free (buffer);
-
-  return res;
-}
-#else
-
-////////////////////////////////////////////////////////////////////////////////
-#ifndef HAVE_UUID_UNPARSE_LOWER
-// Older versions of libuuid don't have uuid_unparse_lower(), only uuid_unparse()
-void uuid_unparse_lower (uuid_t uu, char *out)
-{
-    uuid_unparse (uu, out);
-    // Characters in out are either 0-9, a-z, '-', or A-Z.  A-Z is mapped to
-    // a-z by bitwise or with 0x20, and the others already have this bit set
-    for (size_t i = 0; i < 36; ++i) out[i] |= 0x20;
-}
-#endif
-
-const std::string uuid ()
-{
-  uuid_t id;
-  uuid_generate (id);
-  char buffer[100] {};
-  uuid_unparse_lower (id, buffer);
-
-  // Bug found by Steven de Brouwer.
-  buffer[36] = '\0';
-
-  return std::string (buffer);
-}
-#endif
+ // call to OSSP-UUID
+ const std::string make_uuid ()
+ {
+   uuid id;
+   id.make(UUID_MAKE_V4);
+   const char * idstr = id.string();
+   std::string res (idstr);
+   delete idstr;
+   return res; 
+ }
 
 // Collides with std::numeric_limits methods
 #undef max
