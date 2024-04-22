--- cui/source/options/optjava.cxx.orig	2024-03-22 19:34:51 UTC
+++ cui/source/options/optjava.cxx
@@ -979,6 +979,7 @@ void SvxJavaClassPathDlg::SetClassPath(
     if ( m_sOldPath.isEmpty() )
         m_sOldPath = _rPath;
     m_xPathList->clear();
+#if HAVE_FEATURE_JAVA
     if (!_rPath.isEmpty())
     {
         std::vector paths = jfw_convertUserPathList(_rPath);
@@ -1000,6 +1001,7 @@ void SvxJavaClassPathDlg::SetClassPath(
         // select first entry
         m_xPathList->select(0);
     }
+#endif
     SelectHdl_Impl(*m_xPathList);
 }
 #endif
