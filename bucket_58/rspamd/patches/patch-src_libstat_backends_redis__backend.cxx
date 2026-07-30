Avoid macro definition collision on sunos.

--- src/libstat/backends/redis_backend.cxx.orig	2026-07-21 17:53:03 UTC
+++ src/libstat/backends/redis_backend.cxx
@@ -62,8 +62,8 @@ struct redis_stat_ctx {
 
 	ucl_object_t *cur_stat = nullptr;
 
-	explicit redis_stat_ctx(lua_State *_L)
-		: L(_L)
+	explicit redis_stat_ctx(lua_State *xxx_L)
+		: L(xxx_L)
 	{
 	}
 
