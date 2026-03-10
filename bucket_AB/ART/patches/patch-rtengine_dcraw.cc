--- rtengine/dcraw.cc.orig	2026-01-13 18:23:55 UTC
+++ rtengine/dcraw.cc
@@ -2335,7 +2335,9 @@ void CLASS hasselblad_correct()
                                             {bhu-1,0},{bhu-1,bwu/2},{bhu-1,bwu-1}};
             for (col = 0; col < bw; col++) {
                 for (i = 0; i < 9; i++) {
-                    ushort dist = (ushort)sqrt(abs((int)(corners[i][0] - row)) * abs((int)(corners[i][0] - row)) + abs((int)(corners[i][1] - col)) * abs((int)(corners[i][1] - col)));
+                    int dr = (int)corners[i][0] - (int)row;
+                    int dc = (int)corners[i][1] - (int)col;
+                    ushort dist = (ushort)std::sqrt((double)(dr*dr + dc*dc));
                     ushort weight = dist > maxdist ? 0 : maxdist - dist;
                     corners_weight[9*(row*bw+col)+i] = weight;
                 }
@@ -3029,7 +3031,7 @@ void CLASS lossy_dng_load_raw()
 	coeff[i] = getreal(12);
       for (i=0; i < 256; i++) {
 	for (tot=j=0; j <= deg; j++)
-	  tot += coeff[j] * pow(i/255.0, j);
+	  tot += coeff[j] * pow(i/255.0, (double)j);
 	cur[c][i] = tot*0xffff;
       }
     }
@@ -6855,7 +6857,7 @@ guess_cfa_pc:
 	    cblack[4] = cblack[5] = 1;
 	break;
       case 61450:
-	cblack[4] = cblack[5] = MIN(sqrt(len),64);
+	cblack[4] = cblack[5] = MIN(sqrt((double)len),64);
       case 50714:			/* BlackLevel */
                 RT_blacklevel_from_constant = ThreeValBool::F;
 //-----------------------------------------------------------------------------
