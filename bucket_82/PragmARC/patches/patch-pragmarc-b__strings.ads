GCC 13.2 has a major regression.  The original code is legal Ada.
Bug report opened in June 2023:
https://gcc.gnu.org/bugzilla/show_bug.cgi?id=110488

--- pragmarc-b_strings.ads.orig	2023-07-15 15:24:51 UTC
+++ pragmarc-b_strings.ads
@@ -21,7 +21,7 @@ pragma Assertion_Policy (Check);
 pragma Unsuppress (All_Checks);
 
 package PragmARC.B_Strings is
-   type B_String (Max_Length : Positive := 1024) is tagged limited private;
+   type B_String (Max_Length : Positive) is tagged private;
    -- Default initial value is Null_B_String
 
    Null_B_String : constant B_String; -- A string of zero characters
@@ -51,7 +51,7 @@ package PragmARC.B_Strings is
    function ">"  (Left : in B_String; Right : in B_String) return Boolean;
    function ">=" (Left : in B_String; Right : in B_String) return Boolean;
 private -- PragmARC.B_Strings
-   type B_String (Max_Length : Positive := 1024) is tagged limited record
+   type B_String (Max_Length : Positive) is tagged record
       Len   : Natural := 0;
       Value : String (1 .. Max_Length) := (1 .. Max_Length => ' ');
    end record;
