--- libfreeipmi/driver/ipmi-kcs-driver.c.orig	2023-06-05 22:58:26 UTC
+++ libfreeipmi/driver/ipmi-kcs-driver.c
@@ -145,7 +145,7 @@
 
 #define IPMI_KCS_MICROSECONDS_IN_SECOND 1000000
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 # include <machine/cpufunc.h>
 # include <machine/sysarch.h>
 #elif defined(__NetBSD__) || defined(__OpenBSD__)
@@ -159,7 +159,7 @@
 # include <asm/io.h>
 #endif
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 # define _INB(port)  inb (port)
 # define _OUTB(data, port)  outb (port, data)
 #elif defined(HAVE_INB) && defined(HAVE_OUTB)
@@ -197,7 +197,7 @@ struct ipmi_kcs_ctx {
   uint8_t register_spacing;
   unsigned int flags;
   unsigned int poll_interval;
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 #ifndef USE_IOPERM
   int dev_fd;
 #endif
@@ -275,7 +275,7 @@ ipmi_kcs_ctx_create (void)
   ctx->register_spacing = IPMI_KCS_SMS_REGISTER_SPACING_DEFAULT;
   ctx->flags = IPMI_KCS_FLAGS_DEFAULT;
   ctx->poll_interval = IPMI_KCS_SLEEP_USECS;
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 #ifndef USE_IOPERM
   ctx->dev_fd = -1;
 #endif
@@ -303,7 +303,7 @@ ipmi_kcs_ctx_destroy (ipmi_kcs_ctx_t ctx
 
   ctx->magic = ~IPMI_KCS_CTX_MAGIC;
   ctx->errnum = IPMI_KCS_ERR_SUCCESS;
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 #ifndef USE_IOPERM
   /* ignore potential error, destroy path */
   close (ctx->dev_fd);
@@ -492,7 +492,7 @@ ipmi_kcs_ctx_io_init (ipmi_kcs_ctx_t ctx
   if (ctx->io_init)
     goto out;
 
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 #ifdef USE_IOPERM
   /* i386_set_ioperm has known problems on FBSD 5.x (bus errors). */
   if (i386_set_ioperm (ctx->driver_address, 0x02, 0x01))
