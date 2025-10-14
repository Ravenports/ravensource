--- src/TableBase.cpp.orig	2014-06-21 23:24:07.000000000 +0200
+++ src/TableBase.cpp	2025-10-14 21:13:53.528394000 +0200
@@ -41,7 +41,7 @@
 	else if ( row >= rows() ) row = rows() - 1;
 	if ( table_h <= tih ) return;		// don't scroll if table smaller than window
 	double newtop = row_scroll_position(row);
-	if ( newtop > vscrollbar->maximum() ) 
+	if ( newtop > vscrollbar->maximum() )
 		{ newtop = vscrollbar->maximum(); }
 	vscrollbar->Fl_Slider::value(newtop);
 	table_scrolled();
@@ -57,7 +57,7 @@
 	else if ( col >= cols() ) col = cols() - 1;
 	if ( table_w <= tiw ) return;		// don't scroll if table smaller than window
 	double newleft = col_scroll_position(col);
-	if ( newleft > hscrollbar->maximum() ) 
+	if ( newleft > hscrollbar->maximum() )
 		{ newleft = hscrollbar->maximum(); }
 	hscrollbar->Fl_Slider::value(newleft);
 	table_scrolled();
@@ -71,7 +71,7 @@
 	int startrow = 0;
 	long scroll = 0;
 
-	// OPTIMIZATION: 
+	// OPTIMIZATION:
 	//	   Attempt to use precomputed row scroll position
 	//
 	if ( toprow_scrollpos != -1 && row >= toprow )
@@ -88,7 +88,7 @@
 	int startcol = 0;
 	long scroll = 0;
 
-	// OPTIMIZATION: 
+	// OPTIMIZATION:
 	//	   Attempt to use precomputed row scroll position
 	//
 	if ( leftcol_scrollpos != -1 && col >= leftcol )
@@ -176,7 +176,7 @@
 void TableBase::row_height(int row, int height)
 {
 	if ( row < 0 ) return;
-	if ( row < (int)_rowheights.size() && _rowheights[row] == height ) 
+	if ( row < (int)_rowheights.size() && _rowheights[row] == height )
 		{ return; }				// OPTIMIZATION: no change? avoid redraw
 	// Add row heights, even if none yet
 	int now_size = (int)_rowheights.size();
@@ -199,7 +199,7 @@
 void TableBase::col_width(int col, int width)
 {
 	if ( col < 0 ) return;
-	if ( col < (int)_colwidths.size() && _colwidths[col] == width ) 
+	if ( col < (int)_colwidths.size() && _colwidths[col] == width )
 		{ return; }				// OPTIMIZATION: no change? avoid redraw
 
 	// Add column widths, even if none yet
@@ -276,7 +276,7 @@
 
 		// TODO: Add other contexts..
 		default:
-			fprintf(stderr, "TableBase::get_bounds(): context %d unimplemented\n", 
+			fprintf(stderr, "TableBase::get_bounds(): context %d unimplemented\n",
 				(int)context);
 			return;
 	}
@@ -388,7 +388,7 @@
 }
 
 // Find X/Y/W/H for cell at R/C
-//	   If R or C are out of range, returns -1 
+//	   If R or C are out of range, returns -1
 //	   with X/Y/W/H set to zero.
 //
 int TableBase::find_cell(TableContext context, int R, int C, int &X, int &Y, int &W, int &H)
@@ -471,7 +471,7 @@
 	else if (lx < (x() + row_header_width()))
 	{
 		Fl::e_x = x() + row_header_width() + 1;
-		if (hscrollbar->visible()) 
+		if (hscrollbar->visible())
 			((Fl_Slider*)hscrollbar)->value(
 				hscrollbar->clamp(hscrollbar->value() - 30));
 		hscrollbar->do_callback();
@@ -481,7 +481,7 @@
 	if (ly > y() + h() - 20)
 	{
 		Fl::e_y = y() + h() - 20;
-		if (vscrollbar->visible()) 
+		if (vscrollbar->visible())
 			((Fl_Slider*)vscrollbar)->value(
 				vscrollbar->clamp(vscrollbar->value() + 30));
 		vscrollbar->do_callback();
@@ -503,7 +503,7 @@
 	Fl::e_y = ly;
 	Fl::check();
 	Fl::flush();
-	if (Fl::event_buttons() && _auto_drag) 
+	if (Fl::event_buttons() && _auto_drag)
 		{ Fl::add_timeout(0.05, _auto_drag_cb2, this); }
 }
 
@@ -535,13 +535,13 @@
 			hideh = (table_w <= tiw);
 
 		// Second pass: Check for interference
-		if ( !hideh & hidev ) { hidev = (( table_h - tih + SCROLLBAR_SIZE ) <= 0 ); } 
-		if ( !hidev & hideh ) { hideh = (( table_w - tiw + SCROLLBAR_SIZE ) <= 0 ); }
+		if ( (!hideh) & hidev ) { hidev = (( table_h - tih + SCROLLBAR_SIZE ) <= 0 ); }
+		if ( (!hidev) & hideh ) { hideh = (( table_w - tiw + SCROLLBAR_SIZE ) <= 0 ); }
 
 		// Determine scrollbar visibility, trim ti[xywh]/to[xywh]
-		if ( hidev ) { vscrollbar->hide(); } 
+		if ( hidev ) { vscrollbar->hide(); }
 		else { vscrollbar->show(); tiw -= SCROLLBAR_SIZE; tow -= SCROLLBAR_SIZE; }
-		if ( hideh ) { hscrollbar->hide(); } 
+		if ( hideh ) { hscrollbar->hide(); }
 		else { hscrollbar->show(); tih -= SCROLLBAR_SIZE; toh -= SCROLLBAR_SIZE; }
 	}
 
@@ -626,15 +626,15 @@
 		vscrollbar->precision(10);
 		vscrollbar->slider_size(vscrolltab);
 		vscrollbar->resize(wix+wiw-SCROLLBAR_SIZE, wiy,
-						   SCROLLBAR_SIZE, 
+						   SCROLLBAR_SIZE,
 						   wih - ((hscrollbar->visible())?SCROLLBAR_SIZE:0));
-		vscrollbar->Fl_Valuator::value(vscrollbar->clamp(vscrollbar->value())); 
+		vscrollbar->Fl_Valuator::value(vscrollbar->clamp(vscrollbar->value()));
 
 		hscrollbar->bounds(0, table_w-tiw);
 		hscrollbar->precision(10);
 		hscrollbar->slider_size(hscrolltab);
 		hscrollbar->resize(wix, wiy+wih-SCROLLBAR_SIZE,
-						   wiw - ((vscrollbar->visible())?SCROLLBAR_SIZE:0), 
+						   wiw - ((vscrollbar->visible())?SCROLLBAR_SIZE:0),
 						   SCROLLBAR_SIZE);
 		hscrollbar->Fl_Valuator::value(hscrollbar->clamp(hscrollbar->value()));
 	}
