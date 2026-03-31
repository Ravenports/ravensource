--- nczarr_test/ncdumpchunks.c.orig	2025-02-07 21:40:00 UTC
+++ nczarr_test/ncdumpchunks.c
@@ -412,7 +412,7 @@ dump(Format* format)
 #ifdef H5
 	case NC_FORMATX_NC_HDF5: {
 	    for(i=0;i<format->rank;i++) hoffset[i] = (hsize_t)offset[i];
-	    if(H5Dread_chunk(datasetid, dxpl_id, hoffset, &filter_mask, chunkdata) < 0)
+	    if(H5Dread_chunk1(datasetid, dxpl_id, hoffset, &filter_mask, chunkdata) < 0)
 	        holechunk = 1;
 	} break;
 #endif
