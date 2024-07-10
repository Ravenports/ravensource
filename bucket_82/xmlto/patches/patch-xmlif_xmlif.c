--- xmlif/xmlif.c.orig	2024-06-11 18:42:54 UTC
+++ xmlif/xmlif.c
@@ -1300,7 +1300,7 @@ static void process_else()
 
 #define INITIAL 0
 #define attrib 1
-#define val 2
+#define unique_val 2
 
 #ifndef YY_NO_UNISTD_H
 /* Special case for "unistd.h", since it is non-ANSI. We include it way
@@ -1597,7 +1597,7 @@ YY_RULE_SETUP
 case 8:
 YY_RULE_SETUP
 #line 218 "xmlif/xmlif.l"
-{BEGIN(val);}
+{BEGIN(unique_val);}
 	YY_BREAK
 case 9:
 YY_RULE_SETUP
@@ -1639,7 +1639,7 @@ ECHO;
 #line 1639 "xmlif/xmlif.c"
 case YY_STATE_EOF(INITIAL):
 case YY_STATE_EOF(attrib):
-case YY_STATE_EOF(val):
+case YY_STATE_EOF(unique_val):
 	yyterminate();
 
 	case YY_END_OF_BUFFER:
