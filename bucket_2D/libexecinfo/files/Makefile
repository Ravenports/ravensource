# libexecinfo has libelf inbuilt from elftoolchain project

.SUFFIXES:	.o .c
.SUFFIXES:	.So .c
.SUFFIXES:	.m4 .c

.c.o:
	${CC} ${_${.IMPSRC:T}_FLAGS} ${PICFLAG} -DPIC ${CFLAGS} -c ${.IMPSRC}

.c.So:
	${CC} ${_${.IMPSRC:T}_FLAGS} ${PICFLAG} -DPIC ${CFLAGS} -c ${.IMPSRC} -o ${.TARGET}

.m4.c:
	m4 -D SRCDIR=${SRCDIR} ${M4FLAGS} ${.IMPSRC} > ${.TARGET}

LIB=		execinfo
LIBMAJOR=	2
LIB_STATIC=	lib${LIB}.a
LIB_SHARED=	lib${LIB}.so.${LIBMAJOR}
LIB_LINK=	lib${LIB}.so
PICFLAG=	-fpic
SRCDIR=		${TOOLCHAINDIR}/libelf
COMMON=		${TOOLCHAINDIR}/common
CFLAGS+=	-I. -I${SRCDIR} -I${COMMON}

.PATH:		${SRCDIR}

all: ${LIB_STATIC} ${LIB_SHARED}

.if ${OPSYS} == Linux || ${OPSYS} == SunOS
TSORT=		tsort 2>/dev/null
.else
TSORT=		tsort -q
.endif

# verbatim from Elftoolchain sourcefile
SRCS=	elf.c							\
	elf_begin.c						\
	elf_cntl.c						\
	elf_end.c elf_errmsg.c elf_errno.c			\
	elf_data.c						\
	elf_fill.c						\
	elf_flag.c						\
	elf_getarhdr.c						\
	elf_getarsym.c						\
	elf_getbase.c						\
	elf_getident.c						\
	elf_hash.c						\
	elf_kind.c						\
	elf_memory.c						\
	elf_next.c						\
	elf_open.c						\
	elf_rand.c						\
	elf_rawfile.c						\
	elf_phnum.c						\
	elf_shnum.c						\
	elf_shstrndx.c						\
	elf_scn.c						\
	elf_strptr.c						\
	elf_update.c						\
	elf_version.c						\
	gelf_cap.c						\
	gelf_checksum.c						\
	gelf_dyn.c						\
	gelf_ehdr.c						\
	gelf_getclass.c						\
	gelf_fsize.c						\
	gelf_move.c						\
	gelf_phdr.c						\
	gelf_rel.c						\
	gelf_rela.c						\
	gelf_shdr.c						\
	gelf_sym.c						\
	gelf_syminfo.c						\
	gelf_symshndx.c						\
	gelf_xlate.c						\
	libelf_align.c						\
	libelf_allocate.c					\
	libelf_ar.c						\
	libelf_ar_util.c					\
	libelf_checksum.c					\
	libelf_data.c						\
	libelf_ehdr.c						\
	libelf_extended.c					\
	libelf_memory.c						\
	libelf_open.c						\
	libelf_phdr.c						\
	libelf_shdr.c						\
	libelf_xlate.c						\
	${GENSRCS}

GENSRCS=	libelf_fsize.c libelf_msize.c libelf_convert.c

libelf_convert.c:	elf_types.m4 libelf_convert.m4
libelf_fsize.c:		elf_types.m4 libelf_fsize.m4
libelf_msize.c:		elf_types.m4 libelf_msize.m4

.if ${OPSYS} == Linux
${SRCS}: native-elf-format.h
.endif

.if "${OPSYS}" == "SunOS"
CFLAGS+=	-I${PREFIX}/include/bsd
SRCS+=		dprintf.c
.endif

# libexec sources
PREFIX?=	/usr/local
SRCS+=		backtrace.c symtab.c unwind.c
OBJS=		${SRCS:.c=.o}
SOBJS=		${SRCS:.c=.So}

${LIB_STATIC}: ${OBJS}
	@${ECHO} building static ${LIB} library
	${AR} cq ${.TARGET} `lorder ${OBJS} | ${TSORT}`
	ranlib ${.TARGET}

${LIB_SHARED}: ${SOBJS}
	@${ECHO} building shared ${LIB} library
	${CC_LINK} ${LDFLAGS} -shared \
	    -o ${.TARGET} -Wl,-soname,${.TARGET} \
	    `lorder ${SOBJS} | ${TSORT}`

native-elf-format.h: ${COMMON}/native-elf-format
	/bin/sh ${.ALLSRC} > ${.TARGET}

install:
	mkdir -p ${DESTDIR}${PREFIX}/lib ${DESTDIR}${PREFIX}/share/man/man3
	mkdir -p ${DESTDIR}${PREFIX}/include
	${BSD_INSTALL_LIB} ${LIB_SHARED} ${DESTDIR}${PREFIX}/lib
	${BSD_INSTALL_DATA} ${LIB_STATIC} ${DESTDIR}${PREFIX}/lib
	ln -s ${LIB_SHARED} ${DESTDIR}${PREFIX}/lib/${LIB_LINK}
	${BSD_INSTALL_MAN} backtrace.3 ${DESTDIR}${PREFIX}/share/man/man3/
	${BSD_INSTALL_DATA} execinfo.h ${DESTDIR}${PREFIX}/include/
