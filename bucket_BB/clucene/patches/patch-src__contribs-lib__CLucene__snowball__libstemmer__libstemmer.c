--- src/contribs-lib/CLucene/snowball/libstemmer/libstemmer.c.orig	2011-03-17 00:21:07 UTC
+++ src/contribs-lib/CLucene/snowball/libstemmer/libstemmer.c
@@ -35,9 +35,8 @@ sb_stemmer_new(const char * algorithm, c
 {
     stemmer_encoding enc;
     struct stemmer_modules * module;
-    struct sb_stemmer * stemmer =
-	    (struct sb_stemmer *) malloc(sizeof(struct sb_stemmer));
-    if (stemmer == NULL) return NULL;
+    struct sb_stemmer * stemmer;
+
     enc = sb_getenc(charenc);
     if (enc == ENC_UNKNOWN) return NULL;
 
@@ -46,6 +45,9 @@ sb_stemmer_new(const char * algorithm, c
     }
     if (module->name == NULL) return NULL;
     
+    stemmer = (struct sb_stemmer *) malloc(sizeof(struct sb_stemmer));
+    if (stemmer == NULL) return NULL;
+
     stemmer->create = module->create;
     stemmer->close = module->close;
     stemmer->stem = module->stem;
