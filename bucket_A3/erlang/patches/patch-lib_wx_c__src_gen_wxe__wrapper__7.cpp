Fox Wx version >= 3.1.6

--- lib/wx/c_src/gen/wxe_wrapper_7.cpp.orig	2026-10-14 11:53:41 UTC
+++ lib/wx/c_src/gen/wxe_wrapper_7.cpp
@@ -2343,7 +2343,7 @@ void wxToolBar_AddTool_4(WxeApp *app, wx
   if(!enif_get_int(env, tpl[1], (int *) &kind)) Badarg("kind"); // enum
     } else        Badarg("Options");
   };
-  wxToolBarToolBase * Result = (wxToolBarToolBase*)This->AddTool(toolId,label,*bitmap,shortHelp,kind);
+  wxToolBarToolBase * Result = (wxToolBarToolBase*)This->AddTool(toolId,label,(wxBitmapBundle)*bitmap,shortHelp,kind);
   wxeReturn rt = wxeReturn(memenv, Ecmd.caller, true);
   rt.send(  rt.make_ref(app->getRef((void *)Result,memenv), "wx"));
 
