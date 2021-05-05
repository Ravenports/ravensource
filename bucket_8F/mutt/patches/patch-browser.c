--- browser.c.orig	2021-05-04 17:41:27 UTC
+++ browser.c
@@ -86,6 +86,12 @@ static int browser_compare_subject (cons
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
@@ -96,6 +102,12 @@ static int browser_compare_date (const v
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
@@ -106,6 +118,12 @@ static int browser_compare_size (const v
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
@@ -116,6 +134,12 @@ static int browser_compare_count (const
   struct folder_file *pa = (struct folder_file *) a;
   struct folder_file *pb = (struct folder_file *) b;
 
+  /* Always keep '..' in first menu position */
+  if (!strncmp(pa->display_name, "..", 2))
+	  return(-1);
+  if (!strncmp(pb->display_name, "..", 2))
+	  return(1);
+
   int r = pa->msg_count - pb->msg_count;
 
   return ((BrowserSort & SORT_REVERSE) ? -r : r);
@@ -126,6 +150,12 @@ static int browser_compare_unread (const
   struct folder_file *pa = (struct folder_file *) a;
   struct folder_file *pb = (struct folder_file *) b;
 
+  /* Always keep '..' in first menu position */
+  if (!strncmp(pa->display_name, "..", 2))
+	  return(-1);
+  if (!strncmp(pb->display_name, "..", 2))
+	  return(1);
+
   int r = pa->msg_unread - pb->msg_unread;
 
   return ((BrowserSort & SORT_REVERSE) ? -r : r);
