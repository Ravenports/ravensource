--- src/core/CLucene/util/BitSet.h.orig	2011-03-17 00:21:07 UTC
+++ src/core/CLucene/util/BitSet.h
@@ -39,6 +39,7 @@ class CLUCENE_EXPORT BitSet:LUCENE_BASE
   /** Indicates if the bit vector is sparse and should be saved as a d-gaps list, or dense, and should be saved as a bit set. */
   bool isSparse();
   static const uint8_t BYTE_COUNTS[256];
+  static const uint8_t BYTE_OFFSETS[256];
 protected:
 	BitSet( const BitSet& copy );
 
