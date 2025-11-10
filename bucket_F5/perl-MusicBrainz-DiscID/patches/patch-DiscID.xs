--- DiscID.xs.orig	2019-10-07 23:09:14 UTC
+++ DiscID.xs
@@ -113,7 +113,7 @@ discid_get_track_length( disc, track_num
 ## Provides the TOC of a known CD.
 ##
 int
-discid_put( disc, first_track, sectors, offsets ... )
+discid_put( disc, first_track, sectors, offsets, ... )
   DiscId *disc
   int first_track
   int sectors
