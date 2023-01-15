--- texk/dvisvgm/dvisvgm-src/src/Ghostscript.hpp.orig	2022-01-21 17:25:16 UTC
+++ texk/dvisvgm/dvisvgm-src/src/Ghostscript.hpp
@@ -47,8 +47,8 @@ struct Ghostscript {
 	Ghostscript (int argc, const char **argv, void *caller=0) {}
 	bool init (int argc, const char **argv, void *caller=0) {return false;}
 	bool available () {return false;}
-	bool revision (gsapi_revision_t *r) {return false;}
-	int revision () {return 0;}
+	bool revision (gsapi_revision_t *r) const {return false;}
+	int revision () const {return 0;}
 	std::string revisionstr () {return "";}
 	int set_stdio (Stdin in, Stdout out, Stderr err) {return 0;}
 	int run_string_begin (int user_errors, int *pexit_code) {return 0;}
