--- cui/source/options/optjava.cxx.orig	2023-08-08 19:49:18 UTC
+++ cui/source/options/optjava.cxx
@@ -940,6 +940,7 @@ void SvxJavaClassPathDlg::SetClassPath(
     if ( m_sOldPath.isEmpty() )
         m_sOldPath = _rPath;
     m_xPathList->clear();
+#if HAVE_FEATURE_JAVA
     if (!_rPath.isEmpty())
     {
         std::vector paths = jfw_convertUserPathList(_rPath);
@@ -961,6 +962,7 @@ void SvxJavaClassPathDlg::SetClassPath(
         // select first entry
         m_xPathList->select(0);
     }
+#endif
     SelectHdl_Impl(*m_xPathList);
 }
 
