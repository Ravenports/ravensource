--- encoder/encoder.cpp.orig	2017-11-29 03:21:40 UTC
+++ encoder/encoder.cpp
@@ -575,7 +575,7 @@ int Encoder::setAnalysisDataAfterZScan(x
                             {
                                 int mv_x = ((analysis_inter_data *)curFrame->m_analysisData.interData)->mv[k][(mbIndex * 16) + cuOffset].x;
                                 int mv_y = ((analysis_inter_data *)curFrame->m_analysisData.interData)->mv[k][(mbIndex * 16) + cuOffset].y;
-                                double mv = sqrt(mv_x*mv_x + mv_y*mv_y);
+                                double mv = sqrt((double)(mv_x*mv_x + mv_y*mv_y));
                                 if (numPU == PU_2Nx2N && ((srcInterData)->depth[cuPos + cuOffset] == (m_param->maxCUSize >> 5)) && mv <= MVTHRESHOLD)
                                     memset(&curFrame->m_analysisData.modeFlag[k][cuPos + cuOffset], 1, bytes);
                             }
@@ -658,7 +658,7 @@ int Encoder::setAnalysisData(x265_analys
                                     {
                                         int mv_x = ((analysis_inter_data *)curFrame->m_analysisData.interData)->mv[i][count + pu].x;
                                         int mv_y = ((analysis_inter_data *)curFrame->m_analysisData.interData)->mv[i][count + pu].y;
-                                        double mv = sqrt(mv_x*mv_x + mv_y*mv_y);
+                                        double mv = sqrt((double)(mv_x*mv_x + mv_y*mv_y));
                                         if (numPU == PU_2Nx2N && m_param->num4x4Partitions <= 16 && mv <= MVTHRESHOLD)
                                             memset(&curFrame->m_analysisData.modeFlag[i][count + pu], 1, bytes);
                                     }
