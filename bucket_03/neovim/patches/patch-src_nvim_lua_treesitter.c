--- src/nvim/lua/treesitter.c.orig	2021-09-26 22:15:30 UTC
+++ src/nvim/lua/treesitter.c
@@ -106,7 +106,11 @@ static PMap(cstr_t) *langs;
 static void build_meta(lua_State *L, const char *tname, const luaL_Reg *meta)
 {
   if (luaL_newmetatable(L, tname)) {  // [meta]
+#if LUA_VERSION_NUM >= 502
+    luaL_setfuncs(L, meta, 0);    /* 5.2 */
+#else
     luaL_register(L, NULL, meta);
+#endif
 
     lua_pushvalue(L, -1);  // [meta, meta]
     lua_setfield(L, -2, "__index");  // [meta]
@@ -449,7 +453,11 @@ static void range_from_lua(lua_State *L,
 
   if (lua_istable(L, -1)) {
     // should be a table of 6 elements
+#if LUA_VERSION_NUM >= 502
+    if (lua_rawlen(L, -1) != 6) {
+#else
     if (lua_objlen(L, -1) != 6) {
+#endif
       goto error;
     }
 
@@ -526,7 +534,11 @@ static int parser_set_ranges(lua_State *
         "argument for parser:set_included_ranges() should be a table.");
   }
 
+#if LUA_VERSION_NUM >= 502
+  size_t tbl_len = lua_rawlen(L, 2);
+#else
   size_t tbl_len = lua_objlen(L, 2);
+#endif
   TSRange *ranges = xmalloc(sizeof(TSRange) * tbl_len);
 
 
@@ -587,7 +599,11 @@ void push_tree(lua_State *L, TSTree *tre
   lua_createtable(L, 1, 0);  // [udata, reftable]
   lua_pushvalue(L, -2);  // [udata, reftable, udata]
   lua_rawseti(L, -2, 1);  // [udata, reftable]
+#if LUA_VERSION_NUM >= 502
+  lua_setuservalue(L, -2);
+#else
   lua_setfenv(L, -2);  // [udata]
+#endif
 }
 
 static TSTree **tree_check(lua_State *L, uint16_t index)
@@ -642,8 +658,13 @@ static void push_node(lua_State *L, TSNo
   *ud = node;
   lua_getfield(L, LUA_REGISTRYINDEX, TS_META_NODE);  // [udata, meta]
   lua_setmetatable(L, -2);  // [udata]
+#if LUA_VERSION_NUM >= 502
+  lua_getuservalue(L, uindex);
+  lua_setuservalue(L, -2);
+#else
   lua_getfenv(L, uindex);  // [udata, reftable]
   lua_setfenv(L, -2);  // [udata]
+#endif
 }
 
 static bool node_check(lua_State *L, int index, TSNode *res)
