--- rtgui/histogrampanel.cc.orig	2026-04-27 06:28:28 UTC
+++ rtgui/histogrampanel.cc
@@ -1415,7 +1415,7 @@ void HistogramArea::updateNonRaw(Cairo::
 
     // determine the number of h-gridlines based on current h
     int nrOfHGridPartitions =
-        (int)rtengine::min(16.0, pow(2.0, floor((hh - 100) / 250) + 2));
+        (int)rtengine::min(16.0, pow(2.0, floor((double)(hh - 100) / 250.0) + 2));
     int nrOfVGridPartitions =
         8; // always show 8 stops (lines at 1,3,7,15,31,63,127)
 
@@ -1666,7 +1666,7 @@ void HistogramArea::updateRaw(Cairo::Ref
 
     // determine the number of h-gridlines based on current h
     int nrOfHGridPartitions =
-        (int)rtengine::min(16.0, pow(2.0, floor((hh - 100) / 250) + 2));
+        (int)rtengine::min(16.0, pow(2.0, floor((double)(hh - 100) / 250.0) + 2));
     double sz = 2;
     if (valid) {
         sz = rtengine::max(rhistRaw.getUpperBound(), ghistRaw.getUpperBound(),
