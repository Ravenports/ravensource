On OmniOS:
../lib/regex.h:682:64: error: use of parameter outside function body before ']'
token 682 | _REGEX_NELTS (__nmatch)], | ^ ../lib/regex.h:682:65:
error: expected ')' before ',' token 682 | _REGEX_NELTS (__nmatch)], | ^ | )
../lib/regex.h:679:20: note: to match this '(' 679 |
   extern int regexec (const regex_t *_Restrict_ __preg, |
   ^ ../lib/regex.h:683:21: error: expected unqualified-id before 'int' 683 |
   int __eflags); |
   ^~~ *** [lftp-lftp.o] Error code 1

--- lib/regex.h.orig	2024-11-08 09:43:25 UTC
+++ lib/regex.h
@@ -678,8 +678,7 @@ extern int regcomp (regex_t *_Restrict_
 
 extern int regexec (const regex_t *_Restrict_ __preg,
 		    const char *_Restrict_ __String, size_t __nmatch,
-		    regmatch_t __pmatch[_Restrict_arr_
-					_REGEX_NELTS (__nmatch)],
+		    regmatch_t *__pmatch,
 		    int __eflags);
 
 extern size_t regerror (int __errcode, const regex_t *_Restrict_ __preg,
