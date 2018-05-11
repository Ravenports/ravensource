--- src/video/x11/SDL_x11sym.h.orig	2012-01-19 06:30:06 UTC
+++ src/video/x11/SDL_x11sym.h
@@ -165,7 +165,7 @@ SDL_X11_SYM(Bool,XShmQueryExtension,(Dis
  */
 #ifdef LONG64
 SDL_X11_MODULE(IO_32BIT)
-SDL_X11_SYM(int,_XData32,(Display *dpy,register long *data,unsigned len),(dpy,data,len),return)
+SDL_X11_SYM(int,_XData32,(Display *dpy,register _Xconst long *data,unsigned len),(dpy,data,len),return)
 SDL_X11_SYM(void,_XRead32,(Display *dpy,register long *data,long len),(dpy,data,len),)
 #endif
 
