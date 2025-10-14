--- sslib/json.ss.orig	2014-06-21 23:24:09.000000000 +0200
+++ sslib/json.ss	2025-10-14 21:13:53.532571000 +0200
@@ -3,21 +3,21 @@
 
 (define (string-split str delimiter)
   (let ([len (string-length str)]
-		[ret '()]
-		[s   0])
-	(let loop ([e 0])
-	  (if (>= e len)
-		(begin
-		  (if (> e s)
-			(set! ret (cons (substring str s e) ret)))
-		  (reverse ret))
-		(if (char=? delimiter (string-ref str e))
-		  (let* ([sub    (substring str s e)]
-				 [sublen (string-length sub)])
-			(set! ret (cons sub ret))
-			(set! s (+ s sublen 1))
-			(loop s))
-		  (loop (+ 1 e)) ) ) ) ) ) 
+        [ret '()]
+        [s   0])
+    (let loop ([e 0])
+      (if (>= e len)
+        (begin
+          (if (> e s)
+            (set! ret (cons (substring str s e) ret)))
+          (reverse ret))
+        (if (char=? delimiter (string-ref str e))
+          (let* ([sub    (substring str s e)]
+                 [sublen (string-length sub)])
+            (set! ret (cons sub ret))
+            (set! s (+ s sublen 1))
+            (loop s))
+          (loop (+ 1 e)) ) ) ) ) )
 
 (define (string-empty? str)
   (> (string-length str) 0))
@@ -27,9 +27,9 @@
 (define (->string x)
   (cond
     [(char? x) (string x)]
-	[(symbol? x) (symbol->string x)]
-	[(eof-object? x) "<EOF>"]
-	[else ""]))
+    [(symbol? x) (symbol->string x)]
+    [(eof-object? x) "<EOF>"]
+    [else ""]))
 
 (define (lexer-error c)
   (error (string-append "unexpected character " (->string c))))
