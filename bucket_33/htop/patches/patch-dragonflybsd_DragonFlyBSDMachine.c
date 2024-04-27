--- dragonflybsd/DragonFlyBSDMachine.c.orig	2024-01-10 09:54:15 UTC
+++ dragonflybsd/DragonFlyBSDMachine.c
@@ -223,7 +223,7 @@ static void DragonFlyBSDMachine_scanCPUT
 }
 
 static void DragonFlyBSDMachine_scanMemoryInfo(Machine* super) {
-   DragonFlyBSDMachine* this = (DragonFlyBSDProcessTable*) super;
+   DragonFlyBSDMachine* this = (DragonFlyBSDMachine*) super;
 
    // @etosan:
    // memory counter relationships seem to be these:
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
