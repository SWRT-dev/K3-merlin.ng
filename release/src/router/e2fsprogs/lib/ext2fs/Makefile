srcdir = .
top_srcdir = ../..

top_builddir = ../..
my_dir = lib/ext2fs
INSTALL = /usr/bin/install -c
DEPEND_CFLAGS = -I$(top_srcdir)/debugfs

# Beginning of file MCONFIG

all::

check::

SHELL = /bin/sh

COMPRESS_EXT = gz bz2 bz Z

prefix = /usr
root_prefix = /usr
exec_prefix = ${prefix}
root_bindir = ${exec_prefix}/bin
root_sbindir = ${exec_prefix}/sbin
root_libdir = ${exec_prefix}/lib
datarootdir = ${prefix}/share
bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libdir = ${exec_prefix}/lib
datadir= ${datarootdir}
localedir = $(datadir)/locale
root_sysconfdir= /etc
includedir = ${prefix}/include
mandir = ${datarootdir}/man
man1dir = $(mandir)/man1
man3dir = $(mandir)/man3
man5dir = $(mandir)/man5
man8dir = $(mandir)/man8
infodir = ${datarootdir}/info
datadir = ${datarootdir}
pkgconfigdir = $(libdir)/pkgconfig



 V =
 ifeq ($(strip $(V)),)
 #  E = @echo
 #  ES = echo
 #  Q = @
    E = @echo
    ES = echo
    Q = @
 else
    E = @\#
    ES = \#
    Q =
 endif

# E = @echo
# ES = echo
# Q = @

 CHECK=sparse
 CHECK_OPTS=-Wsparse-all -Wno-transparent-union -Wno-return-void -Wno-undef -Wno-non-pointer-null
 ifeq ("$(C)", "2")
   CHECK_CMD=$(CHECK) $(CHECK_OPTS) -Wbitwise -D__CHECK_ENDIAN__
 else
   ifeq ("$(C)", "1")
     CHECK_CMD=$(CHECK) $(CHECK_OPTS)
    else
     CHECK_CMD=@true
   endif
 endif

# CHECK_CMD=@true

CC = arm-brcm-linux-uclibcgnueabi-gcc
BUILD_CC = gcc
CFLAGS = -Os -ffunction-sections -fdata-sections -DLINUX26 -DCONFIG_BCMWL5 -DDEBUG_NOISY -DDEBUG_RCTEST -pipe -DBCMWPA2 -DBCMARM -fno-strict-aliasing -marm -DCONFIG_NVSIZE_128 -DLINUX_KERNEL_VERSION=132644  -DHAVE_CONFIG_H
CPPFLAGS = -I. -I$(top_builddir)/lib -I$(top_srcdir)/lib
ALL_CFLAGS = $(CPPFLAGS) $(CFLAGS)
LDFLAGS = -Wl,--gc-sections -lgcc_s
ALL_LDFLAGS = $(LDFLAGS) -Wl,-rpath-link,$(top_builddir)/lib
LDFLAGS_STATIC = $(LDFLAGS) 
BUILD_CFLAGS = 
BUILD_LDFLAGS = 
RDYNAMIC = -rdynamic
LINK_BUILD_FLAGS = 
LINK_INSTALL_FLAGS = -f
RM = /bin/rm
LN = /bin/ln
LN_S = ln -s
MV = /bin/mv
CP = /bin/cp
CHMOD = /bin/chmod
AR = arm-brcm-linux-uclibcgnueabi-ar
AWK = gawk
SED = /bin/sed
PERL = /usr/bin/perl
RANLIB = arm-brcm-linux-uclibcgnueabi-ranlib
STRIP = arm-brcm-linux-uclibcgnueabi-strip
LD = $(PURE) arm-brcm-linux-uclibcgnueabi-gcc
ARUPD = $(AR) r
ARGEN = $(AR) rc
LDCONFIG = /sbin/ldconfig
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL}
MKINSTALLDIRS = $(top_builddir)/config/mkinstalldirs

#
# Library definitions
#
LIB = $(top_builddir)/lib
LIBSS = $(LIB)/libss.so # 
LIBCOM_ERR = $(LIB)/libcom_err.so # 
LIBE2P = $(LIB)/libe2p.so
LIBEXT2FS = $(LIB)/libext2fs.so
LIBUUID = $(LIB)/libuuid.so 
LIBQUOTA = $(LIB)/libquota.a
LIBBLKID = $(LIB)/libblkid.so # $(LIBUUID)
LIBINTL = 
SYSLIBS = 
DEPLIBSS = $(LIB)/libss.so
DEPLIBCOM_ERR = $(LIB)/libcom_err.so
DEPLIBUUID = $(LIB)/libuuid.so
DEPLIBQUOTA = $(LIB)/libquota.a
DEPLIBBLKID = $(LIB)/libblkid.so # $(DEPLIBUUID)
TESTENV = LD_LIBRARY_PATH="$(LIB):$${LD_LIBRARY_PATH}" DYLD_LIBRARY_PATH="$(LIB):$${DYLD_LIBRARY_PATH}"

STATIC_LIBSS = $(LIB)/libss.a 
STATIC_LIBCOM_ERR = $(LIB)/libcom_err.a 
STATIC_LIBE2P = $(LIB)/libe2p.a
STATIC_LIBEXT2FS = $(LIB)/libext2fs.a
STATIC_LIBUUID = $(LIB)/libuuid.a 
STATIC_LIBQUOTA = $(LIB)/libquota.a
STATIC_LIBBLKID = $(LIB)/libblkid.a $(STATIC_LIBUUID)
DEPSTATIC_LIBSS = $(LIB)/libss.a
DEPSTATIC_LIBCOM_ERR = $(LIB)/libcom_err.a
DEPSTATIC_LIBUUID = $(LIB)/libuuid.a
DEPSTATIC_LIBQUOTA = $(LIB)/libquota.a
DEPSTATIC_LIBBLKID = $(LIB)/libblkid.a $(DEPSTATIC_LIBUUID)

PROFILED_LIBSS = $(LIB)/libss.a 
PROFILED_LIBCOM_ERR = $(LIB)/libcom_err.a 
PROFILED_LIBE2P = $(LIB)/libe2p.a
PROFILED_LIBEXT2FS = $(LIB)/libext2fs.a
PROFILED_LIBUUID = $(LIB)/libuuid.a 
PROFILED_LIBQUOTA = $(LIB)/libquota.a
PROFILED_LIBBLKID = $(LIB)/libblkid.a $(PROFILED_LIBUUID)
DEPPROFILED_LIBSS = $(LIB)/libss.a
DEPPROFILED_LIBCOM_ERR = $(LIB)/libcom_err.a
DEPPROFILED_LIBUUID = $(LIB)/libuuid.a
DEPPROFILED_LIBQUOTA = $(LIB)/libquota.a
DEPPROFILED_LIBBLKID = $(LIB)/libblkid.a $(DEPPROFILED_LIBUUID)

#
# A fast substitution command for fixing up man pages, shell scripts, etc.
#
SUBST_CONF=$(top_builddir)/util/subst.conf
SUBSTITUTE= $(top_builddir)/util/subst -f $(SUBST_CONF)
SUBSTITUTE_UPTIME= $(top_builddir)/util/subst -t -f $(SUBST_CONF)
DEP_SUBSTITUTE= $(top_builddir)/util/subst $(SUBST_CONF)

$(top_builddir)/util/subst:
	cd $(top_builddir)/util ; $(MAKE) subst

