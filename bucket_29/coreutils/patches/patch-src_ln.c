From 6a707feee86ffd8eee1f8f1e7a701693d0489ffb Mon Sep 17 00:00:00 2001
From: Paul Eggert <eggert@cs.ucla.edu>
Date: Sat, 16 Mar 2019 11:24:19 -0700
Subject: [PATCH] ln: port to platforms lacking O_DIRECTORY
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit

* src/ln.c (main): Port to older platforms lacking
support for POSIX.1-2008’s O_DIRECTORY flag (Bug#34876).
---
 src/ln.c | 14 +++++++++++++-
 1 file changed, 13 insertions(+), 1 deletion(-)

--- src/ln.c
+++ src/ln.c
@@ -610,13 +610,25 @@ main (int argc, char **argv)
           int flags = (O_PATHSEARCH | O_DIRECTORY
                        | (dereference_dest_dir_symlinks ? 0 : O_NOFOLLOW));
           destdir_fd = openat_safer (AT_FDCWD, d, flags);
+          int err = errno;
+          if (!O_DIRECTORY && 0 <= destdir_fd)
+            {
+              struct stat st;
+              err = (fstat (destdir_fd, &st) != 0 ? errno
+                     : S_ISDIR (st.st_mode) ? 0 : ENOTDIR);
+              if (err != 0)
+                {
+                  close (destdir_fd);
+                  destdir_fd = -1;
+                }
+            }
           if (0 <= destdir_fd)
             {
               n_files -= !target_directory;
               target_directory = d;
             }
           else if (! (n_files == 2 && !target_directory))
-            die (EXIT_FAILURE, errno, _("target %s"), quoteaf (d));
+            die (EXIT_FAILURE, err, _("target %s"), quoteaf (d));
         }
     }
 
