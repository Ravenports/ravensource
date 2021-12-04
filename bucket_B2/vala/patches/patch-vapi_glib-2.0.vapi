--- vapi/glib-2.0.vapi.orig	2021-11-29 10:23:21 UTC
+++ vapi/glib-2.0.vapi
@@ -3913,6 +3913,8 @@ namespace GLib {
 		public static FileStream? open (string path, string mode);
 		[CCode (cname = "fdopen")]
 		public static FileStream? fdopen (int fildes, string mode);
+		[CCode (cname = "freopen", instance_pos = -1)]
+		public void reopen (string path, string mode);
 		[CCode (cname = "fprintf")]
 		[PrintfFormat ()]
 		public void printf (string format, ...);
