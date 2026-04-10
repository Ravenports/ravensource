--- vapi/glib-2.0.vapi.orig	2025-03-02 19:20:12.000000000 -0000
+++ vapi/glib-2.0.vapi
@@ -4068,6 +4068,8 @@ namespace GLib {
 		public static FileStream? open (string path, string mode);
 		[CCode (cname = "fdopen")]
 		public static FileStream? fdopen (int fildes, string mode);
+		[CCode (cname = "freopen", instance_pos = -1)]
+		public void reopen (string path, string mode);
 		[CCode (cname = "fprintf")]
 		[PrintfFormat ()]
 		public int printf (string format, ...);
