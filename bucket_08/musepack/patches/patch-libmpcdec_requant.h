--- libmpcdec/requant.h.orig	2009-02-23 18:44:04 UTC
+++ libmpcdec/requant.h
@@ -47,9 +47,9 @@ extern "C" {
 
 
 /* C O N S T A N T S */
-const mpc_uint8_t      Res_bit [18];     ///< Bits per sample for chosen quantizer
-const MPC_SAMPLE_FORMAT __Cc    [1 + 18]; ///< Requantization coefficients
-const mpc_int16_t       __Dc    [1 + 18]; ///< Requantization offset
+extern const mpc_uint8_t      Res_bit [18];     ///< Bits per sample for chosen quantizer
+extern const MPC_SAMPLE_FORMAT __Cc    [1 + 18]; ///< Requantization coefficients
+extern const mpc_int16_t       __Dc    [1 + 18]; ///< Requantization offset
 
 #define Cc (__Cc + 1)
 #define Dc (__Dc + 1)
