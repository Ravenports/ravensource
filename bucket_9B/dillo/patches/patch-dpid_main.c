--- dpid/main.c.orig	2015-06-10 21:34:22 UTC
+++ dpid/main.c
@@ -231,7 +231,7 @@ int main(void)
    /* this sleep used to unmask a race condition */
    // sleep(2);
 
-   dpi_errno = no_errors;
+   enum dpi_errno error_code = no_errors;
 
    /* Get list of available dpis */
    numdpis = register_all(&dpi_attr_list);
@@ -254,7 +254,7 @@ int main(void)
 
    /* Initialise sockets */
    if ((numsocks = init_ids_srs_socket()) == -1) {
-      switch (dpi_errno) {
+      switch (error_code) {
       case dpid_srs_addrinuse:
          MSG_ERR("dpid refuses to start, possibly because:\n");
          MSG_ERR("\t1) An instance of dpid is already running.\n");
