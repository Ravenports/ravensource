--- lumina-checkpass/lumina-checkpass.pro.orig	2021-10-02 19:05:49 UTC
+++ lumina-checkpass/lumina-checkpass.pro
@@ -13,6 +13,5 @@ LIBS     += -lpam
 SOURCES += main.c
 
 perms.path = $$DESTDIR$${PREFIX}/sbin
-perms.extra = "chmod 4555 $$DESTDIR$${PREFIX}/sbin/lumina-checkpass"
 
 INSTALLS += target perms
