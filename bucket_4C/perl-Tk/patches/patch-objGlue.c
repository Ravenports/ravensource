--- objGlue.c.orig	2019-10-20 16:36:39 UTC
+++ objGlue.c
@@ -625,9 +625,11 @@ Tcl_GetByteArrayFromObj(Tcl_Obj * objPtr
  /* SRT: Is this correct? */
  dTHX;
  sv_utf8_downgrade(objPtr, 0);
+ long unsigned int mylen;
  if (lengthPtr)
   {
-   return (unsigned char *) SvPV(objPtr, *lengthPtr);
+   mylen = (long unsigned int)*lengthPtr;
+   return (unsigned char *) SvPV(objPtr, mylen);
   }
  else
   {
