--- dragonflybsd/DragonFlyBSDMachine.c.orig	2024-01-10 09:54:15 UTC
+++ dragonflybsd/DragonFlyBSDMachine.c
@@ -119,7 +119,7 @@ Machine* Machine_new(UsersTable* usersTa
 }
 
 void Machine_delete(Machine* super) {
-   const DragonFlyBSDMachine* this = (const DragonFlyBSDMachine*) super;
+   DragonFlyBSDMachine* this = (DragonFlyBSDMachine*) super;
 
    Machine_done(super);
 
@@ -223,7 +223,7 @@ static void DragonFlyBSDMachine_scanCPUT
 }
 
 static void DragonFlyBSDMachine_scanMemoryInfo(Machine* super) {
-   DragonFlyBSDMachine* this = (DragonFlyBSDProcessTable*) super;
+   DragonFlyBSDMachine* this = (DragonFlyBSDMachine*) super;
 
    // @etosan:
    // memory counter relationships seem to be these:
@@ -319,7 +319,7 @@ retry:
    free(jails);
 }
 
-char* DragonFlyBSDMachine_readJailName(DragonFlyBSDMachine* host, int jailid) {
+char* DragonFlyBSDMachine_readJailName(const DragonFlyBSDMachine* host, int jailid) {
    char* hostname;
    char* jname;
 
@@ -339,3 +339,12 @@ void Machine_scan(Machine* super) {
    DragonFlyBSDMachine_scanCPUTime(super);
    DragonFlyBSDMachine_scanJails(this);
 }
+
+bool Machine_isCPUonline(const Machine* host, unsigned int id) {
+   assert(id < host->existingCPUs);
+
+   // TODO: support offline CPUs and hot swapping
+   (void) host; (void) id;
+
+   return true;
+}
