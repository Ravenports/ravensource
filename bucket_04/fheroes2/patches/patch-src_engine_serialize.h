--- src/engine/serialize.h.orig	2026-11-08 12:34:15 UTC
+++ src/engine/serialize.h
@@ -181,7 +181,9 @@ public:
 
     IStreamBase & operator>>( bool & v );
     IStreamBase & operator>>( char & v );
+#if !(defined(__sun) && defined(_CHAR_IS_SIGNED))
     IStreamBase & operator>>( int8_t & v );
+#endif
     IStreamBase & operator>>( uint8_t & v );
     IStreamBase & operator>>( int16_t & v );
     IStreamBase & operator>>( uint16_t & v );
@@ -331,7 +333,9 @@ public:
 
     OStreamBase & operator<<( const bool v );
     OStreamBase & operator<<( const char v );
+#if !(defined(__sun) && defined(_CHAR_IS_SIGNED))
     OStreamBase & operator<<( const int8_t v );
+#endif
     OStreamBase & operator<<( const uint8_t v );
     OStreamBase & operator<<( const int16_t v );
     OStreamBase & operator<<( const uint16_t v );
