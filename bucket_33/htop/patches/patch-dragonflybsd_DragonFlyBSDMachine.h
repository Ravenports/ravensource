--- dragonflybsd/DragonFlyBSDMachine.h.orig	2024-01-10 09:54:15 UTC
+++ dragonflybsd/DragonFlyBSDMachine.h
@@ -56,6 +56,6 @@ typedef struct DragonFlyBSDMachine_ {
    unsigned long* cp_times_n;
 } DragonFlyBSDMachine;
 
-char* DragonFlyBSDMachine_readJailName(DragonFlyBSDMachine* host, int jailid);
+char* DragonFlyBSDMachine_readJailName(const DragonFlyBSDMachine* host, int jailid);
 
 #endif
