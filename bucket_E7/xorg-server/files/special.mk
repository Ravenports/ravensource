sharefonts=	${LOCALBASE}/share/fonts
fontpathd=	${PREFIX}/etc/X11/fontpath.d

fontlist=	${sharefonts}/misc \
		${sharefonts}/TTF \
		${sharefonts}/OTF \
		${sharefonts}/Type1 \
		${sharefonts}/100dpi \
		${sharefonts}/75dpi \
		catalogue:${fontpathd}
