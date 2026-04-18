--- plugins/actor/corona/corona.cpp.orig	2023-03-20 02:04:42 UTC
+++ plugins/actor/corona/corona.cpp
@@ -118,7 +118,7 @@ bool Corona::setUpSurface(int width, int
 	}
 
 	// Change the number of particles
-	int newsize = (int) (::sqrt(m_width * m_height) * 3.0);
+	int newsize = (int) (::sqrt((double)m_width * m_height) * 3.0);
 	if (newsize < 2000) newsize = 2000;
 	int oldsize = (int) nbParticules;
 	nbParticules = newsize;
