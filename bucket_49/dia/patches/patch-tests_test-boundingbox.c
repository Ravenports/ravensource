--- tests/test-boundingbox.c.orig	2014-08-24 15:46:02 UTC
+++ tests/test-boundingbox.c
@@ -116,7 +116,7 @@ _add_bezier_tests (void)
     {
       gchar *testpath = g_strdup_printf ("/Dia/BoundingBox/Bezier%d", i+1);
 #if GLIB_CHECK_VERSION(2,16,0)
-      g_test_add_data_func (testpath, &_test_beziers[i], _check_one_bezier);
+      g_test_add_data_func (testpath, &_test_beziers[i], (GTestDataFunc)_check_one_bezier);
 #endif
       g_free (testpath);
     }
