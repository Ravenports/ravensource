This allows /raven/etc/vim/vimrc to be loaded as a system
vimrc. Note that creating that file will prevent loading
defaults.vim from Vim runtime.

--- src/feature.h.orig	2026-04-09 22:21:23.000000000 -0000
+++ src/feature.h
@@ -700,12 +700,12 @@
 /*
  * SYS_VIMRC_FILE	Name of the system-wide .vimrc file.
  */
-// #define SYS_VIMRC_FILE	"/etc/vimrc"
+#define SYS_VIMRC_FILE	"%%ETCDIR%%/vimrc"
 
 /*
  * SYS_GVIMRC_FILE	Name of the system-wide .gvimrc file.
  */
-// #define SYS_GVIMRC_FILE	"/etc/gvimrc"
+#define SYS_GVIMRC_FILE	"%%ETCDIR%%/gvimrc"
 
 /*
  * DFLT_HELPFILE	Name of the help file.
