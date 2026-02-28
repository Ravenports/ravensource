--- ../ngx_dynamic_upstream-2.3.3/src/ngx_http_dynamic_upstream_module.cpp.orig	2022-10-28 12:10:17 UTC
+++ ../ngx_dynamic_upstream-2.3.3/src/ngx_http_dynamic_upstream_module.cpp
@@ -276,7 +276,7 @@ static ngx_str_t
 get_str(ngx_http_request_t *r, const char *arg,
     ngx_dynamic_upstream_op_t *op = NULL, ngx_int_t flag = 0)
 {
-    ngx_str_t                   name = { 0, (u_char *) alloca(128) }, val;
+    ngx_str_t                   name = { 0, (u_char *) __builtin_alloca(128) }, val;
     ngx_http_variable_value_t  *var;
 
     name.len = ngx_snprintf(name.data, 128, "arg_%s", arg) - name.data;
