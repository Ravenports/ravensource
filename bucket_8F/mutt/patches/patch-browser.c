--- browser.c.orig	2020-03-28 18:17:53 UTC
+++ browser.c
@@ -32,6 +32,7 @@
 #ifdef USE_IMAP
 #include "imap.h"
 #endif
+#include "mx.h"
 
 #include <stdlib.h>
 #include <dirent.h>
@@ -86,6 +87,12 @@ static int browser_compare_subject (cons
   struct folder_file *pa = (struct folder_file *) a;
   struct folder_file *pb = (struct folder_file *) b;
 
+  /* Always keep '..' in first menu position */
+  if (!strncmp(pa->display_name, "..", 2))
+	  return(-1);
+  if (!strncmp(pb->display_name, "..", 2))
+	  return(1);
+
   int r = mutt_strcoll (pa->display_name, pb->display_name);
 
   return ((BrowserSort & SORT_REVERSE) ? -r : r);
@@ -96,6 +103,12 @@ static int browser_compare_date (const v
   struct folder_file *pa = (struct folder_file *) a;
   struct folder_file *pb = (struct folder_file *) b;
 
+  /* Always keep '..' in first menu position */
+  if (!strncmp(pa->display_name, "..", 2))
+	  return(-1);
+  if (!strncmp(pb->display_name, "..", 2))
+	  return(1);
+
   int r = pa->mtime - pb->mtime;
 
   return ((BrowserSort & SORT_REVERSE) ? -r : r);
@@ -106,6 +119,12 @@ static int browser_compare_size (const v
   struct folder_file *pa = (struct folder_file *) a;
   struct folder_file *pb = (struct folder_file *) b;
 
+  /* Always keep '..' in first menu position */
+  if (!strncmp(pa->display_name, "..", 2))
+	  return(-1);
+  if (!strncmp(pb->display_name, "..", 2))
+	  return(1);
+
   int r = pa->size - pb->size;
 
   return ((BrowserSort & SORT_REVERSE) ? -r : r);
@@ -430,6 +449,21 @@ static void init_state (struct browser_s
     menu->data = state->entry;
 }
 
+static void check_maildir_times (BUFFY *buf, struct stat *st)
+{
+  char buffer[_POSIX_PATH_MAX + SHORT_STRING];
+  struct stat s;
+
+  if(!buf || buf->magic != MUTT_MAILDIR)
+    return;
+
+  snprintf (buffer, sizeof (buffer), "%s/tmp", mutt_b2s(buf->pathbuf));
+  if (lstat (buffer, &s) != 0)
+    return;
+
+  st->st_mtime = s.st_mtime;
+}
+
 static int examine_directory (MUTTMENU *menu, struct browser_state *state,
 			      const char *d, const char *prefix)
 {
@@ -496,6 +530,7 @@ static int examine_directory (MUTTMENU *
     tmp = Incoming;
     while (tmp && mutt_strcmp (mutt_b2s (full_path), mutt_b2s (tmp->pathbuf)))
       tmp = tmp->next;
+    check_maildir_times (tmp, &s);
     if (tmp && Context &&
         !mutt_strcmp (tmp->realpath, Context->realpath))
     {
@@ -574,6 +609,7 @@ static int examine_mailboxes (MUTTMENU *
 	s.st_mtime = st2.st_mtime;
     }
 
+    check_maildir_times (tmp, &s);
     add_folder (menu, state, mutt_b2s (mailbox), mutt_b2s (tmp->pathbuf), &s, tmp);
   }
   while ((tmp = tmp->next));
