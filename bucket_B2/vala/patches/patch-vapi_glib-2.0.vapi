--- vapi/glib-2.0.vapi.orig	2020-07-29 10:35:44 UTC
+++ vapi/glib-2.0.vapi
@@ -3794,6 +3794,8 @@ namespace GLib {
 		public static FileStream? open (string path, string mode);
 		[CCode (cname = "fdopen")]
 		public static FileStream? fdopen (int fildes, string mode);
+		[CCode (cname = "freopen", instance_pos = -1)]
+		public void reopen (string path, string mode);
 		[CCode (cname = "fprintf")]
 		[PrintfFormat ()]
 		public void printf (string format, ...);
