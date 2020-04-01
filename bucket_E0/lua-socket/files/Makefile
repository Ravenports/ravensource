PLAT?= linux
PLATS= macosx linux win32 mingw

all: $(PLAT)

$(PLATS) none install install-unix local clean:
	$(MAKE) -C src $@

install:
	$(MAKE) clean 
	@cd src; $(MAKE) $(PLAT)
	@cd src; $(MAKE) install

install-unix:
	$(MAKE) clean 
	@cd src; $(MAKE) $(PLAT)
	@cd src; $(MAKE) install-unix
