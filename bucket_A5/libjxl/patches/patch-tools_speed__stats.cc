Fix ambiguity with converting ssize_t type to either double or int
--- tools/speed_stats.cc.orig	2026-02-10 13:53:22 UTC
+++ tools/speed_stats.cc
@@ -43,7 +43,7 @@ bool SpeedStats::GetSummary(SpeedStats::
   }
 
   // Prefer geomean unless numerically unreliable (too many reps)
-  if (pow(elapsed_[0], elapsed_.size()) < 1E100) {
+  if (pow(elapsed_[0], (double)elapsed_.size()) < 1E100) {
     double product = 1.0;
     for (size_t i = 1; i < elapsed_.size(); ++i) {
       product *= elapsed_[i];
