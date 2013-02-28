# $NetBSD: Makefile.inc,v 1.5 2012/06/01 20:28:02 wiz Exp $

WARNS=		2

SRCDIR:=	${.PARSEDIR}/dist

.PATH: ${SRCDIR}

CPPFLAGS+=	\
		-DHAVE_GMTIME_R=1 \
		-DHAVE_INTTYPES_H=1 \
		-DHAVE_LOCALTIME_R=1 \
		-DHAVE_READLINE=1 \
		-DHAVE_STDINT_H=1 \
		-DHAVE_STRERROR_R=1 \
		-DHAVE_USLEEP=1 \
		-DSQLITE_ENABLE_COLUMN_METADATA \
		-DSQLITE_ENABLE_FTS3_PARENTHESIS \
		-DSQLITE_ENABLE_FTS4 \
		-DSQLITE_ENABLE_LOAD_EXTENSION \
		-DSQLITE_ENABLE_UNLOCK_NOTIFY \
		-DSQLITE_HAVE_ISNAN

.if defined(__MINIX)
CPPFLAGS+=	\
		-DSQLITE_THREADSAFE=0 \
		-DSQLITE_OMIT_WAL
.endif # defined(__MINIX)

CWARNFLAGS+=	-Wno-shadow -Wno-unused