@@ -778,7 +778,7 @@
 		if (Fl::event_inside(hscrollbar) || Fl::event_inside(vscrollbar)) return 1;
 		if (Fl::focus() != this && contains(Fl::focus())) return 1;
 	}
- 
+
 	// Which row/column are we over?
 	int R, C;							// row/column being worked on
 	ResizeFlag resizeflag;				// which resizing area are we over? (0=none)
@@ -796,13 +796,13 @@
 					ret = 1;
 				}
 				damage_zone(current_row, current_col, select_row, select_col, R, C);
-				if (context == CONTEXT_CELL) 
+				if (context == CONTEXT_CELL)
 				{
 					current_row = select_row = R;
 					current_col = select_col = C;
 					_selecting = CONTEXT_CELL;
 				}
-				else 
+				else
 				{
 					current_row = select_row = -1;
 					current_col = select_col = -1;
@@ -822,13 +822,13 @@
 
 				case CONTEXT_NONE:
 					// FL_PUSH on table corner?
-					if ( Fl::event_button() == 1 && 
-						 Fl::event_x() < x() + row_header_width()) 
+					if ( Fl::event_button() == 1 &&
+						 Fl::event_x() < x() + row_header_width())
 					{
 						current_col = 0;
 						select_col = cols() - 1;
 						current_row = 0;
-						select_row = rows() - 1;								
+						select_row = rows() - 1;
 						damage_zone(current_row, current_col, select_row, select_col);
 						ret = 1;
 					}
@@ -843,12 +843,12 @@
 						{
 							// Start resize if left click on column border.
 							//	  "ret=1" ensures we get drag events from now on.
-							//	  (C-1) is used if mouse is over the left hand side 
+							//	  (C-1) is used if mouse is over the left hand side
 							//	  of cell, so we resize the next column on the left.
 							//
-							_resizing_col = ( resizeflag & RESIZE_COL_LEFT ) ? C-1 : C; 
+							_resizing_col = ( resizeflag & RESIZE_COL_LEFT ) ? C-1 : C;
 							_resizing_row = -1;
-							_dragging_x = Fl::event_x(); 
+							_dragging_x = Fl::event_x();
 							ret = 1;
 						}
 						else
@@ -858,7 +858,7 @@
 							current_row = 0;
 							select_row = rows() - 1;
 							_selecting = CONTEXT_COL_HEADER;
-							damage_zone(current_row, current_col, 
+							damage_zone(current_row, current_col,
 										select_row, select_col);
 							ret = 1;
 						}
@@ -877,11 +877,11 @@
 							//	  (R-1) is used if mouse is over the top of the cell,
 							//	  so that we resize the row above.
 							//
-							_resizing_row = ( resizeflag & RESIZE_ROW_ABOVE ) ? R-1 : R; 
+							_resizing_row = ( resizeflag & RESIZE_ROW_ABOVE ) ? R-1 : R;
 							_resizing_col = -1;
-							_dragging_y = Fl::event_y(); 
+							_dragging_y = Fl::event_y();
 							ret = 1;
-						} 
+						}
 						else
 						{
 							// Not resizing? Select the row
@@ -889,7 +889,7 @@
 							current_col = 0;
 							select_col = cols() - 1;
 							_selecting = CONTEXT_ROW_HEADER;
-							damage_zone(current_row, current_col, 
+							damage_zone(current_row, current_col,
 										select_row, select_col);
 							ret = 1;
 						}
@@ -949,23 +949,23 @@
 				if ( Fl_Widget::callback() && when() & FL_WHEN_CHANGED )
 					{ do_callback(CONTEXT_RC_RESIZE, R, C); }
 			} else {
-				if (Fl::event_button() == 1 && _selecting == CONTEXT_CELL 
-						&& context == CONTEXT_CELL) 
+				if (Fl::event_button() == 1 && _selecting == CONTEXT_CELL
+						&& context == CONTEXT_CELL)
 				{
 					if (select_row != R || select_col != C)
 						damage_zone(current_row, current_col, select_row, select_col, R, C);
 					select_row = R;
 					select_col = C;
 					ret = 1;
-				} else if (Fl::event_button() == 1 && _selecting == CONTEXT_ROW_HEADER 
-						&& context & (CONTEXT_ROW_HEADER|CONTEXT_COL_HEADER|CONTEXT_CELL)) 
+				} else if (Fl::event_button() == 1 && _selecting == CONTEXT_ROW_HEADER
+						&& context & (CONTEXT_ROW_HEADER|CONTEXT_COL_HEADER|CONTEXT_CELL))
 				{
 				   if (select_row != R)
 						damage_zone(current_row, current_col, select_row, select_col, R, C);
 					select_row = R;
 					ret = 1;
-				} else if (Fl::event_button() == 1 && _selecting == CONTEXT_COL_HEADER 
-						&& context & (CONTEXT_ROW_HEADER|CONTEXT_COL_HEADER|CONTEXT_CELL)) 
+				} else if (Fl::event_button() == 1 && _selecting == CONTEXT_COL_HEADER
+						&& context & (CONTEXT_ROW_HEADER|CONTEXT_COL_HEADER|CONTEXT_CELL))
 				{
 					if (select_col != C)
 						damage_zone(current_row, current_col, select_row, select_col, R, C);
@@ -974,9 +974,9 @@
 				}
 			}
 			// Enable autodrag if not resizing, and mouse has moved off table edge
