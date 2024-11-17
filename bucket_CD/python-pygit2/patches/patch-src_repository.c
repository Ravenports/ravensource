--- src/repository.c.orig	2024-08-19 07:09:41 UTC
+++ src/repository.c
@@ -1065,7 +1065,8 @@ Repository_create_commit(Repository *sel
 
     err = git_commit_create(&oid, self->repo, update_ref,
                             py_author->signature, py_committer->signature,
-                            encoding, message, tree, parent_count, parents);
+                            encoding, message, tree, parent_count,
+                            (const git_commit **)parents);
     if (err < 0) {
         Error_set(err);
         goto out;
@@ -1147,7 +1148,8 @@ Repository_create_commit_string(Reposito
 
     err = git_commit_create_buffer(&buf, self->repo,
                                    py_author->signature, py_committer->signature,
-                                   encoding, message, tree, parent_count, parents);
+                                   encoding, message, tree, parent_count,
+                                   (const git_commit **)parents);
     if (err < 0) {
         Error_set(err);
         goto out;
