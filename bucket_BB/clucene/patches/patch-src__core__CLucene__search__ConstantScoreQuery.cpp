--- src/core/CLucene/search/ConstantScoreQuery.cpp.orig	2011-03-17 00:21:07 UTC
+++ src/core/CLucene/search/ConstantScoreQuery.cpp
@@ -25,14 +25,17 @@ class ConstantScorer : public Scorer {
     BitSet* bits;
     const float_t theScore;
     int32_t _doc;
+    bool shouldDelete;
 
 public:
     ConstantScorer(Similarity* similarity, IndexReader* reader, Weight* w, Filter* filter) : Scorer(similarity),
         bits(filter->bits(reader)), theScore(w->getValue()), _doc(-1)
     {
+        shouldDelete = filter->shouldDeleteBitSet(bits);
     }
     virtual ~ConstantScorer() {
-        _CLLDELETE(bits);
+        if ( shouldDelete)
+            _CLLDELETE(bits);
     }
 
     bool next() {
