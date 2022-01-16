From 16ae5af7b7c56ed285e8ebdacadffa03acab5644 Mon Sep 17 00:00:00 2001
From: Ka Ho Ng <khng@FreeBSD.org>
Date: Tue, 11 Jan 2022 23:27:48 -0500
Subject: [PATCH] natpmp_declspec.h: Rename header guard to
 NATPMP_DECLSPEC_H_INCLUDED

---
 natpmp_declspec.h | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

--- natpmp_declspec.h.orig
+++ natpmp_declspec.h
@@ -1,5 +1,5 @@
-#ifndef DECLSPEC_H_INCLUDED
-#define DECLSPEC_H_INCLUDED
+#ifndef NATPMP_DECLSPEC_H_INCLUDED
+#define NATPMP_DECLSPEC_H_INCLUDED
 
 #if defined(_WIN32) && !defined(NATPMP_STATICLIB)
 	/* for windows dll */
