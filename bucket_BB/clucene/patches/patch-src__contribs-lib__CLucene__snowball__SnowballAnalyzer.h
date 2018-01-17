--- src/contribs-lib/CLucene/snowball/SnowballAnalyzer.h.orig	2011-03-17 00:21:07 UTC
+++ src/contribs-lib/CLucene/snowball/SnowballAnalyzer.h
@@ -22,6 +22,7 @@ CL_NS_DEF2(analysis,snowball)
 class CLUCENE_CONTRIBS_EXPORT SnowballAnalyzer: public Analyzer {
   TCHAR* language;
   CLTCSetList* stopSet;
+  class SavedStreams;
 
 public:
   /** Builds the named analyzer with no stop words. */
@@ -37,6 +38,8 @@ public:
       StandardFilter}, a {@link LowerCaseFilter} and a {@link StopFilter}. */
   TokenStream* tokenStream(const TCHAR* fieldName, CL_NS(util)::Reader* reader);
   TokenStream* tokenStream(const TCHAR* fieldName, CL_NS(util)::Reader* reader, bool deleteReader);
+
+  TokenStream* reusableTokenStream(const TCHAR* fieldName, CL_NS(util)::Reader* reader);
 };
 
 CL_NS_END2
