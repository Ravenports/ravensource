--- rtgui/histogrampanel.cc.orig	2026-01-13 18:23:55 UTC
+++ rtgui/histogrampanel.cc
@@ -1407,7 +1407,7 @@ void HistogramArea::updateNonRaw(Cairo::
 
     // determine the number of h-gridlines based on current h
     int nrOfHGridPartitions =
-        (int)rtengine::min(16.0, pow(2.0, floor((h - 100) / 250) + 2));
+        (int)rtengine::min(16.0, pow(2.0, floor((double)(h - 100) / 250) + 2.0));
     int nrOfVGridPartitions =
         8; // always show 8 stops (lines at 1,3,7,15,31,63,127)
 
@@ -1654,7 +1654,7 @@ void HistogramArea::updateRaw(Cairo::Ref
 
     // determine the number of h-gridlines based on current h
     int nrOfHGridPartitions =
-        (int)rtengine::min(16.0, pow(2.0, floor((h - 100) / 250) + 2));
+        (int)rtengine::min(16.0, pow(2.0, floor((double)(h - 100) / 250) + 2.0));
     double sz = 2;
     if (valid) {
         sz = rtengine::max(rhistRaw.getUpperBound(), ghistRaw.getUpperBound(),
