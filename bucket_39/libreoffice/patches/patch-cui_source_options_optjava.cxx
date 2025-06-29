--- cui/source/options/optjava.cxx.orig	2025-06-05 10:22:59 UTC
+++ cui/source/options/optjava.cxx
@@ -977,6 +977,7 @@ void SvxJavaClassPathDlg::SetClassPath(
     if ( m_sOldPath.isEmpty() )
         m_sOldPath = _rPath;
     m_xPathList->clear();
+#if HAVE_FEATURE_JAVA
     if (!_rPath.isEmpty())
     {
         std::vector paths = jfw_convertUserPathList(_rPath);
@@ -998,6 +999,7 @@ void SvxJavaClassPathDlg::SetClassPath(
         // select first entry
         m_xPathList->select(0);
     }
+#endif
     SelectHdl_Impl(*m_xPathList);
 }
 #endif
