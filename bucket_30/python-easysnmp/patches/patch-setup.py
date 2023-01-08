--- setup.py.orig	2022-07-16 15:53:20 UTC
+++ setup.py
@@ -55,6 +55,9 @@ else:
         elif flag[:2] == '-f':  # -flat_namespace
             link_args.append(flag)
             pass_next = False
+        elif flag[:10] == '-Wl,-rpath':
+            link_args.append(flag)
+            pass_next = False
 
     # link_args += [flag for flag in s_split(netsnmp_libs) if flag[:2] == '-f']
     libs = [flag[2:] for flag in s_split(netsnmp_libs) if flag[:2] == '-l']
