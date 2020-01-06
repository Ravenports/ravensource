From c47709338b14169b8e68aa342ae547dbc73f5281 Mon Sep 17 00:00:00 2001
From: rezso <rezso@rezso.net>
Date: Tue, 31 Dec 2019 02:56:23 +0100
Subject: [PATCH] Fix build with Qt 5.14
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit

In file included from Renderer.h:10,
                 from PropDialog.h:9,
                 from PropDialog.cpp:8:
Annotation.h:38:11: error: ???QImage??? does not name a type
---
 src-qt5/Annotation.h | 1 +
 1 file changed, 1 insertion(+)

--- Annotation.h.orig
+++ Annotation.h
@@ -1,4 +1,5 @@
 #include <QColor>
+#include <QImage>
 #include <QList>
 #include <QPointF>
 #include <QPolygonF>