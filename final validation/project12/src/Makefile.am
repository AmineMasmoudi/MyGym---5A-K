## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = project12

project12_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
        coach.c coach.h \
        verif.c verif.h \
	medecin.c medecin.h \
	nutritionniste.c nutritionniste.h \
	agenda.c agenda.h \
	adherant.c adherant.h \
	avis.c avis.h \
	profil.c profil.h \
	interfacem.c interfacem.h \
	callbacksm.c callbacksm.h \
	verifierm.c verifierm.h \
	calendarm.c calendarm.h \
	fichem.c fichem.h \
	Ajoutadherent.c Ajoutadherent.h \
	Coach.c Coach.h \
	Medical.c Medical.h \
	Site.c Site.h

project12_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

