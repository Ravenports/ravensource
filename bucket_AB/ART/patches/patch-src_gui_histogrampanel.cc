--- src/gui/histogrampanel.cc.orig	2026-10-15 13:01:50 UTC
+++ src/gui/histogrampanel.cc
@@ -1419,7 +1419,7 @@ void HistogramArea::updateNonRaw(Cairo::
 
     // determine the number of h-gridlines based on current h
     int nrOfHGridPartitions =
-        (int)art::engine::min(16.0, pow(2.0, floor((hh - 100) / 250) + 2));
+        (int)art::engine::min(16.0, pow(2.0, floor((double)(hh - 100) / 250) + 2));
     int nrOfVGridPartitions =
         8; // always show 8 stops (lines at 1,3,7,15,31,63,127)
 
@@ -1670,7 +1670,7 @@ void HistogramArea::updateRaw(Cairo::Ref
 
     // determine the number of h-gridlines based on current h
     int nrOfHGridPartitions =
-        (int)art::engine::min(16.0, pow(2.0, floor((hh - 100) / 250) + 2));
+        (int)art::engine::min(16.0, pow(2.0, floor((double)(hh - 100) / 250) + 2));
     double sz = 2;
     if (valid) {
         sz = art::engine::max(rhistRaw.getUpperBound(), ghistRaw.getUpperBound(),
