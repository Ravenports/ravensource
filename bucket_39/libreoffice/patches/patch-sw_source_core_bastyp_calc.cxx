$NetBSD: patch-sw_source_core_bastyp_calc.cxx,v 1.2 2021/08/22 02:41:50 ryoon Exp $

For NetBSD at least.

--- sw/source/core/bastyp/calc.cxx.orig	2025-01-23 21:25:49 UTC
+++ sw/source/core/bastyp/calc.cxx
@@ -1007,7 +1007,7 @@ SwSbxValue SwCalc::PrimFunc(bool &rChkPo
             return StdFunc(&acos, true);
         case CALC_ABS:
             SAL_INFO("sw.calc", "abs");
-            return StdFunc(&abs, false);
+            return StdFunc(&fabs, false);
         case CALC_SIGN:
         {
             SAL_INFO("sw.calc", "sign");
