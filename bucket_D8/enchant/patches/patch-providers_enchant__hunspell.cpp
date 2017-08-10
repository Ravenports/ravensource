--- providers/enchant_hunspell.cpp.orig	2017-07-25 08:36:41 UTC
+++ providers/enchant_hunspell.cpp
@@ -312,7 +312,7 @@ HunspellChecker::requestDictionary(const
 	if(hunspell == NULL){
 		return false;
 	}
-	char *enc = hunspell->get_dic_encoding();
+	const char *enc = hunspell->get_dic_encoding();
 
 	m_translate_in = g_iconv_open(enc, "UTF-8");
 	m_translate_out = g_iconv_open("UTF-8", enc);
