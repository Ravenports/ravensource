--- lib/wx/c_src/gen/wxe_wrapper_7.cpp.orig	2026-01-13 09:25:18 UTC
+++ lib/wx/c_src/gen/wxe_wrapper_7.cpp
@@ -2341,7 +2341,11 @@ void wxToolBar_AddTool_4(WxeApp *app, wx
     } else        Badarg("Options");
   };
   if(!This) throw wxe_badarg("This");
+#if wxCHECK_VERSION(3,1,6)
+  wxToolBarToolBase * Result = (wxToolBarToolBase*)This->AddTool(toolId,label,(wxBitmapBundle)*bitmap,shortHelp,kind);
+#else < 3.1.6
   wxToolBarToolBase * Result = (wxToolBarToolBase*)This->AddTool(toolId,label,*bitmap,shortHelp,kind);
+#endif
   wxeReturn rt = wxeReturn(memenv, Ecmd.caller, true);
   rt.send(  rt.make_ref(app->getRef((void *)Result,memenv), "wx"));
 
