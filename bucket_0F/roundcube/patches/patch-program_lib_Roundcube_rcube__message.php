--- program/lib/Roundcube/rcube_message.php.orig	2024-08-04 09:45:14 UTC
+++ program/lib/Roundcube/rcube_message.php
@@ -912,8 +912,7 @@ class rcube_message
                 else if (
                     preg_match('/^(inline|attach)/', $mail_part->disposition)
                     || !empty($mail_part->headers['content-id'])
-                    || ($mail_part->filename &&
-                        (empty($mail_part->disposition) || preg_match('/^[a-z0-9!#$&.+^_-]+$/i', $mail_part->disposition)))
+                    || $mail_part->filename
                 ) {
                     // skip apple resource forks
                     if ($message_ctype_secondary == 'appledouble' && $secondary_type == 'applefile') {
