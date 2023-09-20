GCC 13.2 has a major regression.  The original code is legal Ada.
Bug report opened in June 2023:
https://gcc.gnu.org/bugzilla/show_bug.cgi?id=110488

--- pragmarc-b_strings.ads.orig	2023-07-15 15:24:51 UTC
+++ pragmarc-b_strings.ads
@@ -24,7 +24,7 @@ package PragmARC.B_Strings is
    type B_String (Max_Length : Positive := 1024) is tagged limited private;
    -- Default initial value is Null_B_String
 
-   Null_B_String : constant B_String; -- A string of zero characters
+   Null_B_String : constant B_String (Max_Length => 1); -- A string of zero characters
 
    function To_String (Source : in B_String) return String with
       Post => To_String'Result'First = 1 and To_String'Result'Last = Source.Length;
@@ -56,5 +56,5 @@ private -- PragmARC.B_Strings
       Value : String (1 .. Max_Length) := (1 .. Max_Length => ' ');
    end record;
 
-   Null_B_String : constant B_String := (Max_Length => 1, others => <>);
+   Null_B_String : constant B_String (Max_Length => 1) := (Max_Length => 1, others => <>);
 end PragmARC.B_Strings;
