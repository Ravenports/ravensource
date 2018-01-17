--- src/contribs-lib/CLucene/highlighter/WeightedTerm.cpp.orig	2011-03-17 00:21:07 UTC
+++ src/contribs-lib/CLucene/highlighter/WeightedTerm.cpp
@@ -73,7 +73,7 @@ CL_NS_DEF2(search,highlight)
 	 * @param weight the weight associated with this term
 	 */
 	void WeightedTerm::setWeight(float_t weight) {
-		this->_weight = _weight;
+		_weight = weight;
 		cachedHashCode = 0;
 	}
 
