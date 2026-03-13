--- sql/item_numconvfunc.cc.orig	2026-02-06 17:11:17 UTC
+++ sql/item_numconvfunc.cc
@@ -50,10 +50,10 @@ public:
   class Single_char_token
   {
   public:
-    static constexpr uchar _C= 'C'; // Positional currency (C, L, U)
-    static constexpr uchar _B= 'B'; // Prefix/inline flag B
-    static constexpr uchar _S= 'S'; // Sign S
-    static constexpr uchar _G= 'G'; // Group decimiter G
+    static constexpr uchar HC= 'C'; // Positional currency (C, L, U)
+    static constexpr uchar HB= 'B'; // Prefix/inline flag B
+    static constexpr uchar HS= 'S'; // Sign S
+    static constexpr uchar HG= 'G'; // Group decimiter G
     // Single char tokens: $ B . D , G 09 C L U
     static uchar elem(uchar ch)
     {
@@ -63,10 +63,10 @@ public:
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* ................ */
          0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, /*  !"#$%&'()*+,-./ */
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* 0123456789:;<=>? */
-         0, 0,_B,_C, 1, 0, 0,_G, 0, 0, 0, 0,_C, 0, 0, 0, /* @ABCDEFGHIJKLMNO */
-         0, 0, 0,_S, 0,_C, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* PQRSTUVWXYZ[\]^_ */
-         0, 0,_B,_C, 1, 0, 0,_G, 0, 0, 0, 0,_C, 0, 0, 0, /* `abcdefghijklmno */
-         0, 0, 0,_S, 0,_C, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* pqrstuvwxyz{|}~. */
+         0, 0,HB,HC, 1, 0, 0,HG, 0, 0, 0, 0,HC, 0, 0, 0, /* @ABCDEFGHIJKLMNO */
+         0, 0, 0,HS, 0,HC, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* PQRSTUVWXYZ[\]^_ */
+         0, 0,HB,HC, 1, 0, 0,HG, 0, 0, 0, 0,HC, 0, 0, 0, /* `abcdefghijklmno */
+         0, 0, 0,HS, 0,HC, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* pqrstuvwxyz{|}~. */
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* ................ */
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* ................ */
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* ................ */
@@ -83,19 +83,19 @@ public:
   // Wrappers for the above class
   static bool is_positional_currency(char ch)
   {
-    return Single_char_token::elem((uchar) ch) == Single_char_token::_C;
+    return Single_char_token::elem((uchar) ch) == Single_char_token::HC;
   }
   static bool is_currency_flag_B(char ch)
   {
-    return Single_char_token::elem((uchar) ch) == Single_char_token::_B;
+    return Single_char_token::elem((uchar) ch) == Single_char_token::HB;
   }
   static bool is_group_delimiter_G(char ch)
   {
-    return Single_char_token::elem((uchar) ch) == Single_char_token::_G;
+    return Single_char_token::elem((uchar) ch) == Single_char_token::HG;
   }
   static bool is_sign_S(char ch)
   {
-    return Single_char_token::elem((uchar) ch) == Single_char_token::_S;
+    return Single_char_token::elem((uchar) ch) == Single_char_token::HS;
   }
   // Combining wrappers
   static bool is_currency_flag(char ch)
