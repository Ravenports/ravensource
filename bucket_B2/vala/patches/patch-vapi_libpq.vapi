--- vapi/libpq.vapi.orig	2019-10-17 07:43:43 UTC
+++ vapi/libpq.vapi
@@ -20,11 +20,7 @@
  *	Jukka-Pekka Iivonen <jp0409@jippii.fi>
  */
 
-#if LIBPQ_9_3
 [CCode (cprefix = "PQ", cheader_filename = "libpq-fe.h")]
-#else
-[CCode (cprefix = "PQ", cheader_filename = "postgresql/libpq-fe.h")]
-#endif
 namespace Postgres {
 
 	[CCode (cname = "ConnStatusType", cprefix = "CONNECTION_", has_type_id = false)]
