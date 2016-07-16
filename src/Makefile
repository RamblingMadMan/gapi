OUT:=$(BUILD_DIR)/libgapi.la

SOURCES:=context.cpp functions.cpp
OBJECTS:=$(addprefix $(BUILD_DIR)/objs/,$(SOURCES:.cpp=.lo))

CXXFLAGS:=$(shell pkg-config gl --cflags) $(CXXFLAGS)
LIBS:=$(LIBS) $(shell pkg-config gl --libs)

HEADER_FOLDER:=$(SRC_DIR)/include/gapi

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
	cp -r $(HEADER_FOLDER) $(DESTDIR)/include
	libtool --mode=install cp $(OUT) $(DESTDIR)/lib/libgapi.la
	echo libtool --mode=uninstall rm -f $(DESTDIR)/lib/libgapi.la >> uninstall.sh
	echo rm -rf $(DESTDIR)/include/glapi >> uninstall.sh
	libtool --finish $(DESTDIR)/lib

clean:
	rm -rf $(OUT) $(OBJECTS)