#
# Script for installing symlinks (for shared libraries)
#
$(top_builddir)/util/install-symlink: $(top_srcdir)/util/install-symlink.in \
			      $(top_builddir)/config.status
	cd $(top_builddir); CONFIG_FILES=util/install-symlink ./config.status
	chmod +x $(top_builddir)/util/install-symlink

$(top_builddir)/util/symlinks:
	cd $(top_builddir)/util ; $(MAKE) symlinks

INSTALL_SYMLINK = /bin/sh $(top_builddir)/util/install-symlink \
			 \
			--symlinks=$(top_builddir)/util/symlinks
DEP_INSTALL_SYMLINK = $(top_builddir)/util/install-symlink \
			$(top_builddir)/util/symlinks

#
# Warning flags
#
# Run make gcc-wall to do a build with warning messages.
#
#
WFLAGS=		-std=c99 -D_XOPEN_SOURCE=600 -D_GNU_SOURCE \
			-pedantic $(WFLAGS_EXTRA) \
			-Wall -W -Wwrite-strings -Wpointer-arith \
			-Wcast-qual -Wcast-align -Wno-variadic-macros \
			-Wstrict-prototypes -Wmissing-prototypes \
			-Wformat-security  -Wformat-nonliteral \
			-Wmissing-format-attribute -O2 -Wstrict-aliasing \
			-Wnested-externs -Winline -DNO_INLINE_FUNCS -Wshadow \
			-UENABLE_NLS

gcc-wall-new:
	(make CFLAGS="-Os -ffunction-sections -fdata-sections -DLINUX26 -DCONFIG_BCMWL5 -DDEBUG_NOISY -DDEBUG_RCTEST -pipe -DBCMWPA2 -DBCMARM -fno-strict-aliasing -marm -DCONFIG_NVSIZE_128 -DLINUX_KERNEL_VERSION=132644  $(WFLAGS)" > /dev/null) 2>&1 | sed -f $(top_srcdir)/util/gcc-wall-cleanup 

gcc-wall:
	make clean > /dev/null
	make gcc-wall-new

#
# Installation user and groups
#
BINGRP=		bin
BINOWN=		bin
BINMODE=	555
INCGRP=		bin
INCOWN=		bin
INCMODE=	444
LIBOWN=		bin
LIBGRP=		bin
LIBMODE=	444
MANGRP=		bin
MANOWN=		bin
MANMODE=	444

#
# Autoconf magic...
#

DEP_LIB_MAKEFILES = $(top_srcdir)/lib/Makefile.library \
	$(top_srcdir)/lib/Makefile.elf-lib  \
	$(top_srcdir)/lib/Makefile.bsd-lib \
	$(top_srcdir)/lib/Makefile.darwin-lib \
	$(top_srcdir)/lib/Makefile.solaris-lib \
	$(top_srcdir)/lib/Makefile.profile

$(top_builddir)/config.status: $(top_srcdir)/configure
	cd $(top_builddir); ./config.status --recheck

$(top_builddir)/MCONFIG: $(top_srcdir)/MCONFIG.in $(top_builddir)/config.status
	cd $(top_builddir); CONFIG_FILES=MCONFIG ./config.status

$(top_builddir)/lib/config.h: $(top_srcdir)/lib/config.h.in \
			      $(top_builddir)/config.status
	cd $(top_builddir); CONFIG_FILES=lib/config.h ./config.status

$(top_builddir)/lib/dirpaths.h: $(DEP_SUBSTITUTE) $(top_srcdir)/lib/dirpaths.h.in
	$(E) "	SUBST $@"
	$(Q) $(SUBSTITUTE) $(top_srcdir)/lib/dirpaths.h.in $@

$(top_builddir)/lib/substitute_sh: $(top_srcdir)/lib/substitute_sh.in \
		$(top_builddir)/config.status
	cd $(top_builddir); CONFIG_FILES=lib/substitute_sh ./config.status

$(top_builddir)/util/subst.conf: $(top_srcdir)/util/subst.conf.in \
		$(top_builddir)/config.status
	cd $(top_builddir); CONFIG_FILES=util/subst.conf ./config.status

Makefile: $(srcdir)/Makefile.in $(top_builddir)/MCONFIG \
		$(DEP_MAKEFILE) $(top_builddir)/config.status
	cd $(top_builddir); CONFIG_FILES=$(my_dir)/Makefile ./config.status

#$(top_srcdir)/configure: $(top_srcdir)/configure.in
#	cd $(top_srcdir) && autoheader && autoconf

coverage.txt: Makefile $(SRCS)
	if test -n "$(SRCS)"; then \
		gcov -s $(top_srcdir) -o . $(SRCS) > coverage.txt 2>&1 ; \
	fi

clean::
	$(RM) -f *.gcda *.gcov *.gcno coverage.txt

#
# Make depend magic...
#

.depend: Makefile $(SRCS) $(top_srcdir)/depfix.sed $(top_srcdir)/wordwrap.pl
	if test -n "$(SRCS)" ; then \
		$(CC) -M $(ALL_CFLAGS) $(DEPEND_CFLAGS) $(SRCS) | \
			$(SED) -f $(top_srcdir)/depfix.sed \
			    -e 's; $(srcdir)/; $$(srcdir)/;g' \
			    -e 's; $(top_srcdir)/; $$(top_srcdir)/;g' \
			    -e 's; $(top_builddir)/; $$(top_builddir)/;g' \
			    -e 's; \./; ;g' \
			    -e '/^#/d' \
			    -e '/^ *\\$$/d' | \
			$(PERL) $(top_srcdir)/wordwrap.pl > .depend; \
	else :; fi

depend:: .depend
	if test -n "$(SRCS)" ; then \
		sed -e '/^# +++ Dependency line eater +++/,$$d' \
			< $(srcdir)/Makefile.in | cat - .depend \
			> $(srcdir)/Makefile.in.new; \
	if cmp -s $(srcdir)/Makefile.in $(srcdir)/Makefile.in.new ; then \
		$(RM) $(srcdir)/Makefile.in.new ; \
	else \
		$(MV) $(srcdir)/Makefile.in $(srcdir)/Makefile.in.old; \
		$(MV) $(srcdir)/Makefile.in.new $(srcdir)/Makefile.in; \
	fi ; else :; fi

# End of file MCONFIG

#DEBUGFS_LIB_OBJS = bb_compat.o inode_io.o write_bb_file.o

MK_CMDS=	_SS_DIR_OVERRIDE=../ss ../ss/mk_cmds

#RESIZE_LIB_OBJS = dupfs.o
#TEST_IO_LIB_OBJS = test_io.o
#E2IMAGE_LIB_OBJS = imager.o

DEBUG_OBJS= debug_cmds.o extent_cmds.o tst_cmds.o debugfs.o util.o \
	ncheck.o icheck.o ls.o lsdel.o dump.o set_fields.o logdump.o \
	htree.o unused.o e2freefrag.o filefrag.o extent_inode.o zap.o \
	quota.o tst_libext2fs.o

