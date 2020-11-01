--- youtube_dl/options.py.orig	2020-11-01 01:52:19 UTC
+++ youtube_dl/options.py
@@ -138,10 +138,6 @@ def parseOpts(overrideArguments=None):
         action='version',
         help='Print program version and exit')
     general.add_option(
-        '-U', '--update',
-        action='store_true', dest='update_self',
-        help='Update this program to latest version. Make sure that you have sufficient permissions (run with sudo if needed)')
-    general.add_option(
         '-i', '--ignore-errors',
         action='store_true', dest='ignoreerrors', default=False,
         help='Continue on download errors, for example to skip unavailable videos in a playlist')
