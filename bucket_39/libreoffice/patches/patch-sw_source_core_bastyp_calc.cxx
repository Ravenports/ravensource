$NetBSD: patch-sw_source_core_bastyp_calc.cxx,v 1.2 2021/08/22 02:41:50 ryoon Exp $

For NetBSD at least.

--- sw/source/core/bastyp/calc.cxx.orig	2024-04-29 18:46:10 UTC
+++ sw/source/core/bastyp/calc.cxx
@@ -1042,7 +1042,7 @@ SwSbxValue SwCalc::PrimFunc(bool &rChkPo
             return StdFunc(&acos, true);
         case CALC_ABS:
             SAL_INFO("sw.calc", "abs");
-            return StdFunc(&abs, false);
+            return StdFunc(&fabs, false);
         case CALC_SIGN:
         {
             SAL_INFO("sw.calc", "sign");
