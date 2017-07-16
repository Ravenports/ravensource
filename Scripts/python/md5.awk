BEGIN {
   FS="\"";
   scan_step1 = 0;
   scan_step2 = 0;
   # set seek to "md5_digest" or "filename"
}
{
   if ($2 == version) {
      scan_step1 = 1;
   } else {
      if (scan_step1) {
         if (($2 == "python_version") && ($4 == "source")) {
            scan_step2 = 1;
         } else {
            if (scan_step2 && ($2 == seek)) {
               print $4;
               scan_step1 = 0;
               scan_step2 = 0;
            }
         }
      }
   }
}