DEBUG_SRCS= debug_cmds.c extent_cmds.c tst_cmds.c \
	$(top_srcdir)/debugfs/debugfs.c \
	$(top_srcdir)/debugfs/util.c \
	$(top_srcdir)/debugfs/ncheck.c \
	$(top_srcdir)/debugfs/icheck.c \
	$(top_srcdir)/debugfs/ls.c \
	$(top_srcdir)/debugfs/lsdel.c \
	$(top_srcdir)/debugfs/dump.c \
	$(top_srcdir)/debugfs/set_fields.c \
	$(top_srcdir)/debugfs/logdump.c \
	$(top_srcdir)/debugfs/htree.c \
	$(top_srcdir)/debugfs/unused.c \
	$(top_srcdir)/debugfs/filefrag.c \
	$(top_srcdir)/debugfs/extent_inode.c \
	$(top_srcdir)/debugfs/zap.c \
	$(top_srcdir)/debugfs/quota.c \
	$(top_srcdir)/misc/e2freefrag.c

OBJS= $(DEBUGFS_LIB_OBJS) $(RESIZE_LIB_OBJS) $(E2IMAGE_LIB_OBJS) \
	$(TEST_IO_LIB_OBJS) \
	ext2_err.o \
	alloc.o \
	alloc_sb.o \
	alloc_stats.o \
	alloc_tables.o \
	badblocks.o \
	bb_inode.o \
	bitmaps.o \
	bitops.o \
	blkmap64_ba.o \
	blkmap64_rb.o \
	blknum.o \
	block.o \
	bmap.o \
	check_desc.o \
	closefs.o \
	crc16.o \
	crc32c.o \
	csum.o \
	dblist.o \
	dblist_dir.o \
	dirblock.o \
	dirhash.o \
	dir_iterate.o \
	expanddir.o \
	ext_attr.o \
	extent.o \
	fileio.o \
	finddev.o \
	flushb.o \
	freefs.o \
	gen_bitmap.o \
	gen_bitmap64.o \
	get_pathname.o \
	getsize.o \
	getsectsize.o \
	i_block.o \
	icount.o \
	ind_block.o \
	initialize.o \
	inline.o \
	inode.o \
	io_manager.o \
	ismounted.o \
	link.o \
	llseek.o \
	lookup.o \
	mkdir.o \
	mkjournal.o \
	mmp.o \
	namei.o \
	native.o \
	newdir.o \
	openfs.o \
	progress.o \
	punch.o \
	qcow2.o \
	read_bb.o \
	read_bb_file.o \
	res_gdt.o \
	rw_bitmaps.o \
	swapfs.o \
	symlink.o \
	tdb.o \
	undo_io.o \
	unix_io.o \
	unlink.o \
	valid_blk.o \
	version.o \
	rbtree.o

SRCS= ext2_err.c \
	$(srcdir)/alloc.c \
	$(srcdir)/alloc_sb.c \
	$(srcdir)/alloc_stats.c \
	$(srcdir)/alloc_tables.c \
	$(srcdir)/badblocks.c \
	$(srcdir)/bb_compat.c \
	$(srcdir)/bb_inode.c \
	$(srcdir)/bitmaps.c \
	$(srcdir)/bitops.c \
	$(srcdir)/blkmap64_ba.c \
	$(srcdir)/blkmap64_rb.c \
	$(srcdir)/block.c \
	$(srcdir)/bmap.c \
	$(srcdir)/check_desc.c \
	$(srcdir)/closefs.c \
	$(srcdir)/crc16.c \
	$(srcdir)/crc32c.c \
	$(srcdir)/gen_crc32ctable.c \
	$(srcdir)/csum.c \
	$(srcdir)/dblist.c \
	$(srcdir)/dblist_dir.c \
	$(srcdir)/dirblock.c \
	$(srcdir)/dirhash.c \
	$(srcdir)/dir_iterate.c \
	$(srcdir)/dupfs.c \
	$(srcdir)/expanddir.c \
	$(srcdir)/ext_attr.c \
	$(srcdir)/extent.c \
	$(srcdir)/fileio.c \
	$(srcdir)/finddev.c \
	$(srcdir)/flushb.c \
	$(srcdir)/freefs.c \
	$(srcdir)/gen_bitmap.c \
	$(srcdir)/gen_bitmap64.c \
	$(srcdir)/get_pathname.c \
	$(srcdir)/getsize.c \
	$(srcdir)/getsectsize.c \
	$(srcdir)/i_block.c \
	$(srcdir)/icount.c \
	$(srcdir)/ind_block.c \
	$(srcdir)/initialize.c \
	$(srcdir)/inline.c \
	$(srcdir)/inode.c \
	$(srcdir)/inode_io.c \
	$(srcdir)/imager.c \
	$(srcdir)/io_manager.c \
	$(srcdir)/ismounted.c \
	$(srcdir)/link.c \
	$(srcdir)/llseek.c \
	$(srcdir)/lookup.c \
	$(srcdir)/mkdir.c \
	$(srcdir)/mkjournal.c \
	$(srcdir)/mmp.c	\
	$(srcdir)/namei.c \
	$(srcdir)/native.c \
	$(srcdir)/newdir.c \
	$(srcdir)/openfs.c \
	$(srcdir)/progress.c \
	$(srcdir)/punch.c \
	$(srcdir)/qcow2.c \
	$(srcdir)/read_bb.c \
	$(srcdir)/read_bb_file.c \
	$(srcdir)/res_gdt.c \
	$(srcdir)/rw_bitmaps.c \
	$(srcdir)/swapfs.c \
	$(srcdir)/symlink.c \
	$(srcdir)/tdb.c \
	$(srcdir)/test_io.c \
	$(srcdir)/tst_badblocks.c \
	$(srcdir)/tst_bitops.c \
	$(srcdir)/tst_byteswap.c \
	$(srcdir)/tst_getsize.c \
	$(srcdir)/tst_iscan.c \
	$(srcdir)/undo_io.c \
	$(srcdir)/unix_io.c \
	$(srcdir)/unlink.c \
	$(srcdir)/valid_blk.c \
	$(srcdir)/version.c \
	$(srcdir)/write_bb_file.c \
	$(srcdir)/rbtree.c \
	$(srcdir)/tst_libext2fs.c \
	$(DEBUG_SRCS)

HFILES= bitops.h ext2fs.h ext2_io.h ext2_fs.h ext2_ext_attr.h ext3_extents.h \
	tdb.h qcow2.h
HFILES_IN=  ext2_err.h ext2_types.h

LIBRARY= libext2fs
LIBDIR= ext2fs

ELF_VERSION = 2.4
ELF_SO_VERSION = 2
ELF_IMAGE = libext2fs
ELF_MYDIR = ext2fs
ELF_INSTALL_DIR = $(root_libdir)
ELF_OTHER_LIBS = -lcom_err

BSDLIB_VERSION = 2.1
BSDLIB_IMAGE = libext2fs
BSDLIB_MYDIR = ext2fs
BSDLIB_INSTALL_DIR = $(root_libdir)

all:: subdirs $(LIBRARY).a

install-shlibs::

uninstall-shlibs::

real-subdirs::

subdirs:: Makefile
	$(Q) $(MAKE) -s real-subdirs
	$(Q) touch subdirs

clean::
	$(Q) $(RM) -f subdirs

$(LIBRARY).a: $(OBJS)
	$(E) "	GEN_LIB $@"
	$(Q) (if test -r $@; then $(RM) -f $@.bak && $(MV) $@ $@.bak; fi)
	$(Q) $(ARGEN) $@ $(OBJS)
	-@$(RANLIB) $@
	$(Q) $(RM) -f ../$@
	$(Q) (cd ..; $(LN) $(LINK_BUILD_FLAGS) \
		`echo $(my_dir) | sed -e 's;lib/;;'`/$@ $@)

