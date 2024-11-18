--- objects/custom/custom_object.c.orig	2014-08-24 15:46:01 UTC
+++ objects/custom/custom_object.c
@@ -379,7 +379,7 @@ void custom_setup_properties (ShapeInfo
 	 Maybe it even works cause the sizeof() in *_get_data_size can be
 	 calculated at compile time. Anyway, a mess ;) --hb
       */
-      size = info->props[i].ops->get_data_size (&info->props[i]);
+      size = info->props[i].ops->get_data_size ((Property *)&info->props[i]);
       info->ext_attr_size += size;
       offs += size;
     }
