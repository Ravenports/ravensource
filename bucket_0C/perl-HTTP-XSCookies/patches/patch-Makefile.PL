--- Makefile.PL.orig	2018-03-09 08:28:14 UTC
+++ Makefile.PL
@@ -59,12 +59,7 @@ sub cflags {
     /;
     # $self->{CCFLAGS} .= " -W$_" for @warning_flags_gonzo;
 
-    # solaris refuses to compile unless we are using C99
-    if ($^O eq 'solaris') {
         $self->{CCFLAGS} .= ' -std=c99';
-    } else {
-        $self->{CCFLAGS} .= ' -std=c89';
-    }
 
     # Need this define for localtime_r(), except on FreeBSD
     if ($^O ne 'freebsd') {
