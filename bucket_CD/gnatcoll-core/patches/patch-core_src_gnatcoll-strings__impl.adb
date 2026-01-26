Solve elaboration warnings:
libadalang-doc_utils.ads:34:04: warning: in instantiation at gnatcoll-strings_impl.adb:123 [-gnatw.f]
libadalang-doc_utils.ads:34:04: warning: "Access" attribute of "Make_Writable_Thread_Safe" before body seen [-gnatw.f]
libadalang-doc_utils.ads:34:04: warning: possible Program_Error on later references [-gnatw.f]
libadalang-doc_utils.ads:34:04: warning:   spec of unit "Doc_Utils" elaborated [-gnatw.f]
libadalang-doc_utils.ads:34:04: warning:   "Access" of "Make_Writable_Thread_Safe" taken at gnatcoll-strings_impl.adb:123, instance at line 34 [-gnatw.f]
libadalang-doc_utils.ads:34:04: warning: in instantiation at gnatcoll-strings_impl.adb:124 [-gnatw.f]
libadalang-doc_utils.ads:34:04: warning: "Access" attribute of "Make_Writable_Thread_Unsafe" before body seen [-gnatw.f]
libadalang-doc_utils.ads:34:04: warning: possible Program_Error on later references [-gnatw.f]
libadalang-doc_utils.ads:34:04: warning:   spec of unit "Doc_Utils" elaborated [-gnatw.f]
libadalang-doc_utils.ads:34:04: warning:   "Access" of "Make_Writable_Thread_Unsafe" taken at gnatcoll-strings_impl.adb:124, instance at line 34 [-gnatw.f]

--- core/src/gnatcoll-strings_impl.adb.orig	2025-11-28 12:36:47 UTC
+++ core/src/gnatcoll-strings_impl.adb
@@ -117,25 +117,6 @@ package body GNATCOLL.Strings_Impl is
       procedure Make_Writable_Thread_Safe (Self : in out XString) with Inline;
       procedure Make_Writable_Thread_Unsafe (Self : in out XString)
          with Inline;
-      Make_Writable : constant not null
-         access procedure (Self : in out XString) :=
-            (if GNATCOLL.Refcount.Application_Uses_Tasks
-             then Make_Writable_Thread_Safe'Access
-             else Make_Writable_Thread_Unsafe'Access);
-      --  Make sure we can modify Self (not a shared string)
-      --  Two versions are provided: the Unsafe version is faster, but will
-      --  fail when a string is read from a thread and written in another one,
-      --  as in the following scenario:
-      --            thread 1                   |               thread 2
-      --    S.Set ("some long long long str"); |
-      --    Append (S, "some long long str");  |
-      --    --  stops after testing refcount   |
-      --                                       | S2 := S;
-      --                                       | --  buffer is now shared
-      --                                       | Put_Line (S2.To_String);
-      --    --  modifies shared buffer         |
-      --                                       | Put_Line (S2.To_String);
-      --                                       | --  different output
 
       procedure Convert_To_Big_String
          (Self : in out XString;
@@ -232,6 +213,29 @@ package body GNATCOLL.Strings_Impl is
          end if;
       end Make_Writable_Thread_Safe;
 
+      -------------------
+      -- Make_Writable --
+      ------------------- 
+      Make_Writable : constant not null
+         access procedure (Self : in out XString) :=
+            (if GNATCOLL.Refcount.Application_Uses_Tasks
+             then Make_Writable_Thread_Safe'Access
+             else Make_Writable_Thread_Unsafe'Access);
+      --  Make sure we can modify Self (not a shared string)
+      --  Two versions are provided: the Unsafe version is faster, but will
+      --  fail when a string is read from a thread and written in another one,
+      --  as in the following scenario:
+      --            thread 1                   |               thread 2
+      --    S.Set ("some long long long str"); |
+      --    Append (S, "some long long str");  |
+      --    --  stops after testing refcount   |
+      --                                       | S2 := S;
+      --                                       | --  buffer is now shared
+      --                                       | Put_Line (S2.To_String);
+      --    --  modifies shared buffer         |
+      --                                       | Put_Line (S2.To_String);
+      --                                       | --  different output
+
       -----------
       -- Clone --
       -----------