@@ -40,172 +40,172 @@
 (define (hex-char-value ch)
   (let ([n (char->integer ch)])
     (cond
-	  [(<= 97 n 102) (- n 87)] ; a-f
-	  [(<= 65 n 70)  (- n 55)] ; A-F
-	  [(<= 48 n 57)  (- n 48)] ; 0-9
-	  [else
-	    (lexer-error ch) ] ) ) )
+      [(<= 97 n 102) (- n 87)] ; a-f
+      [(<= 65 n 70)  (- n 55)] ; A-F
+      [(<= 48 n 57)  (- n 48)] ; 0-9
+      [else
+        (lexer-error ch) ] ) ) )
 
 (define (char-control? ch)
   (let ([i (char->integer ch)])
     (or (< i 32)
-		(< 127 i 160))))
+        (< 127 i 160))))
 
 (define (consume-char expect)
   (let ([ch (read-char)])
     (if (eqv? ch expect)
-	  ch
-	  (lexer-error ch) ) ) )
+      ch
+      (lexer-error ch) ) ) )
 
 (define (parse-unicode)
   (let* ([a (hex-char-value (read-char))]
-		 [b (hex-char-value (read-char))]
-		 [c (hex-char-value (read-char))]
-		 [d (hex-char-value (read-char))])
-	(integer->char
-	  (+ (* 4096 a)
-		 (*  256 b)
-		 (*   16 c)
-		 d))))
+         [b (hex-char-value (read-char))]
+         [c (hex-char-value (read-char))]
+         [d (hex-char-value (read-char))])
+    (integer->char
+      (+ (* 4096 a)
+         (*  256 b)
+         (*   16 c)
+         d))))
 
 (define (parse-escape q)
   (let ([ch (read-char)])
     (case ch
-	  [(#\b) #\x08]
-	  [(#\f) #\x0C]
-	  [(#\n) #\newline]
-	  [(#\r) #\return]
-	  [(#\t) #\tab]
-	  [(#\\) #\\]
-	  [(#\u) (parse-unicode)]
-	  [else
-	    (if (eqv? ch q)
-		  q
-		  (lexer-error ch) ) ] ) ) )
+      [(#\b) #\x08]
+      [(#\f) #\x0C]
+      [(#\n) #\newline]
+      [(#\r) #\return]
+      [(#\t) #\tab]
+      [(#\\) #\\]
+      [(#\u) (parse-unicode)]
+      [else
+        (if (eqv? ch q)
+          q
+          (lexer-error ch) ) ] ) ) )
 
 (define (parse-number ch)
   (let loop ([res (string ch)])
-	(let ([ch (peek-char)])
-	  (case ch
-		[(#\- #\+ #\0 #\1 #\2 #\3 #\4 #\5 #\6 #\7 #\8 #\9 #\. #\e #\E)
-		 (begin
-		   (read-char)
-		   (loop (string-append res (string ch))) ) ]
-		[else
-		  (string->number res) ] ) ) ) )
+    (let ([ch (peek-char)])
+      (case ch
+        [(#\- #\+ #\0 #\1 #\2 #\3 #\4 #\5 #\6 #\7 #\8 #\9 #\. #\e #\E)
+         (begin
+           (read-char)
+           (loop (string-append res (string ch))) ) ]
+        [else
+          (string->number res) ] ) ) ) )
 
 (define (parse-string q)
   (let loop ([res ""])
-	(let ([ch (read-char)])
-	  (cond
-	    [(eqv? ch #\\) (loop string-append rest (string (parse-escape q)))]
-		[(eqv? ch q) res]
-		;[(eqv? ch q) res]
-		[(not (char-control? ch)) (loop (string-append res (string ch)))]
-		[else (lexer-error ch)] ) ) ) )
+    (let ([ch (read-char)])
+      (cond
+        [(eqv? ch #\\) (loop string-append rest (string (parse-escape q)))]
+        [(eqv? ch q) res]
+        ;[(eqv? ch q) res]
+        [(not (char-control? ch)) (loop (string-append res (string ch)))]
+        [else (lexer-error ch)] ) ) ) )
 
 ;; reads symbol 'true', the first character is already read by next-token
 (define (parse-true)
   (begin
-	(consume-char #\r)
-	(consume-char #\u)
-	(consume-char #\e)
-	#t))
+    (consume-char #\r)
+    (consume-char #\u)
+    (consume-char #\e)
+    #t))
 
 (define (parse-false)
   (begin
-	(consume-char #\a)
-	(consume-char #\l)
-	(consume-char #\s)
-	(consume-char #\e)
-	#f))
+    (consume-char #\a)
+    (consume-char #\l)
+    (consume-char #\s)
+    (consume-char #\e)
+    #f))
 
 (define (parse-null)
   (begin
-	(consume-char #\u)
-	(consume-char #\l)
-	(consume-char #\l)
-	'()))
+    (consume-char #\u)
+    (consume-char #\l)
+    (consume-char #\l)
+    '()))
 
 (define (next-token)
   (let ([ch (read-char)])
     (case ch
-	  [(#\space #\newline #\tab #\return) (next-token)]
-	  [(#\" #\') (parse-string ch)]
-	  [(#\- #\0 #\1 #\2 #\3 #\4 #\5 #\6 #\7 #\8 #\9) (parse-number ch)]
-	  [(#\[) 'open-brace]
-	  [(#\]) 'close-brace]
-	  [(#\{) 'open-curly]
-	  [(#\}) 'close-curly]
-	  [(#\:) 'colon]
-	  [(#\,) 'comma]
-	  [(#\t) (parse-true)]
-	  [(#\f) (parse-false)]
-	  [(#\n) (parse-null)]
-	  [else
-	    (if (eof-object? ch)
-		  ch
-		  (lexer-error ch) ) ] ) ) )
+      [(#\space #\newline #\tab #\return) (next-token)]
+      [(#\" #\') (parse-string ch)]
+      [(#\- #\0 #\1 #\2 #\3 #\4 #\5 #\6 #\7 #\8 #\9) (parse-number ch)]
+      [(#\[) 'open-brace]
+      [(#\]) 'close-brace]
+      [(#\{) 'open-curly]
+      [(#\}) 'close-curly]
+      [(#\:) 'colon]
+      [(#\,) 'comma]
+      [(#\t) (parse-true)]
+      [(#\f) (parse-false)]
+      [(#\n) (parse-null)]
+      [else
+        (if (eof-object? ch)
+          ch
+          (lexer-error ch) ) ] ) ) )
 
 (define (parse-list)
   (let loop ([res '(list)])
-	(let ([token (next-token)])
-	  (cond
-	    [(eqv? token 'close-brace) (reverse res)]
-		[else
-		  (let* ([res  (cons (parse-object-helper token) res)]
-				 [next (next-token)])
-			(cond
-			  [(eqv? next 'close-brace) (reverse res)]
-			  [(eqv? next 'comma) (loop res)]
-			  [else
-			    (parse-error next) ] ) ) ] ) ) ) )
+    (let ([token (next-token)])
+      (cond
+        [(eqv? token 'close-brace) (reverse res)]
+        [else
+          (let* ([res  (cons (parse-object-helper token) res)]
+                 [next (next-token)])
+            (cond
+              [(eqv? next 'close-brace) (reverse res)]
+              [(eqv? next 'comma) (loop res)]
+              [else
+                (parse-error next) ] ) ) ] ) ) ) )
 
 (define (parse-map)
   (let loop ([res '(map)])
-	(let ([token (next-token)])
-	  (cond
-	    [(eqv? token 'close-curly) (reverse res)]
-		[(string? token)
-		 (let* ([res  (cons
-					    (cons (string->symbol token) (parse-map-value))
-						res)]
-				[next (next-token)])
-		   (cond
-			 [(eqv? next 'close-curly) (reverse res)]
-			 [(eqv? next 'comma) (loop res)]
-			 [else (parse-error next) ] ) ) ]
-		[else
-		  (parse-error next) ] ) ) ) )
+    (let ([token (next-token)])
+      (cond
+        [(eqv? token 'close-curly) (reverse res)]
+        [(string? token)
+         (let* ([res  (cons
+                        (cons (string->symbol token) (parse-map-value))
+                        res)]
+                [next (next-token)])
+           (cond
+             [(eqv? next 'close-curly) (reverse res)]
+             [(eqv? next 'comma) (loop res)]
+             [else (parse-error next) ] ) ) ]
+        [else
+          (parse-error next) ] ) ) ) )
 
 (define (parse-map-value)
   (let ([token (next-token)])
     (if (eqv? token 'colon)
-	  (parse-object)
-	  (parse-error token) ) ) )
+      (parse-object)
+      (parse-error token) ) ) )
 
 (define (parse-object-helper token)
   (cond
     [(eqv? token 'open-brace) (parse-list)]
-	[(eqv? token 'open-curly) (parse-map)]
-	[(null?    token) token]
-	[(string?  token) token]
-	[(number?  token) token]
-	[(boolean? token) token]
-	[else
-	  (parse-error token) ] ) )
+    [(eqv? token 'open-curly) (parse-map)]
+    [(null?    token) token]
+    [(string?  token) token]
+    [(number?  token) token]
+    [(boolean? token) token]
+    [else
+      (parse-error token) ] ) )
 
 (define (parse-object)
   (parse-object-helper (next-token)))
 
 (define (tokenize)
   (let loop ([res   '()]
-			 [token (next-token)])
-	(if (eof-object? token)
-	  (reverse res)
-	  (loop
-	    (cons token res)
-		(next-token) ) ) ) )
+             [token (next-token)])
+    (if (eof-object? token)
+      (reverse res)
+      (loop
+        (cons token res)
+        (next-token) ) ) ) )
 
 (define (double-quote str)
   (string-append "\"" str "\""))
@@ -230,36 +230,36 @@
 
 (define (json/gen-string obj)
   (if (pair? obj)
-	(let ([token (car obj)])
-	  (case tok
-		[(map)
-		 (string-append "{"
-						(reduce
-						  (lambda (o s)
-							(string-append
-							  (double-quote
-							    (symbol->string (car o)))
-							  ":"
-							  (json/gen-string (cdr o))
-							  (if (> (string-length s) 0) ", " "")
-							  s))
-						  ""
-						  (cdr obj))
-						"}")]
-		[(list)
-		 (string-append "["
-						(reduce
-						  (lambda (o s)
-							(string-append
-							  (json/gen-string o)
-							  (if (> (string-length s) 0) ", " "")
-							  S))
-						  ""
-						  (cdr obj))
-						"]")]))
-	;; else
-	(cond
-	  [(boolean? obj) (if obj "true" "false")]
-	  [(number? obj) (number->string obj)]
-	  [(string? obj) (double-quote obj)]
-	  [(list? obj) "null"] ) ) )
+    (let ([token (car obj)])
+      (case token
+        [(map)
+         (string-append "{"
+                        (reduce
+                          (lambda (o s)
+                            (string-append
+                              (double-quote
+                                (symbol->string (car o)))
+                              ":"
+                              (json/gen-string (cdr o))
+                              (if (> (string-length s) 0) ", " "")
+                              s))
+                          ""
+                          (cdr obj))
+                        "}")]
+        [(list)
+         (string-append "["
+                        (reduce
+                          (lambda (o s)
+                            (string-append
+                              (json/gen-string o)
+                              (if (> (string-length s) 0) ", " "")
+                              S))
+                          ""
+                          (cdr obj))
+                        "]")]))
+    ;; else
+    (cond
+      [(boolean? obj) (if obj "true" "false")]
+      [(number? obj) (number->string obj)]
+      [(string? obj) (double-quote obj)]
+      [(list? obj) "null"] ) ) )
