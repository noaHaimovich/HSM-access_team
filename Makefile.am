ACLOCAL_AMFLAGS = -I m4

MAINTAINERCLEANFILES = \
        config.log config.status softhsm2.module \
        $(srcdir)/Makefile.in \
        $(srcdir)/configure \
        $(srcdir)/install-sh $(srcdir)/ltmain.sh $(srcdir)/missing \
        $(srcdir)/depcomp $(srcdir)/aclocal.m4 $(srcdir)/compile \
        $(srcdir)/config.guess $(srcdir)/config.sub

SUBDIRS = src

if WITH_P11KIT
p11moddir = @P11KIT_PATH@
p11mod_DATA = softhsm2.module
endif

EXTRA_DIST =	$(srcdir)/CMakeLists.txt \
		$(srcdir)/CMAKE-NOTES.md \
		$(srcdir)/config.h.in.cmake \
		$(srcdir)/FIPS-NOTES.md \
		$(srcdir)/LICENSE \
		$(srcdir)/m4/*.m4 \
		$(srcdir)/cmake/modules/*.cmake \
		$(srcdir)/cmake/modules/tests/*.c \
		$(srcdir)/cmake/modules/tests/*.cpp \
		$(srcdir)/OSX-NOTES.md \
		$(srcdir)/README.md \
		$(srcdir)/win32/convarch/convarch.vcxproj.in \
		$(srcdir)/win32/convarch/convarch.vcxproj.filters.in \
		$(srcdir)/win32/convarch/convarch.vcxproj.user \
		$(srcdir)/win32/cryptotest/cryptotest.vcxproj.in \
		$(srcdir)/win32/cryptotest/cryptotest.vcxproj.filters \
		$(srcdir)/win32/cryptotest/cryptotest.vcxproj.user \
		$(srcdir)/win32/datamgrtest/datamgrtest.vcxproj.in \
		$(srcdir)/win32/datamgrtest/datamgrtest.vcxproj.filters \
		$(srcdir)/win32/datamgrtest/datamgrtest.vcxproj.user \
		$(srcdir)/win32/dump/dump.vcxproj.in \
		$(srcdir)/win32/dump/dump.vcxproj.filters \
		$(srcdir)/win32/dump/dump.vcxproj.user \
		$(srcdir)/win32/handlemgrtest/handlemgrtest.vcxproj.in \
		$(srcdir)/win32/handlemgrtest/handlemgrtest.vcxproj.filters \
		$(srcdir)/win32/handlemgrtest/handlemgrtest.vcxproj.user \
		$(srcdir)/win32/keyconv/keyconv.vcxproj.in \
		$(srcdir)/win32/keyconv/keyconv.vcxproj.filters.in \
		$(srcdir)/win32/keyconv/keyconv.vcxproj.user \
		$(srcdir)/win32/objstoretest/objstoretest.vcxproj.in \
		$(srcdir)/win32/objstoretest/objstoretest.vcxproj.filters \
		$(srcdir)/win32/objstoretest/objstoretest.vcxproj.user \
		$(srcdir)/win32/p11test/p11test.vcxproj.in \
		$(srcdir)/win32/p11test/p11test.vcxproj.filters \
		$(srcdir)/win32/p11test/p11test.vcxproj.user \
		$(srcdir)/win32/sessionmgrtest/sessionmgrtest.vcxproj.in \
		$(srcdir)/win32/sessionmgrtest/sessionmgrtest.vcxproj.filters \
		$(srcdir)/win32/sessionmgrtest/sessionmgrtest.vcxproj.user \
		$(srcdir)/win32/slotmgrtest/slotmgrtest.vcxproj.in \
		$(srcdir)/win32/slotmgrtest/slotmgrtest.vcxproj.filters \
		$(srcdir)/win32/slotmgrtest/slotmgrtest.vcxproj.user \
		$(srcdir)/win32/softhsm2/softhsm2.vcxproj.in \
		$(srcdir)/win32/softhsm2/softhsm2.vcxproj.filters \
		$(srcdir)/win32/softhsm2/softhsm2.vcxproj.user \
		$(srcdir)/win32/softhsm2.sln.in \
		$(srcdir)/win32/util/util.vcxproj.in \
		$(srcdir)/win32/util/util.vcxproj.filters.in \
		$(srcdir)/win32/util/util.vcxproj.user \
		$(srcdir)/WIN32-NOTES.md
