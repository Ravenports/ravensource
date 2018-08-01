--- libsrc/posix-unsafe_process_primitives.adb.orig	2017-05-16 10:40:58 UTC
+++ libsrc/posix-unsafe_process_primitives.adb
@@ -40,6 +40,7 @@ with POSIX.C,
      POSIX.Implementation,
      System,
      System.Soft_Links,
+     System.Secondary_Stack,
      Unchecked_Conversion;
 
 package body POSIX.Unsafe_Process_Primitives is
@@ -88,9 +89,10 @@ package body POSIX.Unsafe_Process_Primit
    function Fork return POSIX.Process_Identification.Process_ID is
       Result : pid_t;
       package SSL renames System.Soft_Links;
+      package SST renames System.Secondary_Stack;
       --  save local values of soft-link data
-      NT_Sec_Stack_Addr : constant System.Address :=
-                            SSL.Get_Sec_Stack_Addr.all;
+      NT_Sec_Stack      : constant SST.SS_Stack_Ptr :=
+                            SSL.Get_Sec_Stack.all;
       NT_Jmpbuf_Address : constant System.Address :=
                             SSL.Get_Jmpbuf_Address.all;
    begin
@@ -106,10 +108,10 @@ package body POSIX.Unsafe_Process_Primit
          SSL.Unlock_Task        := SSL.Task_Unlock_NT'Access;
          SSL.Get_Jmpbuf_Address := SSL.Get_Jmpbuf_Address_NT'Access;
          SSL.Set_Jmpbuf_Address := SSL.Set_Jmpbuf_Address_NT'Access;
-         SSL.Get_Sec_Stack_Addr := SSL.Get_Sec_Stack_Addr_NT'Access;
-         SSL.Set_Sec_Stack_Addr := SSL.Set_Sec_Stack_Addr_NT'Access;
+         SSL.Get_Sec_Stack      := SSL.Get_Sec_Stack_NT'Access;
+         SSL.Set_Sec_Stack      := SSL.Set_Sec_Stack_NT'Access;
          --  reset global data to saved local values for this thread
-         SSL.Set_Sec_Stack_Addr (NT_Sec_Stack_Addr);
+         SSL.Set_Sec_Stack (NT_Sec_Stack);
          SSL.Set_Jmpbuf_Address (NT_Jmpbuf_Address);
       end if;
       return To_Process_ID (Result);