$(LIB)/$(LIBRARY).a: $(LIBRARY).a
#
# This is a Makefile stub which handles the creation of Linux ELF shared
# libraries.
#
# In order to use this stub, the following makefile variables must be defined.
# 
# ELF_VERSION = 1.0
# ELF_SO_VERSION = 1
# ELF_IMAGE = libce
# ELF_MYDIR = et
# ELF_INSTALL_DIR = $(SHLIBDIR)
# ELF_OTHER_LIBS = -lc

all:: image

real-subdirs:: Makefile
	$(E) "	MKDIR elfshared"
	$(Q) mkdir -p elfshared

ELF_LIB = $(ELF_IMAGE).so.$(ELF_VERSION)
ELF_SONAME = $(ELF_IMAGE).so.$(ELF_SO_VERSION)

image:		$(ELF_LIB)

$(ELF_LIB): $(OBJS)
	$(E) "	GEN_ELF_SOLIB $(ELF_LIB)"
	$(Q) (cd elfshared; $(CC) --shared -o $(ELF_LIB) \
		-L$(top_builddir)/../lib $(LDFLAGS) \
		-Wl,-soname,$(ELF_SONAME) $(OBJS) $(ELF_OTHER_LIBS))
	$(Q) $(MV) elfshared/$(ELF_LIB) .
	$(Q) $(RM) -f ../$(ELF_LIB) ../$(ELF_IMAGE).so ../$(ELF_SONAME)
	$(Q) (cd ..; $(LN) $(LINK_BUILD_FLAGS) \
		`echo $(my_dir) | sed -e 's;lib/;;'`/$(ELF_LIB) $(ELF_LIB))
	$(Q) (cd ..; $(LN) $(LINK_BUILD_FLAGS) $(ELF_LIB) $(ELF_IMAGE).so)
	$(Q) (cd ..; $(LN) $(LINK_BUILD_FLAGS) $(ELF_LIB) $(ELF_SONAME))

installdirs-elf-lib::
	$(E) "	MKINSTALLDIRS $(ELF_INSTALL_DIR) $(libdir)"
	$(Q) $(MKINSTALLDIRS) $(DESTDIR)$(ELF_INSTALL_DIR) \
		$(DESTDIR)$(libdir)

installdirs:: installdirs-elf-lib

install-shlibs install:: $(ELF_LIB) installdirs-elf-lib $(DEP_INSTALL_SYMLINK)
	$(E) "	INSTALL-ELF-LIB $(ELF_INSTALL_DIR)/$(ELF_LIB)"
	$(Q) $(INSTALL_PROGRAM) $(ELF_LIB) $(DESTDIR)$(ELF_INSTALL_DIR)/$(ELF_LIB)
	$(E) "	SYMLINK $(ELF_INSTALL_DIR)/$(ELF_SONAME)"
	$(Q) $(INSTALL_SYMLINK) $(ELF_INSTALL_DIR)/$(ELF_LIB) \
		$(ELF_INSTALL_DIR)/$(ELF_SONAME) $(DESTDIR)
	$(E) "	SYMLINK $(libdir)/$(ELF_IMAGE).so"
	$(Q) $(INSTALL_SYMLINK) $(ELF_INSTALL_DIR)/$(ELF_SONAME) \
		$(libdir)/$(ELF_IMAGE).so $(DESTDIR)
	$(E) "	LDCONFIG"
	$(Q) -$(LDCONFIG)

install-strip: install
	$(E) "	STRIP-LIB $(ELF_INSTALL_DIR)/$(ELF_LIB)"
	$(Q) $(STRIP) --strip-unneeded --remove-section=.comment \
		--remove-section=.note $(DESTDIR)$(ELF_INSTALL_DIR)/$(ELF_LIB)

install-shlibs-strip: install-shlibs
	$(E) "	STRIP-LIB $(ELF_INSTALL_DIR)/$(ELF_LIB)"
	$(Q) $(STRIP) --strip-unneeded --remove-section=.comment \
		--remove-section=.note $(DESTDIR)$(ELF_INSTALL_DIR)/$(ELF_LIB)

uninstall-shlibs uninstall::
	$(RM) -f $(DESTDIR)$(ELF_INSTALL_DIR)/$(ELF_LIB) \
		$(DESTDIR)$(ELF_INSTALL_DIR)/$(ELF_SONAME) \
		$(DESTDIR)$(libdir)/$(ELF_IMAGE).so
	-$(LDCONFIG)

clean::
	$(RM) -rf elfshared
	$(RM) -f $(ELF_LIB)
	$(RM) -f ../$(ELF_LIB) ../$(ELF_IMAGE).so ../$(ELF_SONAME)

all:: ext2fs.pc

.c.o:
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@
	$(Q) $(CHECK_CMD) $(ALL_CFLAGS) $<
#	$(Q) $(CC) $(ALL_CFLAGS) -g -pg -o profiled/$*.o -c $<
	$(Q) $(CC) $(ALL_CFLAGS) -fPIC -o elfshared/$*.o -c $<
#	$(Q) $(CC) $(ALL_CFLAGS) $(BSDLIB_PIC_FLAG) -o pic/$*.o -c $<

COMPILE_ET=../et/compile_et --build-tree

DISTFILES= Makefile *.c *.h image

ext2_err.et: $(DEP_SUBSTITUTE) $(srcdir)/ext2_err.et.in
	$(E) "	SUBST $@"
	$(Q) $(SUBSTITUTE) $(srcdir)/ext2_err.et.in ext2_err.et

ext2_err.c ext2_err.h: ext2_err.et
	$(E) "	COMPILE_ET ext2_err.et"
	$(Q) $(COMPILE_ET) ext2_err.et

ext2fs.pc: $(srcdir)/ext2fs.pc.in $(top_builddir)/config.status
	$(E) "	CONFIG.STATUS $@"
	$(Q) cd $(top_builddir); CONFIG_FILES=lib/ext2fs/ext2fs.pc ./config.status

tst_badblocks: tst_badblocks.o $(STATIC_LIBEXT2FS) $(DEPSTATIC_LIBCOM_ERR)
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_badblocks tst_badblocks.o $(ALL_LDFLAGS) \
		$(STATIC_LIBEXT2FS) $(STATIC_LIBCOM_ERR) $(SYSLIBS)

tst_icount: $(srcdir)/icount.c $(STATIC_LIBEXT2FS) $(DEPSTATIC_LIBCOM_ERR)
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_icount $(srcdir)/icount.c -DDEBUG \
		$(ALL_CFLAGS) $(ALL_LDFLAGS) \
		$(STATIC_LIBEXT2FS) $(STATIC_LIBCOM_ERR) $(SYSLIBS)

tst_iscan: tst_iscan.o $(STATIC_LIBEXT2FS) $(DEPSTATIC_LIBCOM_ERR)
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_iscan tst_iscan.o $(ALL_LDFLAGS) \
		$(STATIC_LIBEXT2FS) $(STATIC_LIBCOM_ERR) $(SYSLIBS)

tst_getsize: tst_getsize.o $(STATIC_LIBEXT2FS) $(DEPSTATIC_LIBCOM_ERR)
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_getsize tst_getsize.o $(ALL_LDFLAGS) \
		$(STATIC_LIBEXT2FS) $(STATIC_LIBCOM_ERR) $(SYSLIBS)

tst_ismounted: $(srcdir)/ismounted.c $(STATIC_LIBEXT2FS) \
		$(DEPSTATIC_LIBCOM_ERR)
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_ismounted $(srcdir)/ismounted.c \
		$(STATIC_LIBEXT2FS) -DDEBUG $(ALL_CFLAGS) $(ALL_LDFLAGS) \
		$(STATIC_LIBCOM_ERR) $(SYSLIBS)

