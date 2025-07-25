--- lib/stdlib/src/calendar.erl.orig	2025-06-13 14:54:33 UTC
+++ lib/stdlib/src/calendar.erl
@@ -475,11 +475,19 @@ The return value is a list of 0, 1, or 2
       DateTime1 :: datetime1970(),
       DateTime :: datetime1970().
 local_time_to_universal_time_dst(DateTime) ->
-    UtDst = erlang:localtime_to_universaltime(DateTime, true),
-    Ut    = erlang:localtime_to_universaltime(DateTime, false),
     %% Reverse check the universal times
-    LtDst = erlang:universaltime_to_localtime(UtDst),
-    Lt    = erlang:universaltime_to_localtime(Ut),
+    {UtDst, LtDst} =
+        try
+            UtDst0 = erlang:localtime_to_universaltime(DateTime, true),
+            {UtDst0, erlang:universaltime_to_localtime(UtDst0)}
+        catch error:badarg -> {error, error}
+        end,
+    {Ut, Lt} =
+        try
+            Ut0 = erlang:localtime_to_universaltime(DateTime, false),
+            {Ut0, erlang:universaltime_to_localtime(Ut0)}
+        catch error:badarg -> {error, error}
+        end,
     %% Return the valid universal times
     case {LtDst,Lt} of
 	{DateTime,DateTime} when UtDst =/= Ut ->
