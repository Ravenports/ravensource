--- icd_generator.rb.orig	2020-12-11 19:32:45 UTC
+++ icd_generator.rb
@@ -531,7 +531,7 @@ EOF
   end
 
   def self.generate_ocl_icd_loader_map
-    ocl_icd_loader_map = "/**\n#{$license}\n*/\n\n"
+    ocl_icd_loader_map = "\n"
     prev_version=""
     $versions_entries.keys.sort.each { |version|
       ocl_icd_loader_map += "OPENCL_#{version.sub('_','.')} {\n";
