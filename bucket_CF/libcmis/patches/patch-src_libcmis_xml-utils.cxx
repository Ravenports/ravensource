--- src/libcmis/xml-utils.cxx.orig	2023-11-13 20:06:58 UTC
+++ src/libcmis/xml-utils.cxx
@@ -536,7 +536,7 @@ namespace libcmis
         sha1.process_bytes( str.c_str(), str.size() );
 
         unsigned int digest[5];
-        sha1.get_digest( digest );
+        sha1.get_digest( reinterpret_cast<boost::uuids::detail::sha1::digest_type&>(digest) );
 
         stringstream out;
         // Setup writing mode. Every number must produce eight
