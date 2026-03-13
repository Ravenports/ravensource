--- codec/encoder/core/src/wels_preprocess.cpp.orig	2025-02-10 07:27:56 UTC
+++ codec/encoder/core/src/wels_preprocess.cpp
@@ -754,7 +754,7 @@ void CWelsPreProcess::BackgroundDetectio
     sRefPixMap.sRect.iRectHeight = pRefPicture->iHeightInPixel;
     sRefPixMap.eFormat = VIDEO_FORMAT_I420;
 
-    BGDParam.pBackgroundMbFlag = pVaaInfo->pVaaBackgroundMbFlag;
+    BGDParam.pBackgroundMbFlag = reinterpret_cast<signed char*>(pVaaInfo->pVaaBackgroundMbFlag);
     BGDParam.pCalcRes = & (pVaaInfo->sVaaCalcInfo);
     m_pInterfaceVp->Set (iMethodIdx, (void*)&BGDParam);
     m_pInterfaceVp->Process (iMethodIdx, &sSrcPixMap, &sRefPixMap);
@@ -901,7 +901,7 @@ void CWelsPreProcess::AnalyzePictureComp
 
     sComplexityAnalysisParam->iComplexityAnalysisMode = iComplexityAnalysisMode;
     sComplexityAnalysisParam->pCalcResult = & (pVaaInfo->sVaaCalcInfo);
-    sComplexityAnalysisParam->pBackgroundMbFlag = pVaaInfo->pVaaBackgroundMbFlag;
+    sComplexityAnalysisParam->pBackgroundMbFlag = reinterpret_cast<signed char*>(pVaaInfo->pVaaBackgroundMbFlag);
     if (pRefPicture)
       SetRefMbType (pCtx, & (sComplexityAnalysisParam->uiRefMbType), pRefPicture->iPictureType);
     sComplexityAnalysisParam->iCalcBgd = bCalculateBGD;
