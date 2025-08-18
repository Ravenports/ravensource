--- src/cmd/link/internal/ld/target.go.orig	2025-08-08 19:33:32 UTC
+++ src/cmd/link/internal/ld/target.go
@@ -72,16 +72,7 @@ func (t *Target) IsDynlinkingGo() bool {
 // UseRelro reports whether to make use of "read only relocations" aka
 // relro.
 func (t *Target) UseRelro() bool {
-	switch t.BuildMode {
-	case BuildModeCArchive, BuildModeCShared, BuildModeShared, BuildModePIE, BuildModePlugin:
-		return t.IsELF || t.HeadType == objabi.Haix || t.HeadType == objabi.Hdarwin
-	default:
-		if t.HeadType == objabi.Hdarwin && t.IsARM64() {
-			// On darwin/ARM64, everything is PIE.
-			return true
-		}
-		return t.linkShared || (t.HeadType == objabi.Haix && t.LinkMode == LinkExternal)
-	}
+	return false
 }
 
 //
