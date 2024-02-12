--- doc/doc.mk.orig	2024-01-09 20:06:42 UTC
+++ doc/doc.mk
@@ -5,5 +5,5 @@ DOCDIR = obj/html
 $(DOCDIR):
 	@mkdir -p $@
 
-build-doc: doc/index | $(DOCDIR)
+build-doc: doc/index $(DOCDIR)
 	asciidoctor doc/index -o $(DOCDIR)/index.html
