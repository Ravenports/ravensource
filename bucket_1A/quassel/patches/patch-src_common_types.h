--- src/common/types.h.orig	2019-02-15 17:17:28.000000000 +0100
+++ src/common/types.h	2020-08-09 15:22:28.853998000 +0200
@@ -140,6 +140,7 @@
 typedef QList<MsgId> MsgIdList;
 typedef QList<BufferId> BufferIdList;
 
+#if QT_VERSION < QT_VERSION_CHECK(5, 14, 0)
 /**
  * Catch-all stream serialization operator for enum types.
  *
@@ -169,6 +170,7 @@
     value = static_cast<T>(v);
     return in;
 }
+#endif
 
 // Exceptions
 
