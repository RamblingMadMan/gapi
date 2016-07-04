OUT:=$(BUILD_DIR)/libgapi.la

SOURCES:=context.cpp
OBJECTS:=$(addprefix $(BUILD_DIR)/objs/,$(SOURCES:.cpp=.lo))

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

install: all
	cp -r $(HEADER_FOLDER) $(DESTDIR)/include/gapi
	libtool --mode=install cp $(OUT) $(DESTDIR)/lib/libgapi.la
	echo $(DEST_DIR)/gapi > install-manifest.txt

clean:
	rm -rf $(OUT) $(OBJECTS)
