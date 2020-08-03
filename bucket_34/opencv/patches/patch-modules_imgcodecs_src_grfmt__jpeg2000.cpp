--- modules/imgcodecs/src/grfmt_jpeg2000.cpp.orig	2020-07-17 22:43:40 UTC
+++ modules/imgcodecs/src/grfmt_jpeg2000.cpp
@@ -378,7 +378,7 @@ bool  Jpeg2KDecoder::readComponent8u( uc
 
     for( y = 0; y < yend - ystart; )
     {
-        jas_seqent_t* pix_row = &jas_matrix_get( buffer, y / ystep, 0 );
+        jas_seqent_t* pix_row = jas_matrix_getref( buffer, y / ystep, 0 );
         uchar* dst = data + (y - yoffset) * step - xoffset;
 
         if( xstep == 1 )
@@ -444,7 +444,7 @@ bool  Jpeg2KDecoder::readComponent16u( u
 
     for( y = 0; y < yend - ystart; )
     {
-        jas_seqent_t* pix_row = &jas_matrix_get( buffer, y / ystep, 0 );
+        jas_seqent_t* pix_row = jas_matrix_getref( buffer, y / ystep, 0 );
         ushort* dst = data + (y - yoffset) * step - xoffset;
 
         if( xstep == 1 )
