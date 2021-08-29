--- plugins/sc68/libsc68/dial68/dial_conf.c.orig	2020-06-28 13:41:28 UTC
+++ plugins/sc68/libsc68/dial68/dial_conf.c
@@ -70,7 +70,7 @@ static inline void del_dial(dial_t * dia
  * @retval  1  on unkown/unset key
  * @retval -1  on error
  */
-static int getopt(const char * key, int op, sc68_dialval_t * val)
+static int dead_getopt(const char * key, int op, sc68_dialval_t * val)
 {
   option68_t * opt = option68_get(key, opt68_ALWAYS);
   const int org = opt68_CFG;
@@ -260,7 +260,7 @@ static int conf(void * data, const char
     if (op == SC68_DIAL_SETI && keyis("sampling-rate")
         && val->i > 0 && val->i < sprmax)
       val->i = i_spr[val->i];
-    res = getopt(key, op, val);
+    res = dead_getopt(key, op, val);
   }
 
 exit:
