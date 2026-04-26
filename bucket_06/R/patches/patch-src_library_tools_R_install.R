--- src/library/tools/R/install.R.orig	2026-04-10 10:15:01 UTC
+++ src/library/tools/R/install.R
@@ -756,7 +756,7 @@ if(FALSE) {
                               nzchar(Sys.which("otool")) &&
                               nzchar(Sys.which("install_name_tool"))
             have_solaris_elfedit <- identical(os, "SunOS") &&
-                                    nzchar(Sys.which("elfedit"))
+                                    file.exists("/usr/bin/elfedit")
 
             hardcoded_paths <- FALSE
             failed_fix <- FALSE
@@ -770,7 +770,7 @@ if(FALSE) {
                 ## changes both rpath and DT_NEEDED paths
                 for (l in slibs) {
                     out <- suppressWarnings(
-                        system(paste("elfedit -re dyn:value", shQuote(l)), intern = TRUE))
+                        system(paste("/usr/bin/elfedit -re dyn:value", shQuote(l)), intern = TRUE))
                     out <- grep("^[ \t]*\\[[0-9]+\\]", out, value = TRUE)
                     re <- "^[ \t]*\\[([0-9]+)\\][ \t]+([^ \t]+)[ \t]+([^ \t]+)[ \t]*(.*)"
                     paths <- gsub(re, "\\4", out)
@@ -787,7 +787,7 @@ if(FALSE) {
                         hardcoded_paths <- TRUE
                         qp <- gsub('([" \\])', "\\\\\\1", paths[i])
                         qp <- gsub("'", "\\\\'", qp)
-                        cmd <- paste0("elfedit -e \"dyn:value -dynndx -s ",
+                        cmd <- paste0("/usr/bin/elfedit -e \"dyn:value -dynndx -s ",
                                      idxs[i], " ", qp, "\" ", shQuote(l))
                         message(cmd)
                         ret <- suppressWarnings(system(cmd, intern = FALSE))
@@ -795,7 +795,7 @@ if(FALSE) {
                             message("NOTE: fixed path ", sQuote(old_paths[i]))
                     }
                     out <- suppressWarnings(
-                        system(paste("elfedit -re dyn:value", shQuote(l)), intern = TRUE))
+                        system(paste("/usr/bin/elfedit -re dyn:value", shQuote(l)), intern = TRUE))
                     out <- grep("^[ \t]*\\[", out, value = TRUE)
                     paths <- gsub(re, "\\4", out)
                     if (any(grepl(instdir, paths, fixed = TRUE)))
