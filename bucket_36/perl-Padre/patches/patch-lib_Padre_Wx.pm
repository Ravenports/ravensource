--- lib/Padre/Wx.pm.orig	2023-06-14 06:59:47 UTC
+++ lib/Padre/Wx.pm
@@ -158,6 +158,7 @@ sub aui_pane_info {
 
 sub launch_browser {
 	require Padre::Task::LaunchDefaultBrowser;
+	Wx::LaunchDefaultBrowser( $_[0] ); return 1;
 	Padre::Task::LaunchDefaultBrowser->new(
 		url => $_[0],
 	)->schedule;
