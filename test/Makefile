OUT:=$(BUILD_DIR)/test

CXXFLAGS:=$(CXXFLAGS) $(shell pkg-config sdl2 --cflags) -shared
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) $(shell pkg-config sdl2 --libs) -lgapi

SOURCES:=\
	main.cpp\
	buffer.cpp\
	shader.cpp\
	shader_buffer.cpp\
	shader_texture.cpp
	
OBJECTS:=$(addprefix $(BUILD_DIR)/test_objs/,$(SOURCES:.cpp=.lo))


.PHONY: all clean


all: dir $(OUT)


dir: | $(BUILD_DIR)/test_objs

$(BUILD_DIR)/test_objs:
	mkdir -p $@


$(OUT): $(OBJECTS)
	libtool --mode=link --tag=CXX $(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)

$(BUILD_DIR)/test_objs/%.lo: %.cpp
	libtool --mode=compile --tag=CXX $(CXX) $(CXXFLAGS) -c $< -o $@
	
$(BUILD_DIR)/test_objs/shader.lo: shader.cpp inline_shader.hpp
	libtool --mode=compile --tag=CXX $(CXX) $(CXXFLAGS) -c $< -o $@
	
$(BUILD_DIR)/test_objs/buffer.lo: buffer.cpp test_data.hpp
	libtool --mode=compile --tag=CXX $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS) $(OUT)

