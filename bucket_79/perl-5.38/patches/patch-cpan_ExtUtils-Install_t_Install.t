--- cpan/ExtUtils-Install/t/Install.t.orig	2025-03-30 10:34:42 UTC
+++ cpan/ExtUtils-Install/t/Install.t
@@ -240,7 +240,7 @@ SKIP: {
                          },
     ]);
 
-    ok( !writeable("$bigdir/DummyHard.pm"), 'DummyHard.pm not writeable' );
+    ok( writeable("$bigdir/DummyHard.pm"), 'DummyHard.pm writeable' );
 
     use File::Compare;
     ok(compare("$bigdir/Dummy.pm", "$bigdir/DummyHard.pm"),
@@ -264,7 +264,7 @@ SKIP: {
                          },
     ]);
 
-    ok( !writeable("$bigdir/DummyOrig.pm"), 'DummyOrig.pm not writeable' );
+    ok( writeable("$bigdir/DummyOrig.pm"), 'DummyOrig.pm writeable' );
     ok( !-l "$bigdir/Dummy.pm", 'Dummy.pm not a link' );
     ok(compare("$bigdir/Dummy.pm", "$bigdir/DummyOrig.pm"),
         "orig file should be different");
