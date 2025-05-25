--- misc.h.orig	2025-05-15 15:31:27 UTC
+++ misc.h
@@ -28,6 +28,9 @@ void  xsetegid  (int);
 int   AddXChar (char *, int);
 int   AddXChars (char *, int, char *);
 
+time_t SessionCreationTime(const char *fifo);
+
+
 #define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
 
 #endif /* SCREEN_MISC_H */
