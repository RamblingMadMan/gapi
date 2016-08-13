OUT:=$(BUILD_DIR)/libgapi.la

SOURCES:=context.cpp functions.cpp
OBJECTS:=$(addprefix $(BUILD_DIR)/objs/,$(SOURCES:.cpp=.lo))

HEADER_FOLDER:=$(SRC_DIR)/include/gapi

CXXFLAGS:=$(shell pkg-config gl --cflags) $(CXXFLAGS)
LDFLAGS:=$(LDFLAGS) -version-info 1:0:1
LIBS:=$(LIBS) $(shell pkg-config gl --libs)

.PHONY: all install clean

all: dir $(OUT)

dir: | $(BUILD_DIR)/objs

$(BUILD_DIR)/objs:
	mkdir -p $@

$(OUT): $(OBJECTS)
	libtool --mode=link --tag=CXX $(CXX) $(LDFLAGS) -o $(OUT) $(OBJECTS) $(LIBS)

$(BUILD_DIR)/objs/%.lo: %.cpp
	libtool --mode=compile --tag=CXX $(CXX) -fPIC $(CXXFLAGS) -c $< -o $@

install-dir: | $(DESTDIR)/include/gapi $(DESTDIR)/lib

$(DESTDIR)/include/gapi:
	mkdir -p $@

$(DESTDIR)/lib:
	mkdir -p $@

install: all install-dir
	echo '#!/bin/bash' > uninstall.sh
	chmod +x uninstall.sh
	install -d $(DESTDIR)/include/gapi
	install $(HEADER_FOLDER)/* -t $(DESTDIR)/include/gapi
	libtool --mode=install install -c $(OUT) $(DESTDIR)/lib/libgapi.la
	echo libtool --mode=uninstall rm -f $(DESTDIR)/lib/libgapi.la >> uninstall.sh
	echo rm -rf $(DESTDIR)/include/glapi >> uninstall.sh
	libtool --finish $(DESTDIR)/lib

clean:
	rm -rf $(OUT) $(OBJECTS)