tst_byteswap: tst_byteswap.o $(STATIC_LIBEXT2FS) $(DEPSTATIC_LIBCOM_ERR)
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_byteswap tst_byteswap.o $(ALL_LDFLAGS) \
		$(STATIC_LIBEXT2FS) $(STATIC_LIBCOM_ERR) $(SYSLIBS)

tst_bitops: tst_bitops.o $(STATIC_LIBEXT2FS) $(DEPSTATIC_LIBCOM_ERR)
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_bitops tst_bitops.o $(ALL_CFLAGS) $(ALL_LDFLAGS) \
		$(STATIC_LIBEXT2FS) $(STATIC_LIBCOM_ERR) $(SYSLIBS)

tst_getsectsize: tst_getsectsize.o $(STATIC_LIBEXT2FS) $(DEPSTATIC_LIBCOM_ERR)
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_sectgetsize tst_getsectsize.o $(ALL_LDFLAGS) \
		$(STATIC_LIBEXT2FS) $(STATIC_LIBCOM_ERR) $(SYSLIBS)

tst_types.o: $(srcdir)/tst_types.c ext2_types.h 

tst_types: tst_types.o ext2_types.h 
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_types tst_types.o $(ALL_LDFLAGS) $(SYSLIBS)

tst_super_size.o: $(srcdir)/tst_super_size.c $(srcdir)/ext2_fs.h

tst_super_size: tst_super_size.o
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_super_size tst_super_size.o $(ALL_LDFLAGS) $(SYSLIBS)

tst_fs_struct.o: $(srcdir)/tst_fs_struct.c $(srcdir)/ext2fs.h

tst_fs_struct: tst_fs_struct.o
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_fs_struct tst_fs_struct.o $(ALL_LDFLAGS) $(SYSLIBS)

tst_inode_size.o: $(srcdir)/tst_inode_size.c $(srcdir)/ext2_fs.h

tst_inode_size: tst_inode_size.o
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_inode_size tst_inode_size.o $(ALL_LDFLAGS) $(SYSLIBS)

ext2_tdbtool: tdbtool.o
	$(E) "	LD $@"
	$(Q) $(CC) -o ext2_tdbtool tdbtool.o tdb.o $(ALL_LDFLAGS) $(SYSLIBS)

tst_cmds.c tst_cmds.h: tst_cmds.ct
	$(E) "	MK_CMDS $@"
	$(Q) $(MK_CMDS) $(srcdir)/tst_cmds.ct

debug_cmds.c debug_cmds.h: $(top_srcdir)/debugfs/debug_cmds.ct
	$(E) "	MK_CMDS $<"
	$(Q) $(MK_CMDS) $(top_srcdir)/debugfs/debug_cmds.ct

extent_cmds.c extent_cmds.h: $(top_srcdir)/debugfs/extent_cmds.ct
	$(E) "	MK_CMDS $<"
	$(Q) $(MK_CMDS) $(top_srcdir)/debugfs/extent_cmds.ct

debugfs.o: $(top_srcdir)/debugfs/debugfs.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@

extent_inode.o: $(top_srcdir)/debugfs/extent_inode.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@

util.o: $(top_srcdir)/debugfs/util.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@

ncheck.o: $(top_srcdir)/debugfs/ncheck.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@

icheck.o: $(top_srcdir)/debugfs/icheck.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@

ls.o: $(top_srcdir)/debugfs/ls.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@

lsdel.o: $(top_srcdir)/debugfs/lsdel.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@

dump.o: $(top_srcdir)/debugfs/dump.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@

set_fields.o: $(top_srcdir)/debugfs/set_fields.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@

logdump.o: $(top_srcdir)/debugfs/logdump.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@

htree.o: $(top_srcdir)/debugfs/htree.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@

unused.o: $(top_srcdir)/debugfs/unused.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@

zap.o: $(top_srcdir)/debugfs/zap.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@

quota.o: $(top_srcdir)/debugfs/quota.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@

e2freefrag.o: $(top_srcdir)/misc/e2freefrag.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -DDEBUGFS -I$(top_srcdir)/debugfs -c $< -o $@

filefrag.o: $(top_srcdir)/debugfs/filefrag.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) -c $< -o $@

tst_libext2fs.o: $(srcdir)/tst_libext2fs.c
	$(E) "	CC $<"
	$(Q) $(CC) $(ALL_CFLAGS) $(ALL_LDFLAGS) $(DEPEND_CFLAGS) -c $< -o $@

tst_bitmaps_cmd.c: tst_bitmaps_cmd.ct
	$(E) "	MK_CMDS $@"
	$(Q) DIR=$(srcdir) $(MK_CMDS) $(srcdir)/tst_bitmaps_cmd.ct

tst_bitmaps: tst_bitmaps.o tst_bitmaps_cmd.o $(srcdir)/blkmap64_rb.c \
		$(STATIC_LIBEXT2FS) $(DEPSTATIC_LIBSS) $(DEPSTATIC_LIBCOM_ERR)
	$(E) "	LD $@"
	$(Q) $(CC) -o $@ tst_bitmaps.o tst_bitmaps_cmd.o \
		-DDEBUG_RB $(srcdir)/blkmap64_rb.c $(ALL_CFLAGS) \
		$(ALL_LDFLAGS) $(STATIC_LIBEXT2FS) $(STATIC_LIBSS) \
		$(STATIC_LIBCOM_ERR) $(SYSLIBS)

tst_extents: $(srcdir)/extent.c $(DEBUG_OBJS) $(DEPSTATIC_LIBSS) libext2fs.a \
	$(STATIC_LIBE2P) $(DEPLIBUUID) $(DEPLIBBLKID) $(DEPSTATIC_LIBCOM_ERR) \
	$(DEPLIBQUOTA)
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_extents $(srcdir)/extent.c \
		$(ALL_CFLAGS) $(ALL_LDFLAGS) -DDEBUG $(DEBUG_OBJS) \
		$(STATIC_LIBSS) $(STATIC_LIBE2P) $(LIBQUOTA) \
		$(STATIC_LIBEXT2FS) $(LIBBLKID) $(LIBUUID) \
		$(STATIC_LIBCOM_ERR) $(SYSLIBS) -I $(top_srcdir)/debugfs

tst_libext2fs: $(DEBUG_OBJS) \
	$(DEPSTATIC_LIBSS) $(STATIC_LIBE2P) $(DEPLIBUUID) libext2fs.a \
	$(DEPLIBBLKID) $(DEPSTATIC_LIBCOM_ERR) $(DEPLIBQUOTA)
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_libext2fs $(ALL_LDFLAGS) -DDEBUG $(DEBUG_OBJS) \
		$(STATIC_LIBSS) $(STATIC_LIBE2P) $(LIBQUOTA) \
		$(STATIC_LIBEXT2FS) $(LIBBLKID) $(LIBUUID) \
		$(STATIC_LIBCOM_ERR) $(SYSLIBS) -I $(top_srcdir)/debugfs

tst_inline: $(srcdir)/inline.c $(STATIC_LIBEXT2FS) $(DEPSTATIC_LIBCOM_ERR)
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_inline $(srcdir)/inline.c $(ALL_CFLAGS) \
		$(ALL_LDFLAGS) -DDEBUG $(STATIC_LIBEXT2FS) \
		$(STATIC_LIBCOM_ERR) $(SYSLIBS)