-			if ( _resizing_row < 0 && _resizing_col < 0 && _auto_drag == 0 && 
+			if ( _resizing_row < 0 && _resizing_col < 0 && _auto_drag == 0 &&
 				( Fl::event_x() > x() + w() - 20 ||
-				  Fl::event_x() < x() + row_header_width() || 
+				  Fl::event_x() < x() + row_header_width() ||
 				  Fl::event_y() > y() + h() - 20 ||
 				  Fl::event_y() < y() + col_header_height()
 				) )
@@ -1037,7 +1037,7 @@
 		case FL_LEAVE:			// We want to track the mouse if resizing is allowed.
 			if ( resizeflag )
 				{ ret = 1; }
-			if ( event == FL_LEAVE ) 
+			if ( event == FL_LEAVE )
 			{
 				_stop_auto_drag();
 				change_cursor(FL_CURSOR_DEFAULT);
@@ -1080,10 +1080,10 @@
 				do_callback(CONTEXT_TABLE, -1, -1);
 				take_focus();
 			}
-			//if (!ret && Fl_Widget::callback() && when() & FL_WHEN_NOT_CHANGED  ) { 
-			if ( Fl_Widget::callback() && 
+			//if (!ret && Fl_Widget::callback() && when() & FL_WHEN_NOT_CHANGED  ) {
+			if ( Fl_Widget::callback() &&
 				 ( ( !ret && when() & FL_WHEN_NOT_CHANGED ) || ( is_row!= select_row || is_col!= select_col ) ) ) {
-				do_callback(CONTEXT_CELL, select_row, select_col); 
+				do_callback(CONTEXT_CELL, select_row, select_col);
 				//damage_zone(current_row, current_col, select_row, select_col);
 				ret = 1;
 			}
@@ -1120,7 +1120,7 @@
 int TableBase::is_selected(int r, int c)
 {
 	int s_left, s_right, s_top, s_bottom;
- 
+
 	if (select_col > current_col) {
 		s_left = current_col;
 		s_right = select_col;
@@ -1173,7 +1173,7 @@
 //	  Then tell the group to draw over us.
 //
 void TableBase::draw()
-{	
+{
 	draw_cell(CONTEXT_STARTPAGE, 0, 0,			// let user's drawing routine
 			  tix, tiy, tiw, tih);				// prep new page
 
@@ -1210,7 +1210,7 @@
 			fl_push_clip(tix, tiy, tiw, tih);
 			for ( int c = _redraw_leftcol; c <= _redraw_rightcol; c++ )
 				for ( int r = _redraw_toprow; r <= _redraw_botrow; r++ )
-				{ 
+				{
 					_redraw_cell(CONTEXT_CELL, r, c);
 				}
 			fl_pop_clip();
@@ -1256,7 +1256,7 @@
 				{
 					for ( int c = leftcol; c <= rightcol; c++ )
 					{
-						_redraw_cell(CONTEXT_CELL, r, c); 
+						_redraw_cell(CONTEXT_CELL, r, c);
 					}
 				}
 			}
@@ -1270,10 +1270,10 @@
 			if ( table->box() )
 			{
 				if ( col_header() )
-					{ fl_rectf(tox, wiy, Fl::box_dx(table->box()), 
+					{ fl_rectf(tox, wiy, Fl::box_dx(table->box()),
 											 col_header_height(), color()); }
 				if ( row_header() )
-					{ fl_rectf(wix, toy, row_header_width(), 
+					{ fl_rectf(wix, toy, row_header_width(),
 										 Fl::box_dx(table->box()), color()); }
 			}
 
@@ -1285,10 +1285,10 @@
 				// Col header? fill that too
 				if ( col_header() )
 				{
-					fl_rectf(tix + table_w, 
-							 wiy, 
+					fl_rectf(tix + table_w,
+							 wiy,
 							 // get that corner just right..
-							 (tiw - table_w + Fl::box_dw(table->box()) - 
+							 (tiw - table_w + Fl::box_dw(table->box()) -
 											  Fl::box_dx(table->box())),
 							 col_header_height(),
 							 color());
@@ -1303,12 +1303,12 @@
 				if ( row_header() )
 				{
 					// NOTE:
-					//	   Careful with that lower corner; don't use tih; when eg. 
-					//	   table->box(FL_THIN_UPFRAME) and hscrollbar hidden, 
+					//	   Careful with that lower corner; don't use tih; when eg.
+					//	   table->box(FL_THIN_UPFRAME) and hscrollbar hidden,
 					//	   leaves a row of dead pixels.
 					//
-					fl_rectf(wix, tiy + table_h, row_header_width(), 
-							 (wiy+wih) - (tiy+table_h) - 
+					fl_rectf(wix, tiy + table_h, row_header_width(),
+							 (wiy+wih) - (tiy+table_h) -
 							 ( hscrollbar->visible() ? SCROLLBAR_SIZE : 0),
 							 color());
 				}
@@ -1318,7 +1318,7 @@
 		// Both scrollbars? Draw little box in lower right
 		if ( vscrollbar->visible() && hscrollbar->visible() )
 		{
-			fl_rectf(vscrollbar->x(), hscrollbar->y(), 
+			fl_rectf(vscrollbar->x(), hscrollbar->y(),
 					 vscrollbar->w(), hscrollbar->h(), color());
 		}
 
