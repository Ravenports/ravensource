Avoid DS conflict on SunOS

--- modules/core/src/downhill_simplex.cpp.orig	2018-12-21 14:31:20 UTC
+++ modules/core/src/downhill_simplex.cpp
@@ -449,7 +449,9 @@ protected:
     }
 };
 
-
+#ifdef __sun__
+#undef DS
+#endif
 // both minRange & minError are specified by termcrit.epsilon;
 // In addition, user may specify the number of iterations that the algorithm does.
 Ptr<DownhillSolver> DownhillSolver::create( const Ptr<MinProblemSolver::Function>& f,
