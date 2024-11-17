--- pTk/mTk/generic/tkEvent.c.orig	2013-11-15 23:50:03 UTC
+++ pTk/mTk/generic/tkEvent.c
@@ -1153,6 +1153,7 @@ TkEventDeadWindow(winPtr)
 Time
 TkCurrentTime(dispPtr, fallbackCurrent)
     TkDisplay *dispPtr;		/* Display for which the time is desired. */
+    int fallbackCurrent;
 {
     register XEvent *eventPtr;
     ThreadSpecificData *tsdPtr = (ThreadSpecificData *)
