--- Event/Event.xs.orig	2021-02-07 16:34:03 UTC
+++ Event/Event.xs
@@ -1532,12 +1532,12 @@ PROTOTYPES: DISABLE
 BOOT:
  {
 #ifdef pWARN_NONE
-  SV *old_warn = PL_curcop->cop_warnings;
+  SV *old_warn = (SV *)PL_curcop->cop_warnings;
   PL_curcop->cop_warnings = pWARN_NONE;
 #endif
   newXS("Tk::Event::INIT", XS_Tk__Event_INIT, file);
 #ifdef pWARN_NONE
- PL_curcop->cop_warnings = old_warn;
+ PL_curcop->cop_warnings = (char *)old_warn;
 #endif
   newXS("Tk::Callback::Call", XS_Tk__Callback_Call, __FILE__);
   install_vtab(aTHX_ "TkeventVtab",TkeventVGet(),sizeof(TkeventVtab));
