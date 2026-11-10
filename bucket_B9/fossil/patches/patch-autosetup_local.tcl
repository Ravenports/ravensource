--- autosetup/local.tcl.orig	2026-03-11 11:31:46 UTC
+++ autosetup/local.tcl
@@ -12,7 +12,7 @@ proc parse-tclconfig-sh {args} {
 			return [parse-tclconfig-sh-file $p/tclConfig.sh]
 		}
 		# Some systems allow for multiple versions
-		foreach libpath {lib/tcl8.6 lib/tcl8.5 lib/tcl8.4 lib/tcl tcl lib}  {
+		foreach libpath {lib/tcl9.1 lib/tcl9.0 lib/tcl8.6 lib/tcl tcl lib}  {
 			if {[file exists $p/$libpath/tclConfig.sh]} {
 				return [parse-tclconfig-sh-file $p/$libpath/tclConfig.sh]
 			}
