--- doc/run-quiet.py.orig	2026-08-06 06:05:15 UTC
+++ doc/run-quiet.py
@@ -31,6 +31,8 @@ if len(sys.argv) < 2:
   sys.exit('Usage: {} PROGRAM [ARGS..]'.format(sys.argv[0]))
 
 command = sys.argv[1:]
+env = os.environ.copy()
+env['LC_ALL'] = 'C'
 
 with open(os.devnull, 'w') as out:
-  sys.exit(subprocess.run(command, stdout=out).returncode)
+  sys.exit(subprocess.run(command, stdout=out, env=env).returncode)
