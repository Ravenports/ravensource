--- cui/source/options/optjava.cxx.orig	2025-12-01 19:30:03 UTC
+++ cui/source/options/optjava.cxx
@@ -983,6 +983,7 @@ void SvxJavaClassPathDlg::SetClassPath(
     if ( m_sOldPath.isEmpty() )
         m_sOldPath = _rPath;
     m_xPathList->clear();
+#if HAVE_FEATURE_JAVA
     if (!_rPath.isEmpty())
     {
         std::vector paths = jfw_convertUserPathList(_rPath);
@@ -1004,6 +1005,7 @@ void SvxJavaClassPathDlg::SetClassPath(
         // select first entry
         m_xPathList->select(0);
     }
+#endif
     SelectHdl_Impl(*m_xPathList);
 }
 #endif
