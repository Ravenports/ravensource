--- cmake/Install.cmake.orig	2020-04-27 13:57:43 UTC
+++ cmake/Install.cmake
@@ -108,7 +108,7 @@ INSTALL(FILES share/config.fish
               ${CMAKE_CURRENT_BINARY_DIR}/share/__fish_build_paths.fish
         DESTINATION ${rel_datadir}/fish)
 
-# $v $(INSTALL) -m 755 -d $(DESTDIR)$(datadir)/pkgconfig
+# $v $(INSTALL) -m 755 -d $(DESTDIR)$(datadir)/../lib/pkgconfig
 # @echo "Creating placeholder vendor/'extra_' directories"
 # -$v $(INSTALL) -m 755 -d $(DESTDIR)$(extra_completionsdir)
 # -$v $(INSTALL) -m 755 -d $(DESTDIR)$(extra_functionsdir)
@@ -118,8 +118,8 @@ FISH_CREATE_DIRS(${rel_datadir}/fish/ven
     ${rel_datadir}/fish/vendor_conf.d)
 
 # @echo "Installing pkgconfig file"
-# $v $(INSTALL) -m 644 fish.pc $(DESTDIR)$(datadir)/pkgconfig
-FISH_TRY_CREATE_DIRS(${rel_datadir}/pkgconfig)
+# $v $(INSTALL) -m 644 fish.pc $(DESTDIR)$(datadir)/../lib/pkgconfig
+FISH_TRY_CREATE_DIRS(${rel_datadir}/../lib/pkgconfig)
 CONFIGURE_FILE(fish.pc.in fish.pc.noversion)
 
 ADD_CUSTOM_COMMAND(OUTPUT fish.pc
@@ -132,7 +132,7 @@ ADD_CUSTOM_COMMAND(OUTPUT fish.pc
 ADD_CUSTOM_TARGET(build_fish_pc ALL DEPENDS fish.pc)
 
 INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/fish.pc
-        DESTINATION ${rel_datadir}/pkgconfig)
+        DESTINATION ${rel_datadir}/../lib/pkgconfig)
 
 # @echo "Installing the $(bo)fish completion library$(sgr0)...";
 # $v $(INSTALL) -m 644 $(COMPLETIONS_DIR_FILES:%='%') $(DESTDIR)$(datadir)/fish/completions/
