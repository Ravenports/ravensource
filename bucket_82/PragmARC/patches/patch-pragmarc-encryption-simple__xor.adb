--- pragmarc-encryption-simple_xor.adb.orig	2025-11-16 14:48:19 UTC
+++ pragmarc-encryption-simple_xor.adb
@@ -36,7 +36,7 @@ package body PragmARC.Encryption.Simple_
    end To_Bytes;
 
    procedure Crypt (Input_Name : in String; Output_Name : in String; Key : in Byte_List) is
-      package Byte_IO is new Ada.Sequential_IO (Element_Type => Byte_Value);
+      package Byte_IO is new Ada.Sequential_IO (Element_Type => Byte);
 
       subtype Key_List is Byte_List (1 .. Key'Length);
 
