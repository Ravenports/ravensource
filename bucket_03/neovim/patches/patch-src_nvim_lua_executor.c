--- src/nvim/lua/executor.c.orig	2021-09-26 22:15:30 UTC
+++ src/nvim/lua/executor.c
@@ -454,7 +454,11 @@ static int nlua_state_init(lua_State *co
   lua_pushcfunction(lstate, &nlua_regex);
   lua_setfield(lstate, -2, "regex");
   luaL_newmetatable(lstate, "nvim_regex");
+#if LUA_VERSION_NUM >= 502
+  luaL_setfuncs(lstate, regex_meta, 0);    /* 5.2 */
+#else
   luaL_register(lstate, NULL, regex_meta);
+#endif
   lua_pushvalue(lstate, -1);  // [meta, meta]
   lua_setfield(lstate, -2, "__index");  // [meta]
   lua_pop(lstate, 1);  // don't use metatable now
