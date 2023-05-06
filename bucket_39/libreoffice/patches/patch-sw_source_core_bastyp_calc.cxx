$NetBSD: patch-sw_source_core_bastyp_calc.cxx,v 1.2 2021/08/22 02:41:50 ryoon Exp $

For NetBSD at least.

--- sw/source/core/bastyp/calc.cxx.orig	2023-04-27 20:06:32 UTC
+++ sw/source/core/bastyp/calc.cxx
@@ -1083,7 +1083,7 @@ SwSbxValue SwCalc::PrimFunc(bool &rChkPo
             return StdFunc(&acos, true);
         case CALC_ABS:
             SAL_INFO("sw.calc", "abs");
-            return StdFunc(&abs, false);
+            return StdFunc(&fabs, false);
         case CALC_SIGN:
         {
             SAL_INFO("sw.calc", "sign");
