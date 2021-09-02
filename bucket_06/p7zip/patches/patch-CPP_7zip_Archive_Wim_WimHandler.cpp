--- CPP/7zip/Archive/Wim/WimHandler.cpp.orig	2016-06-11 08:08:06 UTC
+++ CPP/7zip/Archive/Wim/WimHandler.cpp
@@ -298,7 +298,7 @@ STDMETHODIMP CHandler::GetArchivePropert
 
       AString res;
 
-      bool numMethods = 0;
+      unsigned numMethods = 0;
       for (unsigned i = 0; i < ARRAY_SIZE(k_Methods); i++)
       {
         if (methodMask & ((UInt32)1 << i))
