--- vapi/glib-2.0.vapi.orig	2019-08-05 06:51:18 UTC
+++ vapi/glib-2.0.vapi
@@ -3615,6 +3615,8 @@ namespace GLib {
 		public static FileStream? open (string path, string mode);
 		[CCode (cname = "fdopen")]
 		public static FileStream? fdopen (int fildes, string mode);
+		[CCode (cname = "freopen", instance_pos = -1)]
+		public void reopen (string path, string mode);
 		[CCode (cname = "fprintf")]
 		[PrintfFormat ()]
 		public void printf (string format, ...);
