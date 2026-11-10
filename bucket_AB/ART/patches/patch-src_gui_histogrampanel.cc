--- src/gui/histogrampanel.cc.orig	2026-11-10 09:54:54 UTC
+++ src/gui/histogrampanel.cc
@@ -1420,7 +1420,7 @@ void HistogramArea::updateNonRaw(Cairo::
 
     // determine the number of h-gridlines based on current h
     int nrOfHGridPartitions =
-        (int)art::engine::min(16.0, pow(2.0, floor((hh - 100) / 250) + 2));
+        (int)art::engine::min(16.0, pow(2.0, floor((double)(hh - 100) / 250) + 2));
     int nrOfVGridPartitions =
         8; // always show 8 stops (lines at 1,3,7,15,31,63,127)
 
@@ -1671,7 +1671,7 @@ void HistogramArea::updateRaw(Cairo::Ref
 
     // determine the number of h-gridlines based on current h
     int nrOfHGridPartitions =
-        (int)art::engine::min(16.0, pow(2.0, floor((hh - 100) / 250) + 2));
+        (int)art::engine::min(16.0, pow(2.0, floor((double)(hh - 100) / 250) + 2));
     double sz = 2;
     if (valid) {
         sz = art::engine::max(rhistRaw.getUpperBound(), ghistRaw.getUpperBound(),
