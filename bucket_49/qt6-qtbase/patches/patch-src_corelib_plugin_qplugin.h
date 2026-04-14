--- src/corelib/plugin/qplugin.h.orig	2025-11-12 10:17:57 UTC
+++ src/corelib/plugin/qplugin.h
@@ -166,15 +166,23 @@ template <auto (&PluginMetaData)> class
 #  define QT_PLUGIN_METADATAV2_SECTION
     using Payload = StaticPayload;
 #elif defined(Q_OF_ELF)
-#  ifdef Q_CC_CLANG
+#  if defined(__sun)
+
+     // Solaris/OmniOS: Rename section to avoid ELF Note validation mangling
+#    define QT_PLUGIN_METADATAV2_SECTION \
+            __attribute__((section(".qtmetadata"), used, aligned(8)))
+     using Payload = RegularPayload; 
+
+#  elif defined Q_CC_CLANG
 #    define QT_PLUGIN_METADATAV2_SECTION                                                            \
             __attribute__((section(".note.qt.metadata"), used, aligned(alignof(void *)),            \
                            no_sanitize("address")))
+     using Payload = ElfNotePayload;
 #  else
 #    define QT_PLUGIN_METADATAV2_SECTION                                                            \
             __attribute__((section(".note.qt.metadata"), used, aligned(alignof(void *))))
+     using Payload = ElfNotePayload;
 #  endif
-    using Payload = ElfNotePayload;
 #else
 #  define QT_PLUGIN_METADATAV2_SECTION      QT_PLUGIN_METADATA_SECTION
     using Payload = RegularPayload;
