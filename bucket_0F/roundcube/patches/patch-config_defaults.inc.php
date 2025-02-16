--- config/defaults.inc.php.orig	2025-02-08 08:47:42 UTC
+++ config/defaults.inc.php
@@ -932,7 +932,7 @@ $config['show_real_foldernames'] = false
 $config['quota_zero_as_unlimited'] = false;
 
 // Make use of the built-in spell checker.
-$config['enable_spellcheck'] = false;
+$config['enable_spellcheck'] = true;
 
 // Enables spellchecker exceptions dictionary.
 // Setting it to 'shared' will make the dictionary shared by all users.
@@ -946,10 +946,10 @@ $config['spellcheck_dictionary'] = false
 // Since Google shut down their public spell checking service, the default settings
 // connect to https://spell.roundcube.net which is a hosted service provided by Roundcube.
 // You can connect to any other googie-compliant service by setting 'spellcheck_uri' accordingly.
-$config['spellcheck_engine'] = 'googie';
+$config['spellcheck_engine'] = 'enchant';
 
-// For locally installed Nox Spell Server or After the Deadline services,
-// please specify the URI to call it.
+// For a locally installed spellcheker, specify the URI to call it, for example:
+// 'http://' . $_SERVER['HTTP_HOST'] . '/spellchecker.php?lang='
 // Get Nox Spell Server from http://orangoo.com/labs/?page_id=72 or
 // the After the Deadline package from https://www.afterthedeadline.com.
 // Leave empty to use the public API of service.afterthedeadline.com