tst_csum: csum.c $(STATIC_LIBEXT2FS) $(DEPSTATIC_LIBCOM_ERR) $(STATIC_LIBE2P) \
		$(top_srcdir)/lib/e2p/e2p.h
	$(E) "	LD $@"
	$(Q) $(CC) -o tst_csum $(srcdir)/csum.c -DDEBUG \
		$(ALL_CFLAGS) $(ALL_LDFLAGS) $(STATIC_LIBEXT2FS) \
		$(STATIC_LIBCOM_ERR) $(STATIC_LIBE2P) $(SYSLIBS)

tst_crc32c: $(srcdir)/crc32c.c $(STATIC_LIBEXT2FS) $(DEPSTATIC_LIBCOM_ERR)
	$(Q) $(CC) $(ALL_LDFLAGS) $(ALL_CFLAGS) -o tst_crc32c $(srcdir)/crc32c.c \
		-DUNITTEST $(STATIC_LIBEXT2FS) $(STATIC_LIBCOM_ERR) \
		$(SYSLIBS)

mkjournal: mkjournal.c $(STATIC_LIBEXT2FS) $(DEPLIBCOM_ERR)
	$(E) "	LD $@"
	$(Q) $(CC) -o mkjournal $(srcdir)/mkjournal.c -DDEBUG \
		$(STATIC_LIBEXT2FS) $(LIBCOM_ERR) $(ALL_CFLAGS) $(SYSLIBS)

check:: tst_bitops tst_badblocks tst_iscan tst_types tst_icount \
    tst_super_size tst_types tst_inode_size tst_csum tst_crc32c tst_bitmaps \
    tst_inline tst_libext2fs
	$(TESTENV) ./tst_bitops
	$(TESTENV) ./tst_badblocks
	$(TESTENV) ./tst_iscan
	$(TESTENV) ./tst_types
	$(TESTENV) ./tst_icount
	$(TESTENV) ./tst_super_size
	$(TESTENV) ./tst_inode_size
	$(TESTENV) ./tst_csum
	$(TESTENV) ./tst_inline
	$(TESTENV) ./tst_crc32c
	$(TESTENV) ./tst_bitmaps -f $(srcdir)/tst_bitmaps_cmds > tst_bitmaps_out
	diff $(srcdir)/tst_bitmaps_exp tst_bitmaps_out
	$(TESTENV) ./tst_bitmaps -t 2 -f $(srcdir)/tst_bitmaps_cmds > tst_bitmaps_out
	diff $(srcdir)/tst_bitmaps_exp tst_bitmaps_out
	$(TESTENV) ./tst_bitmaps -t 3 -f $(srcdir)/tst_bitmaps_cmds > tst_bitmaps_out
	diff $(srcdir)/tst_bitmaps_exp tst_bitmaps_out
	$(TESTENV) ./tst_bitmaps -l -f $(srcdir)/tst_bitmaps_cmds > tst_bitmaps_out
	diff $(srcdir)/tst_bitmaps_exp tst_bitmaps_out

installdirs::
	$(E) "	MKINSTALLDIRS $(libdir) $(includedir)/ext2fs"
	$(Q) $(MKINSTALLDIRS) $(DESTDIR)$(libdir) \
		$(DESTDIR)$(includedir)/ext2fs $(DESTDIR)$(pkgconfigdir)

install:: all $(HFILES) $(HFILES_IN) installdirs ext2fs.pc
	$(E) "	INSTALL_DATA $(libdir)/libext2fs.a"
	$(Q) $(INSTALL_DATA) libext2fs.a $(DESTDIR)$(libdir)/libext2fs.a
	-$(Q) $(RANLIB) $(DESTDIR)$(libdir)/libext2fs.a
	$(Q) $(CHMOD) $(LIBMODE) $(DESTDIR)$(libdir)/libext2fs.a
	$(Q) for i in $(HFILES); do \
		echo "	INSTALL_DATA $(includedir)/ext2fs/$$i"; \
		$(INSTALL_DATA) $(srcdir)/$$i $(DESTDIR)$(includedir)/ext2fs/$$i; \
	done
	$(Q) for i in $(HFILES_IN); do \
		echo "	INSTALL_DATA $(includedir)/ext2fs/$$i"; \
		$(INSTALL_DATA) $$i $(DESTDIR)$(includedir)/ext2fs/$$i; \
	done
	$(E) "	INSTALL_DATA $(pkgconfigdir)/ext2fs.pc"
	$(Q) $(INSTALL_DATA) ext2fs.pc $(DESTDIR)$(pkgconfigdir)/ext2fs.pc

uninstall::
	$(RM) -f $(DESTDIR)$(libdir)/libext2fs.a \
		$(DESTDIR)$(pkgconfigdir)/ext2fs.pc
	$(RM) -rf $(DESTDIR)$(includedir)/ext2fs 

clean::
	$(RM) -f \#* *.s *.o *.a *~ *.bak core profiled/* \
		tst_badblocks tst_iscan ext2_err.et ext2_err.c ext2_err.h \
		tst_byteswap tst_ismounted tst_getsize tst_sectgetsize \
		tst_bitops tst_types tst_icount tst_super_size tst_csum \
		tst_bitmaps tst_bitmaps_out tst_extents tst_inline \
		tst_inline_data tst_inode_size tst_bitmaps_cmd.c \
		ext2_tdbtool mkjournal debug_cmds.c tst_cmds.c extent_cmds.c \
		../libext2fs.a ../libext2fs_p.a ../libext2fs_chk.a \
		crc32c_table.h gen_crc32ctable tst_crc32c tst_libext2fs \
		ext2fs.pc ext2_types.h

mostlyclean:: clean
distclean:: clean
	$(RM) -f .depend ext2_err.c ext2_err.h Makefile ext2fs.pc \
		$(srcdir)/TAGS $(srcdir)/Makefile.in.old
#
# Hack to parallel makes recognize dependencies correctly.
#
$(top_builddir)/lib/ext2fs/ext2_err.h: ext2_err.h

$(OBJS): subdirs

gen_crc32ctable: $(srcdir)/gen_crc32ctable.c
	$(E) "	CC $@"
	$(Q) $(BUILD_CC) $(BUILD_CFLAGS) $(BUILD_LDFLAGS) -o gen_crc32ctable \
		$(srcdir)/gen_crc32ctable.c

crc32c_table.h: gen_crc32ctable
	$(E) "	GEN32CTABLE $@"
	$(Q) ./gen_crc32ctable > crc32c_table.h

$(top_builddir)/$(my_dir)/ext2_types.h: $(srcdir)/ext2_types.h.in \
		$(top_builddir)/config.status
	cd $(top_builddir); CONFIG_FILES=$(my_dir)/ext2_types.h ./config.status

# +++ Dependency line eater +++
# 
# Makefile dependencies follow.  This must be the last section in
# the Makefile.in file
#
ext2_err.o: ext2_err.c
alloc.o: $(srcdir)/alloc.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
alloc_sb.o: $(srcdir)/alloc_sb.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
alloc_stats.o: $(srcdir)/alloc_stats.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
alloc_tables.o: $(srcdir)/alloc_tables.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h $(srcdir)/ext2fsP.h
badblocks.o: $(srcdir)/badblocks.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h
bb_compat.o: $(srcdir)/bb_compat.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h
bb_inode.o: $(srcdir)/bb_inode.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
bitmaps.o: $(srcdir)/bitmaps.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h $(srcdir)/ext2fsP.h \
 $(srcdir)/bmap64.h
