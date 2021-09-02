--- CPP/Windows/ErrorMsg.cpp.orig	2015-01-18 18:20:28 UTC
+++ CPP/Windows/ErrorMsg.cpp
@@ -13,7 +13,7 @@ UString MyFormatMessage(DWORD errorCode)
   const char * txt = 0;
   AString msg;
 
-  switch(errorCode) {
+  switch(HRESULT(errorCode)) {
     case ERROR_NO_MORE_FILES   : txt = "No more files"; break ;
     case E_NOTIMPL             : txt = "E_NOTIMPL"; break ;
     case E_NOINTERFACE         : txt = "E_NOINTERFACE"; break ;
@@ -43,7 +43,7 @@ bool MyFormatMessage(DWORD messageID, CS
   const char * txt = 0;
   AString msg;
 
-  switch(messageID) {
+  switch(HRESULT(messageID)) {
     case ERROR_NO_MORE_FILES   : txt = "No more files"; break ;
     case E_NOTIMPL             : txt = "E_NOTIMPL"; break ;
     case E_NOINTERFACE         : txt = "E_NOINTERFACE"; break ;
