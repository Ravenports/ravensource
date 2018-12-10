--- scheduler/cups-driverd.cxx.orig	2018-12-07 19:41:56 UTC
+++ scheduler/cups-driverd.cxx
@@ -917,7 +917,7 @@ get_file(const char *name,		/* I - Name
   }
   else
 
-#elif defined(__linux)
+#elif defined(__linux) || defined(__FreeBSD__) || defined(__DragonFly__)
   if (!strncmp(name, "lsb/usr/", 8))
   {
    /*
@@ -1097,7 +1097,7 @@ list_ppds(int        request_id,	/* I -
   load_ppds("/System/Library/Printers/PPDs/Contents/Resources/en.lproj",
             "System/Library/Printers/PPDs/Contents/Resources/en.lproj", 0);
 
-#elif defined(__linux)
+#elif defined(__linux) || defined(__FreeBSD__) || defined(__DragonFly__)
  /*
   * Load PPDs from LSB-defined locations...
   */
