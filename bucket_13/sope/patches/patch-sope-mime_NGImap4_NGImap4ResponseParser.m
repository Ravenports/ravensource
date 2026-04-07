--- sope-mime/NGImap4/NGImap4ResponseParser.m.orig	2026-03-03 11:58:40.000000000 -0000
+++ sope-mime/NGImap4/NGImap4ResponseParser.m
@@ -88,7 +88,7 @@ static NSDictionary *_parseSingleBody(NG
 static NSDictionary *_parseMultipartBody(NGImap4ResponseParser *self,
 					 BOOL isBodyStructure);
 
-static NSArray *_parseLanguages();
+static NSArray *_parseLanguages(NGImap4ResponseParser *self);
 
 static NSString *_parseBodyString(NGImap4ResponseParser *self,
                                   BOOL _convertString);
@@ -97,7 +97,7 @@ static NSString *_parseBodyDecodeString(
                                         BOOL _decode);
 static NSDictionary *_parseBodyParameterList(NGImap4ResponseParser *self);
 static NSDictionary *_parseContentDisposition(NGImap4ResponseParser *self);
-static NSArray *_parseAddressStructure(NGImap4ResponseParser *self);
+static NSDictionary *_parseAddressStructure(NGImap4ResponseParser *self);
 static NSArray *_parseParenthesizedAddressList(NGImap4ResponseParser *self);
 static int _parseTaggedResponse(NGImap4ResponseParser *self,
                                 NGMutableHashMap *result_);
@@ -2205,7 +2205,7 @@ static NSDictionary *_parseContentDispos
   return disposition;
 }
 
-static NSArray *_parseAddressStructure(NGImap4ResponseParser *self) {
+static NSDictionary *_parseAddressStructure(NGImap4ResponseParser *self) {
   NSString *personalName, *sourceRoute, *mailboxName, *hostName;
 
   // Handle broken address list - generally sent by Microsoft Exchange.
