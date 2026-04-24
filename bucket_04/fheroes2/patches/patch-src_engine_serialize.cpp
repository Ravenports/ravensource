--- src/engine/serialize.cpp.orig	2026-04-12 03:02:21 UTC
+++ src/engine/serialize.cpp
@@ -90,12 +90,14 @@ IStreamBase & IStreamBase::operator>>( c
     return *this;
 }
 
+#if !(defined(__sun) && defined(_CHAR_IS_SIGNED))
 IStreamBase & IStreamBase::operator>>( int8_t & v )
 {
     v = static_cast<int8_t>( get8() );
 
     return *this;
 }
+#endif
 
 IStreamBase & IStreamBase::operator>>( uint8_t & v )
 {
@@ -170,12 +172,14 @@ OStreamBase & OStreamBase::operator<<( c
     return *this;
 }
 
+#if !(defined(__sun) && defined(_CHAR_IS_SIGNED))
 OStreamBase & OStreamBase::operator<<( const int8_t v )
 {
     put8( static_cast<uint8_t>( v ) );
 
     return *this;
 }
+#endif
 
 OStreamBase & OStreamBase::operator<<( const uint8_t v )
 {
