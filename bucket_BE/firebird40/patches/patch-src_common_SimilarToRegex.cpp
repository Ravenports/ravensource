--- src/common/SimilarToRegex.cpp.orig	2021-12-21 10:19:50 UTC
+++ src/common/SimilarToRegex.cpp
@@ -110,7 +110,8 @@ namespace
 			options.set_log_errors(false);
 			options.set_dot_nl(true);
 			options.set_case_sensitive(!(flags & COMP_FLAG_CASE_INSENSITIVE));
-			options.set_utf8(!(flags & COMP_FLAG_LATIN));
+			if (!(flags & COMP_FLAG_LATIN))
+				options.set_encoding(options.EncodingUTF8);
 
 			re2::StringPiece sp((const char*) re2PatternStr.c_str(), re2PatternStr.length());
 			regexp = FB_NEW_POOL(pool) RE2(sp, options);
@@ -761,7 +762,8 @@ namespace
 			options.set_log_errors(false);
 			options.set_dot_nl(true);
 			options.set_case_sensitive(!(flags & COMP_FLAG_CASE_INSENSITIVE));
-			options.set_utf8(!(flags & COMP_FLAG_LATIN));
+			if (!(flags & COMP_FLAG_LATIN))
+				options.set_encoding(options.EncodingUTF8);
 
 			re2::StringPiece sp((const char*) finalRe2Pattern.c_str(), finalRe2Pattern.length());
 			regexp = FB_NEW_POOL(pool) RE2(sp, options);
