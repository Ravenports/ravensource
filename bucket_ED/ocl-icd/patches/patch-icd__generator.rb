--- icd_generator.rb.orig	2025-04-02 20:16:06 UTC
+++ icd_generator.rb
@@ -556,7 +556,7 @@ EOF
   end
 
   def self.generate_ocl_icd_loader_map
-    ocl_icd_loader_map = "/**\n#{$license}\n*/\n\n"
+    ocl_icd_loader_map = "\n"
     prev_version=""
     $versions_entries.keys.sort.each { |version|
       ocl_icd_loader_map += "OPENCL_#{version.sub('_','.')} {\n";