bitops.o: $(srcdir)/bitops.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
blkmap64_ba.o: $(srcdir)/blkmap64_ba.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(srcdir)/bmap64.h
blkmap64_rb.o: $(srcdir)/blkmap64_rb.c $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(srcdir)/bmap64.h $(srcdir)/rbtree.h
block.o: $(srcdir)/block.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
bmap.o: $(srcdir)/bmap.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h
check_desc.o: $(srcdir)/check_desc.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
closefs.o: $(srcdir)/closefs.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h
crc16.o: $(srcdir)/crc16.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_builddir)/lib/ext2fs/ext2_types.h \
 $(srcdir)/crc16.h
crc32c.o: $(srcdir)/crc32c.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/crc32c_defs.h $(srcdir)/ext2fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2_fs.h \
 $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h crc32c_table.h
gen_crc32ctable.o: $(srcdir)/gen_crc32ctable.c $(srcdir)/crc32c_defs.h
csum.o: $(srcdir)/csum.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h $(srcdir)/crc16.h
dblist.o: $(srcdir)/dblist.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h
dblist_dir.o: $(srcdir)/dblist_dir.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h
dirblock.o: $(srcdir)/dirblock.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
dirhash.o: $(srcdir)/dirhash.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
dir_iterate.o: $(srcdir)/dir_iterate.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h
dupfs.o: $(srcdir)/dupfs.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h
expanddir.o: $(srcdir)/expanddir.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
ext_attr.o: $(srcdir)/ext_attr.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h
extent.o: $(srcdir)/extent.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(srcdir)/e2image.h
fileio.o: $(srcdir)/fileio.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h $(srcdir)/ext2fsP.h
finddev.o: $(srcdir)/finddev.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h $(srcdir)/ext2fsP.h
flushb.o: $(srcdir)/flushb.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
freefs.o: $(srcdir)/freefs.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h
gen_bitmap.o: $(srcdir)/gen_bitmap.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h
gen_bitmap64.o: $(srcdir)/gen_bitmap64.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(srcdir)/bmap64.h
get_pathname.o: $(srcdir)/get_pathname.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
getsize.o: $(srcdir)/getsize.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
getsectsize.o: $(srcdir)/getsectsize.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
i_block.o: $(srcdir)/i_block.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
icount.o: $(srcdir)/icount.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h $(srcdir)/tdb.h
ind_block.o: $(srcdir)/ind_block.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
initialize.o: $(srcdir)/initialize.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
inline.o: $(srcdir)/inline.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
inode.o: $(srcdir)/inode.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(srcdir)/e2image.h
inode_io.o: $(srcdir)/inode_io.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
imager.o: $(srcdir)/imager.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
io_manager.o: $(srcdir)/io_manager.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
ismounted.o: $(srcdir)/ismounted.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
link.o: $(srcdir)/link.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
llseek.o: $(srcdir)/llseek.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h
lookup.o: $(srcdir)/lookup.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
mkdir.o: $(srcdir)/mkdir.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
mkjournal.o: $(srcdir)/mkjournal.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(top_srcdir)/lib/e2p/e2p.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext2fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(srcdir)/jfs_user.h $(srcdir)/kernel-jbd.h \
 $(srcdir)/jfs_compat.h $(srcdir)/kernel-list.h
mmp.o: $(srcdir)/mmp.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h
namei.o: $(srcdir)/namei.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h $(srcdir)/ext2fsP.h
native.o: $(srcdir)/native.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
newdir.o: $(srcdir)/newdir.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
openfs.o: $(srcdir)/openfs.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h $(srcdir)/e2image.h
progress.o: $(srcdir)/progress.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2_fs.h \
 $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(srcdir)/ext2fsP.h
punch.o: $(srcdir)/punch.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
qcow2.o: $(srcdir)/qcow2.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2_fs.h \
 $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(srcdir)/qcow2.h
read_bb.o: $(srcdir)/read_bb.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
read_bb_file.o: $(srcdir)/read_bb_file.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
res_gdt.o: $(srcdir)/res_gdt.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
rw_bitmaps.o: $(srcdir)/rw_bitmaps.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h $(srcdir)/e2image.h
swapfs.o: $(srcdir)/swapfs.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
symlink.o: $(srcdir)/symlink.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
tdb.o: $(srcdir)/tdb.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/tdb.h
test_io.o: $(srcdir)/test_io.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
tst_badblocks.o: $(srcdir)/tst_badblocks.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
tst_bitops.o: $(srcdir)/tst_bitops.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
tst_byteswap.o: $(srcdir)/tst_byteswap.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
tst_getsize.o: $(srcdir)/tst_getsize.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
tst_iscan.o: $(srcdir)/tst_iscan.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
undo_io.o: $(srcdir)/undo_io.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/tdb.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
unix_io.o: $(srcdir)/unix_io.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
unlink.o: $(srcdir)/unlink.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
valid_blk.o: $(srcdir)/valid_blk.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
version.o: $(srcdir)/version.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h $(top_srcdir)/version.h
write_bb_file.o: $(srcdir)/write_bb_file.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_io.h $(top_builddir)/lib/ext2fs/ext2_err.h \
 $(srcdir)/ext2_ext_attr.h $(srcdir)/bitops.h
rbtree.o: $(srcdir)/rbtree.c $(srcdir)/rbtree.h
tst_libext2fs.o: $(srcdir)/tst_libext2fs.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fsP.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext2_fs.h $(srcdir)/ext3_extents.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/ss/ss.h $(top_builddir)/lib/ss/ss_err.h \
 $(top_srcdir)/debugfs/debugfs.h $(srcdir)/ext2fs.h \
 $(top_srcdir)/lib/quota/quotaio.h $(top_srcdir)/lib/quota/dqblk_v2.h \
 $(top_srcdir)/lib/quota/quotaio_tree.h $(top_srcdir)/lib/../e2fsck/dict.h
debug_cmds.o: debug_cmds.c $(top_srcdir)/lib/ss/ss.h \
 $(top_builddir)/lib/ss/ss_err.h $(top_srcdir)/lib/et/com_err.h
extent_cmds.o: extent_cmds.c $(top_srcdir)/lib/ss/ss.h \
 $(top_builddir)/lib/ss/ss_err.h $(top_srcdir)/lib/et/com_err.h
tst_cmds.o: tst_cmds.c $(top_srcdir)/lib/ss/ss.h \
 $(top_builddir)/lib/ss/ss_err.h $(top_srcdir)/lib/et/com_err.h
debugfs.o: $(top_srcdir)/debugfs/debugfs.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_srcdir)/debugfs/debugfs.h \
 $(top_srcdir)/lib/ss/ss.h $(top_builddir)/lib/ss/ss_err.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/quota/quotaio.h \
 $(top_srcdir)/lib/quota/dqblk_v2.h $(top_srcdir)/lib/quota/quotaio_tree.h \
 $(top_srcdir)/lib/../e2fsck/dict.h $(top_srcdir)/lib/e2p/e2p.h \
 $(top_srcdir)/debugfs/../version.h $(top_srcdir)/debugfs/jfs_user.h \
 $(srcdir)/kernel-jbd.h $(srcdir)/jfs_compat.h $(srcdir)/kernel-list.h
