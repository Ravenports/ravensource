--- json_container/tests/json_container_test.cc.orig	2020-04-21 23:04:52 UTC
+++ json_container/tests/json_container_test.cc
@@ -22,11 +22,13 @@ TEST_CASE("JsonContainer::JsonContainer
     std::string json_value {};
 
     SECTION("it should instantiate by passing any JSON value") {
+        json_value = "{}";
         SECTION("object") {
             json_value = JSON;
         }
 
         SECTION("array") {
+            json_value = "[]";
             SECTION("of numbers") {
                 json_value = "[1, 2, 3]";
             }
