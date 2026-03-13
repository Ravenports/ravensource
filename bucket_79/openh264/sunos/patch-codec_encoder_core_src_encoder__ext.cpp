--- codec/encoder/core/src/encoder_ext.cpp.orig	2025-02-10 07:27:56 UTC
+++ codec/encoder/core/src/encoder_ext.cpp
@@ -1714,7 +1714,7 @@ int32_t RequestMemorySvc (sWelsEncCtx**
     (*ppCtx)->pVaa->sAdaptiveQuantParam.pMotionTextureUnit   = static_cast<SMotionTextureUnit*>
         (pMa->WelsMallocz (iCountMaxMbNum * sizeof (SMotionTextureUnit), "pVaa->sAdaptiveQuantParam.pMotionTextureUnit"));
     WELS_VERIFY_RETURN_IF (1, (NULL == (*ppCtx)->pVaa->sAdaptiveQuantParam.pMotionTextureUnit))
-    (*ppCtx)->pVaa->sAdaptiveQuantParam.pMotionTextureIndexToDeltaQp   = static_cast<int8_t*>
+    (*ppCtx)->pVaa->sAdaptiveQuantParam.pMotionTextureIndexToDeltaQp   = reinterpret_cast<signed char*>
         (pMa->WelsMallocz (iCountMaxMbNum * sizeof (int8_t), "pVaa->sAdaptiveQuantParam.pMotionTextureIndexToDeltaQp"));
     WELS_VERIFY_RETURN_IF (1, (NULL == (*ppCtx)->pVaa->sAdaptiveQuantParam.pMotionTextureIndexToDeltaQp))
   }
