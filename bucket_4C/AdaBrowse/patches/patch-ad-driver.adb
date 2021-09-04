--- ad-driver.adb.orig	2021-09-04 15:38:31 UTC
+++ ad-driver.adb
@@ -470,6 +470,7 @@ package body AD.Driver is
                AIC.Set_File_Name
                  (AIC.Subprogram_Index, Canonical (S (S'First + 2 .. S'Last)));
             elsif S = "-P" then
+               Error ("-P is disabled in Ravenports");
                I := I + 1;
                Check_Following (I, N, S);
                if Has_Project then
