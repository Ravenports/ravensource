--- build-outputs.mk.orig	2021-02-04 12:21:14 UTC
+++ build-outputs.mk
@@ -1390,11 +1390,11 @@ install-swig-rb-lib: subversion/bindings
 
 install-tools: tools/diff/diff$(EXEEXT) tools/diff/diff3$(EXEEXT) tools/diff/diff4$(EXEEXT) tools/dev/fsfs-access-map$(EXEEXT) tools/server-side/mod_dontdothat/mod_dontdothat.la tools/client-side/svn-mergeinfo-normalizer/svn-mergeinfo-normalizer$(EXEEXT) tools/server-side/svn-populate-node-origins-index$(EXEEXT) tools/server-side/svnauthz$(EXEEXT) tools/server-side/svnauthz-validate$(EXEEXT) tools/client-side/svnconflict/svnconflict$(EXEEXT) tools/dev/svnmover/svnmover$(EXEEXT) tools/dev/svnraisetreeconflict/svnraisetreeconflict$(EXEEXT) tools/dev/x509-parser$(EXEEXT)
 	$(MKDIR) $(DESTDIR)$(toolsdir)
-	cd tools/diff ; $(INSTALL_TOOLS) diff$(EXEEXT) $(DESTDIR)$(toolsdir)/diff$(EXEEXT)
+	cd tools/diff ; $(INSTALL_TOOLS) diff$(EXEEXT) $(DESTDIR)$(toolsdir)/svndiff$(EXEEXT)
 	
-	cd tools/diff ; $(INSTALL_TOOLS) diff3$(EXEEXT) $(DESTDIR)$(toolsdir)/diff3$(EXEEXT)
+	cd tools/diff ; $(INSTALL_TOOLS) diff3$(EXEEXT) $(DESTDIR)$(toolsdir)/svndiff3$(EXEEXT)
 	
-	cd tools/diff ; $(INSTALL_TOOLS) diff4$(EXEEXT) $(DESTDIR)$(toolsdir)/diff4$(EXEEXT)
+	cd tools/diff ; $(INSTALL_TOOLS) diff4$(EXEEXT) $(DESTDIR)$(toolsdir)/svndiff4$(EXEEXT)
 	
 	cd tools/dev ; $(INSTALL_TOOLS) fsfs-access-map$(EXEEXT) $(DESTDIR)$(toolsdir)/fsfs-access-map$(EXEEXT)
 	
