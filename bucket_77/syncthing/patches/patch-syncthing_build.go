--- syncthing/build.go.orig	2020-08-11 08:56:46 UTC
+++ syncthing/build.go
@@ -464,7 +464,7 @@ func install(target target, tags []strin
 		defer shouldCleanupSyso(sysoPath)
 	}
 
-	args := []string{"install", "-v"}
+	args := []string{"install"}
 	args = appendParameters(args, tags, target.buildPkgs...)
 	runPrint(goCmd, args...)
 }
