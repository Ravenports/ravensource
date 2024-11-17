--- tkGlue.c.orig	2021-02-07 16:34:04 UTC
+++ tkGlue.c
@@ -5549,15 +5549,15 @@ _((pTHX))
 #define COP_WARNINGS_TYPE SV*
 #endif
 #ifdef pWARN_NONE
- COP_WARNINGS_TYPE old_warn = PL_curcop->cop_warnings;
- PL_curcop->cop_warnings = pWARN_NONE;
+ COP_WARNINGS_TYPE old_warn = (long unsigned int*)PL_curcop->cop_warnings;
+ PL_curcop->cop_warnings = (char*)pWARN_NONE;
 #endif
 
  /* Arrange to call initialization code - an XSUB called INIT */
  cv = newXS("Tk::INIT", XS_Tk_INIT, __FILE__);
 
 #ifdef pWARN_NONE
- PL_curcop->cop_warnings = old_warn;
+ PL_curcop->cop_warnings = (char*)old_warn;
 #endif
 
  initialized = 0;
