OUT:=$(BUILD_DIR)/libgapi.la

SOURCES:=context.cpp
OBJECTS:=$(addprefix $(BUILD_DIR)/objs/,$(SOURCES:.cpp=.lo))

.PHONY: all clean

all: dir $(OUT)

dir: | $(BUILD_DIR)/objs

$(BUILD_DIR)/objs:
	mkdir -p $@

$(OUT): $(OBJECTS)
	libtool --mode=link --tag=CXX $(CXX) $(LDFLAGS) -o $(OUT) $(OBJECTS) $(LIBS)

$(BUILD_DIR)/objs/%.lo: %.cpp
	libtool --mode=compile --tag=CXX $(CXX) -fPIC $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OUT) $(OBJECTS)
