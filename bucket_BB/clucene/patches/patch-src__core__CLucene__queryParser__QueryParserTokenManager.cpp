--- src/core/CLucene/queryParser/QueryParserTokenManager.cpp.orig	2011-03-17 00:21:07 UTC
+++ src/core/CLucene/queryParser/QueryParserTokenManager.cpp
@@ -15,9 +15,9 @@
 
 CL_NS_DEF(queryParser)
 
-const int64_t QueryParserTokenManager::jjbitVec2[]={0x0L, 0x0L, _ILONGLONG(0xffffffffffffffff), _ILONGLONG(0xffffffffffffffff)};
+const int64_t QueryParserTokenManager::jjbitVec2[]={0x0L, 0x0L, int64_t(_ILONGLONG(0xffffffffffffffff)), int64_t(_ILONGLONG(0xffffffffffffffff))};
 const int64_t QueryParserTokenManager::jjbitVec0[] = {
-	_ILONGLONG(0xfffffffffffffffe), _ILONGLONG(0xffffffffffffffff), _ILONGLONG(0xffffffffffffffff), _ILONGLONG(0xffffffffffffffff)
+	int64_t(_ILONGLONG(0xfffffffffffffffe)), int64_t(_ILONGLONG(0xffffffffffffffff)), int64_t(_ILONGLONG(0xffffffffffffffff)), int64_t(_ILONGLONG(0xffffffffffffffff))
 };
 const int32_t QueryParserTokenManager::jjnextStates[]={
 		15, 17, 18, 29, 32, 23, 33, 30, 20, 21, 32, 23, 33, 31, 34, 27,
@@ -544,7 +544,10 @@ int32_t QueryParserTokenManager::jjMoveN
 			kind = 0x7fffffff;
 		}
 		++curPos;
-		if ((i = jjnewStateCnt) == (startsAt = 36 - (jjnewStateCnt = startsAt)))
+		i = jjnewStateCnt;
+		jjnewStateCnt = startsAt;
+		startsAt = 36 - jjnewStateCnt;
+		if (i == startsAt)
 			return curPos;
 		try { curChar = input_stream->readChar(); }
 		catch(CLuceneError& e) {
@@ -756,7 +759,10 @@ int32_t QueryParserTokenManager::jjMoveN
 			kind = 0x7fffffff;
 		}
 		++curPos;
-		if ((i = jjnewStateCnt) == (startsAt = 7 - (jjnewStateCnt = startsAt)))
+		i = jjnewStateCnt;
+		jjnewStateCnt = startsAt;
+		startsAt = 7 - jjnewStateCnt;
+		if (i == startsAt)
 			return curPos;
 		try { curChar = input_stream->readChar(); }
 		catch(CLuceneError& e) {
@@ -854,7 +860,10 @@ int32_t QueryParserTokenManager::jjMoveN
 			kind = 0x7fffffff;
 		}
 		++curPos;
-		if ((i = jjnewStateCnt) == (startsAt = 3 - (jjnewStateCnt = startsAt)))
+		i = jjnewStateCnt;
+		jjnewStateCnt = startsAt;
+		startsAt = 3 - jjnewStateCnt;
+		if (i == startsAt)
 			return curPos;
 		try { curChar = input_stream->readChar(); }
 		catch(CLuceneError& e) {
@@ -1066,7 +1075,10 @@ int32_t QueryParserTokenManager::jjMoveN
 			kind = 0x7fffffff;
 		}
 		++curPos;
-		if ((i = jjnewStateCnt) == (startsAt = 7 - (jjnewStateCnt = startsAt)))
+		i = jjnewStateCnt;
+		jjnewStateCnt = startsAt;
+		startsAt = 7 - jjnewStateCnt;
+		if (i == startsAt)
 			return curPos;
 		try { curChar = input_stream->readChar(); }
 		catch(CLuceneError& e) {
