--- src/3rdparty/assimp/src/code/AssetLib/AMF/AMFImporter_Postprocess.cpp.orig	2021-08-27 08:22:22 UTC
+++ src/3rdparty/assimp/src/code/AssetLib/AMF/AMFImporter_Postprocess.cpp
@@ -329,8 +329,8 @@ void AMFImporter::Postprocess_AddMetadat
     sceneNode.mMetaData = aiMetadata::Alloc(static_cast<unsigned int>(metadataList.size()));
     size_t meta_idx(0);
 
-    for (const AMFMetadata &metadata : metadataList) {
-        sceneNode.mMetaData->Set(static_cast<unsigned int>(meta_idx++), metadata.Type, aiString(metadata.Value));
+    for (const AMFMetadata *metadata : metadataList) {
+        sceneNode.mMetaData->Set(static_cast<unsigned int>(meta_idx++), metadata->Type, aiString(metadata->Value));
     }
 }
 
