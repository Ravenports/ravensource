_USES_build+= 555:assemble_pic
_USES_stage+= 555:install_pic

FILES_DOCS=\
	ANNOUNCE \
	NEWS \
	README \
	doc/hackguide.doc \
	doc/ncurses-intro.doc \
	doc/html/index.html \
	doc/html/announce.html \
	doc/html/hackguide.html \
	doc/html/ncurses-intro.html \

TINFO_OBJS=\
	obj_s/access.o \
	obj_s/add_tries.o \
	obj_s/alloc_ttype.o \
	obj_s/codes.o \
	obj_s/comp_captab.o \
	obj_s/comp_error.o \
	obj_s/comp_hash.o \
	obj_s/comp_userdefs.o \
	obj_s/db_iterator.o \
	obj_s/doalloc.o \
	obj_s/entries.o \
	obj_s/fallback.o \
	obj_s/free_ttype.o \
	obj_s/getenv_num.o \
	obj_s/home_terminfo.o \
	obj_s/init_keytry.o \
	obj_s/lib_acs.o \
	obj_s/lib_baudrate.o \
	obj_s/lib_cur_term.o \
	obj_s/lib_data.o \
	obj_s/lib_has_cap.o \
	obj_s/lib_kernel.o \
	obj_s/lib_keyname.o \
	obj_s/lib_longname.o \
	obj_s/lib_napms.o \
	obj_s/lib_options.o \
	obj_s/lib_raw.o \
	obj_s/lib_setup.o \
	obj_s/lib_termcap.o \
	obj_s/lib_termname.o \
	obj_s/lib_tgoto.o \
	obj_s/lib_ti.o \
	obj_s/lib_tparm.o \
	obj_s/lib_tputs.o \
	obj_s/lib_trace.o \
	obj_s/lib_ttyflags.o \
	obj_s/lib_twait.o \
	obj_s/name_match.o \
	obj_s/names.o \
	obj_s/obsolete.o \
	obj_s/read_entry.o \
	obj_s/read_termcap.o \
	obj_s/strings.o \
	obj_s/tries.o \
	obj_s/trim_sgr0.o \
	obj_s/unctrl.o \
	obj_s/visbuf.o \
	obj_s/alloc_entry.o \
	obj_s/captoinfo.o \
	obj_s/comp_expand.o \
	obj_s/comp_parse.o \
	obj_s/comp_scan.o \
	obj_s/parse_entry.o \
	obj_s/write_entry.o \
	obj_s/define_key.o \
	obj_s/hashed_db.o \
	obj_s/key_defined.o \
	obj_s/keybound.o \
	obj_s/keyok.o \
	obj_s/version.o

NCURSES_OBJS=\
	obj_s/hardscroll.o \
	obj_s/hashmap.o \
	obj_s/lib_addch.o \
	obj_s/lib_addstr.o \
	obj_s/lib_beep.o \
	obj_s/lib_bkgd.o \
	obj_s/lib_box.o \
	obj_s/lib_chgat.o \
	obj_s/lib_clear.o \
	obj_s/lib_clearok.o \
	obj_s/lib_clrbot.o \
	obj_s/lib_clreol.o \
	obj_s/lib_color.o \
	obj_s/lib_colorset.o \
	obj_s/lib_delch.o \
	obj_s/lib_delwin.o \
	obj_s/lib_echo.o \
	obj_s/lib_endwin.o \
	obj_s/lib_erase.o \
	obj_s/lib_flash.o \
	obj_s/lib_gen.o \
	obj_s/lib_getch.o \
	obj_s/lib_getstr.o \
	obj_s/lib_hline.o \
	obj_s/lib_immedok.o \
	obj_s/lib_inchstr.o \
	obj_s/lib_initscr.o \
	obj_s/lib_insch.o \
	obj_s/lib_insdel.o \
	obj_s/lib_insnstr.o \
	obj_s/lib_instr.o \
	obj_s/lib_isendwin.o \
	obj_s/lib_leaveok.o \
	obj_s/lib_mouse.o \
	obj_s/lib_move.o \
	obj_s/lib_mvcur.o \
	obj_s/lib_mvwin.o \
	obj_s/lib_newterm.o \
	obj_s/lib_newwin.o \
	obj_s/lib_nl.o \
	obj_s/lib_overlay.o \
	obj_s/lib_pad.o \
	obj_s/lib_printw.o \
	obj_s/lib_redrawln.o \
	obj_s/lib_refresh.o \
	obj_s/lib_restart.o \
	obj_s/lib_scanw.o \
	obj_s/lib_screen.o \
	obj_s/lib_scroll.o \
	obj_s/lib_scrollok.o \
	obj_s/lib_scrreg.o \
	obj_s/lib_set_term.o \
	obj_s/lib_slk.o \
	obj_s/lib_slkatr_set.o \
	obj_s/lib_slkatrof.o \
	obj_s/lib_slkatron.o \
	obj_s/lib_slkatrset.o \
	obj_s/lib_slkattr.o \
	obj_s/lib_slkclear.o \
	obj_s/lib_slkcolor.o \
	obj_s/lib_slkinit.o \
	obj_s/lib_slklab.o \
	obj_s/lib_slkrefr.o \
	obj_s/lib_slkset.o \
	obj_s/lib_slktouch.o \
	obj_s/lib_touch.o \
	obj_s/lib_tstp.o \
	obj_s/lib_ungetch.o \
	obj_s/lib_vidattr.o \
	obj_s/lib_vline.o \
	obj_s/lib_wattroff.o \
	obj_s/lib_wattron.o \
	obj_s/lib_winch.o \
	obj_s/lib_window.o \
	obj_s/nc_panel.o \
	obj_s/safe_sprintf.o \
	obj_s/tty_update.o \
	obj_s/varargs.o \
	obj_s/vsscanf.o \
	obj_s/lib_freeall.o \
	obj_s/charable.o \
	obj_s/lib_add_wch.o \
	obj_s/lib_box_set.o \
	obj_s/lib_cchar.o \
	obj_s/lib_erasewchar.o \
	obj_s/lib_get_wch.o \
	obj_s/lib_get_wstr.o \
	obj_s/lib_hline_set.o \
	obj_s/lib_in_wch.o \
	obj_s/lib_in_wchnstr.o \
	obj_s/lib_ins_wch.o \
	obj_s/lib_inwstr.o \
	obj_s/lib_key_name.o \
	obj_s/lib_pecho_wchar.o \
	obj_s/lib_slk_wset.o \
	obj_s/lib_unget_wch.o \
	obj_s/lib_vid_attr.o \
	obj_s/lib_vline_set.o \
	obj_s/lib_wacs.o \
	obj_s/lib_wunctrl.o \
	obj_s/expanded.o \
	obj_s/legacy_coding.o \
	obj_s/lib_dft_fgbg.o \
	obj_s/lib_print.o \
	obj_s/new_pair.o \
	obj_s/resizeterm.o \
	obj_s/use_screen.o \
	obj_s/use_window.o \
	obj_s/wresize.o

assemble_pic:
	(cd ${WRKSRC} &&\
	 ${AR} -cq libtinfo_pic.a ${TINFO_OBJS} &&\
	 ranlib libtinfo_pic.a)
	(cd ${WRKSRC} &&\
	 ${AR} -cq libncurses_pic.a ${NCURSES_OBJS} &&\
	 ranlib libncurses_pic.a)

install_pic:
	${INSTALL_DATA} ${WRKSRC}/libtinfo_pic.a ${WRKSRC}/libncurses_pic.a \
		${STAGEDIR}${PREFIX}/lib/
