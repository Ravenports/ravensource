--- Cbc/src/CbcSolver.cpp.orig	2018-11-14 12:19:56 UTC
+++ Cbc/src/CbcSolver.cpp
@@ -1877,10 +1877,6 @@ int CbcMain1 (int argc, const char *argv
 	    }
 	    sprintf(generalPrint + strlen(generalPrint),
 		    "Build Date: %s \n", __DATE__);
-#ifdef CBC_SVN_REV
-	    sprintf(generalPrint + strlen(generalPrint),
-		    "Revision Number: %d \n", CBC_SVN_REV);
-#endif
             generalMessageHandler->message(CLP_GENERAL, generalMessages)
             << generalPrint
             << CoinMessageEol;
