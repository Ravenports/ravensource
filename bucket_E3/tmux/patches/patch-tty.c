--- tty.c.orig	2019-05-29 23:24:04 UTC
+++ tty.c
@@ -527,6 +527,12 @@ tty_putc(struct tty *tty, u_char ch)
 {
 	const char	*acs;
 
+	if ((tty->term->flags & TERM_EARLYWRAP) &&
+	    ch >= 0x20 && ch != 0x7f &&
+	    tty->cy == tty->sy - 1 &&
+	    tty->cx + 1 >= tty->sx)
+		return;
+
 	if (tty->cell.attr & GRID_ATTR_CHARSET) {
 		acs = tty_acs_get(tty, ch);
 		if (acs != NULL)
@@ -557,6 +563,11 @@ tty_putc(struct tty *tty, u_char ch)
 void
 tty_putn(struct tty *tty, const void *buf, size_t len, u_int width)
 {
+	if ((tty->term->flags & TERM_EARLYWRAP) &&
+	    tty->cy == tty->sy - 1 &&
+	    tty->cx + len >= tty->sx)
+		len = tty->sx - tty->cx - 1;
+
 	tty_add(tty, buf, len);
 	if (tty->cx + width > tty->sx) {
 		tty->cx = (tty->cx + width) - tty->sx;
@@ -1746,6 +1757,8 @@ void
 tty_cmd_cells(struct tty *tty, const struct tty_ctx *ctx)
 {
 	struct window_pane	*wp = ctx->wp;
+	u_int			 i;
+	struct grid_cell	 gc;
 
 	if (!tty_is_visible(tty, ctx, ctx->ocx, ctx->ocy, ctx->num, 1))
 		return;
@@ -1769,6 +1782,15 @@ tty_cmd_cells(struct tty *tty, const str
 	tty_margin_off(tty);
 	tty_cursor_pane_unless_wrap(tty, ctx, ctx->ocx, ctx->ocy);
 
+	if (tty->term->flags & TERM_EARLYWRAP) {
+		for (i = 0; i < ctx->num; i++) {
+			memcpy(&gc, ctx->cell, sizeof gc);
+			utf8_set(&gc.data, ((char *)ctx->ptr)[i]);
+			tty_cell(tty, &gc, ctx->wp);
+		}
+		return;
+	}
+
 	tty_attributes(tty, ctx->cell, ctx->wp);
 	tty_putn(tty, ctx->ptr, ctx->num, ctx->num);
 }
