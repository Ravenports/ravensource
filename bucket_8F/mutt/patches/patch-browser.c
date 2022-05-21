--- browser.c.orig	2022-04-21 21:35:19 UTC
+++ browser.c
@@ -99,6 +99,12 @@ static int browser_compare_subject (cons
   struct folder_file *pa = (struct folder_file *) a;
   struct folder_file *pb = (struct folder_file *) b;
 
+  /* Always keep '..' in first menu position */
+  if (!strncmp(pa->display_name, "..", 2))
+	  return(-1);
+  if (!strncmp(pb->display_name, "..", 2))
+	  return(1);
+
   int r = mutt_strcoll (pa->display_name, pb->display_name);
 
   return (sort_reverse_flag ? -r : r);
@@ -109,6 +115,12 @@ static int browser_compare_date (const v
   struct folder_file *pa = (struct folder_file *) a;
   struct folder_file *pb = (struct folder_file *) b;
 
+  /* Always keep '..' in first menu position */
+  if (!strncmp(pa->display_name, "..", 2))
+	  return(-1);
+  if (!strncmp(pb->display_name, "..", 2))
+	  return(1);
+
   int r = pa->mtime - pb->mtime;
 
   return (sort_reverse_flag ? -r : r);
@@ -119,6 +131,12 @@ static int browser_compare_size (const v
   struct folder_file *pa = (struct folder_file *) a;
   struct folder_file *pb = (struct folder_file *) b;
 
+  /* Always keep '..' in first menu position */
+  if (!strncmp(pa->display_name, "..", 2))
+	  return(-1);
+  if (!strncmp(pb->display_name, "..", 2))
+	  return(1);
+
   int r = pa->size - pb->size;
 
   return (sort_reverse_flag ? -r : r);
@@ -129,6 +147,12 @@ static int browser_compare_count (const
   struct folder_file *pa = (struct folder_file *) a;
   struct folder_file *pb = (struct folder_file *) b;
 
+  /* Always keep '..' in first menu position */
+  if (!strncmp(pa->display_name, "..", 2))
+	  return(-1);
+  if (!strncmp(pb->display_name, "..", 2))
+	  return(1);
+
   int r = pa->msg_count - pb->msg_count;
 
   return (sort_reverse_flag ? -r : r);
@@ -139,6 +163,12 @@ static int browser_compare_unread (const
   struct folder_file *pa = (struct folder_file *) a;
   struct folder_file *pb = (struct folder_file *) b;
 
+  /* Always keep '..' in first menu position */
+  if (!strncmp(pa->display_name, "..", 2))
+	  return(-1);
+  if (!strncmp(pb->display_name, "..", 2))
+	  return(1);
+
   int r = pa->msg_unread - pb->msg_unread;
 
   return (sort_reverse_flag ? -r : r);
