--- vapi/glib-2.0.vapi.orig	2018-12-20 14:54:58 UTC
+++ vapi/glib-2.0.vapi
@@ -3608,6 +3608,8 @@ namespace GLib {
 		public static FileStream? open (string path, string mode);
 		[CCode (cname = "fdopen")]
 		public static FileStream? fdopen (int fildes, string mode);
+		[CCode (cname = "freopen", instance_pos = -1)]
+		public void reopen (string path, string mode);
 		[CCode (cname = "fprintf")]
 		[PrintfFormat ()]
 		public void printf (string format, ...);
