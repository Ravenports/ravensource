--- src/common/SimilarToRegex.cpp.orig	2021-05-29 15:05:05 UTC
+++ src/common/SimilarToRegex.cpp
@@ -108,7 +108,8 @@ namespace
 			options.set_log_errors(false);
 			options.set_dot_nl(true);
 			options.set_case_sensitive(!(flags & COMP_FLAG_CASE_INSENSITIVE));
-			options.set_utf8(!(flags & COMP_FLAG_LATIN));
+			if (!(flags & COMP_FLAG_LATIN))
+				options.set_encoding(options.EncodingUTF8);
 
 			re2::StringPiece sp((const char*) re2PatternStr.c_str(), re2PatternStr.length());
 			regexp = FB_NEW_POOL(pool) RE2(sp, options);
@@ -759,7 +760,8 @@ namespace
 			options.set_log_errors(false);
 			options.set_dot_nl(true);
 			options.set_case_sensitive(!(flags & COMP_FLAG_CASE_INSENSITIVE));
-			options.set_utf8(!(flags & COMP_FLAG_LATIN));
+			if (!(flags & COMP_FLAG_LATIN))
+				options.set_encoding(options.EncodingUTF8);
 
 			re2::StringPiece sp((const char*) finalRe2Pattern.c_str(), finalRe2Pattern.length());
 			regexp = FB_NEW_POOL(pool) RE2(sp, options);
