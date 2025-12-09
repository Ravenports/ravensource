The recorded mtime for output files on DragonFly are just wrong.
The input file times seem to be correct.  I don't know what's going on
here.  Rather than disabling this "obsolete output" check for all platforms,
just disable it on DragonFly for now and observe.

Also seen on MidnightBSD

--- src/graph.cc.orig	2025-06-18 12:08:38 UTC
+++ src/graph.cc
@@ -343,6 +343,7 @@ bool DependencyScan::RecomputeOutputDirt
                              output->path().c_str());
         return true;
       }
+#if !(defined(__DragonFly__) || defined(__MidnightBSD__))
       if (most_recent_input && entry->mtime < most_recent_input->mtime()) {
         // May also be dirty due to the mtime in the log being older than the
         // mtime of the most recent input.  This can occur even when the mtime
@@ -358,6 +359,7 @@ bool DependencyScan::RecomputeOutputDirt
             entry->mtime, most_recent_input->mtime());
         return true;
       }
+#endif
     }
     if (!entry && !generator) {
       explanations_.Record(output, "command line not found in log for %s",
