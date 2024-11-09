--- doc/doc.mk.orig	2024-10-25 07:26:33 UTC
+++ doc/doc.mk
@@ -5,5 +5,5 @@ DOCDIR = obj/html
 $(DOCDIR):
 	@mkdir -p $@
 
-build-doc: doc/index | $(DOCDIR)
+build-doc: doc/index $(DOCDIR)
 	asciidoctor doc/index -o $(DOCDIR)/index.html
