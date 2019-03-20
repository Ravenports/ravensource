--- src/gui/DatabaseWidget.cpp.orig	2019-03-19 22:59:14 UTC
+++ src/gui/DatabaseWidget.cpp
@@ -1112,7 +1112,9 @@ void DatabaseWidget::search(const QStrin
     }
 
     m_searchingLabel->setVisible(true);
+#ifdef WITH_XC_KEESHARE
     m_shareLabel->setVisible(false);
+#endif
 
     emit searchModeActivated();
 }
