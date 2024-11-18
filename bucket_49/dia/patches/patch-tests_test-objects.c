--- tests/test-objects.c.orig	2014-08-24 15:46:02 UTC
+++ tests/test-objects.c
@@ -259,19 +259,19 @@ _ot_item (gpointer key,
 
 #if GLIB_CHECK_VERSION(2,16,0)
   testpath = g_strdup_printf ("%s/%s/%s", base, name, "Creation");
-  g_test_add_data_func (testpath, type, _test_creation);
+  g_test_add_data_func (testpath, type, (GTestDataFunc) _test_creation);
   g_free (testpath);
 
   testpath = g_strdup_printf ("%s/%s/%s", base, name, "Copy");
-  g_test_add_data_func (testpath, type, _test_copy);
+  g_test_add_data_func (testpath, type, (GTestDataFunc) _test_copy);
   g_free (testpath);
 
   testpath = g_strdup_printf ("%s/%s/%s", base, name, "Movement");
-  g_test_add_data_func (testpath, type, _test_movement);
+  g_test_add_data_func (testpath, type, (GTestDataFunc) _test_movement);
   g_free (testpath);
 
   testpath = g_strdup_printf ("%s/%s/%s", base, name, "Change");
-  g_test_add_data_func (testpath, type, _test_change);
+  g_test_add_data_func (testpath, type, (GTestDataFunc) _test_change);
   g_free (testpath);
 #endif
 