util.o: $(top_srcdir)/debugfs/util.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_srcdir)/lib/ss/ss.h \
 $(top_builddir)/lib/ss/ss_err.h $(top_srcdir)/lib/et/com_err.h \
 $(top_srcdir)/debugfs/debugfs.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/quota/quotaio.h \
 $(top_srcdir)/lib/quota/dqblk_v2.h $(top_srcdir)/lib/quota/quotaio_tree.h \
 $(top_srcdir)/lib/../e2fsck/dict.h
ncheck.o: $(top_srcdir)/debugfs/ncheck.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_srcdir)/debugfs/debugfs.h \
 $(top_srcdir)/lib/ss/ss.h $(top_builddir)/lib/ss/ss_err.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/quota/quotaio.h \
 $(top_srcdir)/lib/quota/dqblk_v2.h $(top_srcdir)/lib/quota/quotaio_tree.h \
 $(top_srcdir)/lib/../e2fsck/dict.h
icheck.o: $(top_srcdir)/debugfs/icheck.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_srcdir)/debugfs/debugfs.h \
 $(top_srcdir)/lib/ss/ss.h $(top_builddir)/lib/ss/ss_err.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/quota/quotaio.h \
 $(top_srcdir)/lib/quota/dqblk_v2.h $(top_srcdir)/lib/quota/quotaio_tree.h \
 $(top_srcdir)/lib/../e2fsck/dict.h
ls.o: $(top_srcdir)/debugfs/ls.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_srcdir)/debugfs/debugfs.h \
 $(top_srcdir)/lib/ss/ss.h $(top_builddir)/lib/ss/ss_err.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/quota/quotaio.h \
 $(top_srcdir)/lib/quota/dqblk_v2.h $(top_srcdir)/lib/quota/quotaio_tree.h \
 $(top_srcdir)/lib/../e2fsck/dict.h
lsdel.o: $(top_srcdir)/debugfs/lsdel.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_srcdir)/debugfs/debugfs.h \
 $(top_srcdir)/lib/ss/ss.h $(top_builddir)/lib/ss/ss_err.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/quota/quotaio.h \
 $(top_srcdir)/lib/quota/dqblk_v2.h $(top_srcdir)/lib/quota/quotaio_tree.h \
 $(top_srcdir)/lib/../e2fsck/dict.h
dump.o: $(top_srcdir)/debugfs/dump.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_srcdir)/debugfs/debugfs.h \
 $(top_srcdir)/lib/ss/ss.h $(top_builddir)/lib/ss/ss_err.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/quota/quotaio.h \
 $(top_srcdir)/lib/quota/dqblk_v2.h $(top_srcdir)/lib/quota/quotaio_tree.h \
 $(top_srcdir)/lib/../e2fsck/dict.h
set_fields.o: $(top_srcdir)/debugfs/set_fields.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_srcdir)/debugfs/debugfs.h \
 $(top_srcdir)/lib/ss/ss.h $(top_builddir)/lib/ss/ss_err.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/quota/quotaio.h \
 $(top_srcdir)/lib/quota/dqblk_v2.h $(top_srcdir)/lib/quota/quotaio_tree.h \
 $(top_srcdir)/lib/../e2fsck/dict.h $(top_srcdir)/lib/e2p/e2p.h
logdump.o: $(top_srcdir)/debugfs/logdump.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_srcdir)/debugfs/debugfs.h \
 $(top_srcdir)/lib/ss/ss.h $(top_builddir)/lib/ss/ss_err.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/quota/quotaio.h \
 $(top_srcdir)/lib/quota/dqblk_v2.h $(top_srcdir)/lib/quota/quotaio_tree.h \
 $(top_srcdir)/lib/../e2fsck/dict.h $(top_srcdir)/debugfs/jfs_user.h \
 $(srcdir)/kernel-jbd.h $(srcdir)/jfs_compat.h $(srcdir)/kernel-list.h
htree.o: $(top_srcdir)/debugfs/htree.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_srcdir)/debugfs/debugfs.h \
 $(top_srcdir)/lib/ss/ss.h $(top_builddir)/lib/ss/ss_err.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/quota/quotaio.h \
 $(top_srcdir)/lib/quota/dqblk_v2.h $(top_srcdir)/lib/quota/quotaio_tree.h \
 $(top_srcdir)/lib/../e2fsck/dict.h $(top_srcdir)/lib/e2p/e2p.h
unused.o: $(top_srcdir)/debugfs/unused.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_srcdir)/debugfs/debugfs.h \
 $(top_srcdir)/lib/ss/ss.h $(top_builddir)/lib/ss/ss_err.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/quota/quotaio.h \
 $(top_srcdir)/lib/quota/dqblk_v2.h $(top_srcdir)/lib/quota/quotaio_tree.h \
 $(top_srcdir)/lib/../e2fsck/dict.h
filefrag.o: $(top_srcdir)/debugfs/filefrag.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_srcdir)/debugfs/debugfs.h \
 $(top_srcdir)/lib/ss/ss.h $(top_builddir)/lib/ss/ss_err.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/quota/quotaio.h \
 $(top_srcdir)/lib/quota/dqblk_v2.h $(top_srcdir)/lib/quota/quotaio_tree.h \
 $(top_srcdir)/lib/../e2fsck/dict.h
extent_inode.o: $(top_srcdir)/debugfs/extent_inode.c \
 $(top_builddir)/lib/config.h $(top_builddir)/lib/dirpaths.h \
 $(top_srcdir)/debugfs/debugfs.h $(top_srcdir)/lib/ss/ss.h \
 $(top_builddir)/lib/ss/ss_err.h $(top_srcdir)/lib/et/com_err.h \
 $(srcdir)/ext2_fs.h $(top_builddir)/lib/ext2fs/ext2_types.h \
 $(srcdir)/ext2fs.h $(srcdir)/ext3_extents.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/quota/quotaio.h \
 $(top_srcdir)/lib/quota/dqblk_v2.h $(top_srcdir)/lib/quota/quotaio_tree.h \
 $(top_srcdir)/lib/../e2fsck/dict.h
zap.o: $(top_srcdir)/debugfs/zap.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_srcdir)/debugfs/debugfs.h \
 $(top_srcdir)/lib/ss/ss.h $(top_builddir)/lib/ss/ss_err.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/quota/quotaio.h \
 $(top_srcdir)/lib/quota/dqblk_v2.h $(top_srcdir)/lib/quota/quotaio_tree.h \
 $(top_srcdir)/lib/../e2fsck/dict.h
quota.o: $(top_srcdir)/debugfs/quota.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(top_srcdir)/debugfs/debugfs.h \
 $(top_srcdir)/lib/ss/ss.h $(top_builddir)/lib/ss/ss_err.h \
 $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/lib/quota/quotaio.h \
 $(top_srcdir)/lib/quota/dqblk_v2.h $(top_srcdir)/lib/quota/quotaio_tree.h \
 $(top_srcdir)/lib/../e2fsck/dict.h
e2freefrag.o: $(top_srcdir)/misc/e2freefrag.c $(top_builddir)/lib/config.h \
 $(top_builddir)/lib/dirpaths.h $(srcdir)/ext2_fs.h \
 $(top_builddir)/lib/ext2fs/ext2_types.h $(srcdir)/ext2fs.h \
 $(srcdir)/ext3_extents.h $(top_srcdir)/lib/et/com_err.h $(srcdir)/ext2_io.h \
 $(top_builddir)/lib/ext2fs/ext2_err.h $(srcdir)/ext2_ext_attr.h \
 $(srcdir)/bitops.h $(top_srcdir)/misc/e2freefrag.h
