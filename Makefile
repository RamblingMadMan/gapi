PWD:=$(shell pwd)
SRC_DIR:=$(PWD)
BUILD_DIR?=$(PWD)/build

DESTDIR?=/usr/local

CXX:=g++
CXXFLAGS?=-std=c++1z -msse3 -I$(SRC_DIR)/include
LDFLAGS?=-rpath $(DESTDIR)/lib -L$(BUILD_DIR)
LIBS?=

USE_EGL?=false

ifneq ($(USE_EGL),false)
ifneq ($(USE_EGL),true)
$(error invalid value for USE_EGL)
else
CXXFLAGS:=$(CXXFLAGS) -DGAPI_EGL
endif
endif

GL_LIB:=

ifeq ($(OS),Windows_NT)
GL_LIB:=-lopengl32
else

endif

OPTFLAGS_DEBUG?=-Og -ggdb
OPTFLAGS_RELEASE?=-Ofast -fexpensive-optimizations -DNDEBUG

BUILD_TYPE?=debug

ifeq ($(BUILD_TYPE),debug)
BUILD_DIR:=$(BUILD_DIR)/debug
CXXFLAGS:=$(CXXFLAGS) $(OPTFLAGS_DEBUG)
else
ifeq ($(BUILD_TYPE),release)
BUILD_DIR:=$(BUILD_DIR)/release
CXXFLAGS:=$(CXXFLAGS) $(OPTFLAGS_RELEASE)
else
$(error bad BUILD_TYPE $(BUILD_TYPE). valid options are debug and release)
endif
endif

export SRC_DIR
export BUILD_DIR
export USE_EGL
export DESTDIR
export CXX
export CXXFLAGS
export LDFLAGS
export LIBS


DEPS:=$(SRC_DIR)/src/functions.cpp

HEADERS:=functions.hpp constants.hpp known.hpp

IMPL_DEPS:=\
	$(SRC_DIR)/spec_parser/functions.cpp\
	$(addprefix $(SRC_DIR)/include/gapi/,$(HEADERS))\
	$(addprefix $(SRC_DIR)/spec_parser/,$(HEADERS))

.PHONY: all headers src test install clean clean_src clean_test

all: dir headers src

headers: $(DEPS)

src: headers
	$(MAKE) -C src

test: src
	$(MAKE) -C test

dir: | $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $@


$(SRC_DIR)/src/functions.cpp: $(SRC_DIR)/spec_parser/functions.hpp
	cd $(SRC_DIR)/spec_parser;\
	./replace.sh

$(SRC_DIR)/spec_parser/functions.hpp: $(SRC_DIR)/spec_parser/spec_parser
	cd $(SRC_DIR)/spec_parser;\
	./spec_parser

$(SRC_DIR)/spec_parser/spec_parser:
	cd $(SRC_DIR)/spec_parser;\
	./compile.sh


install:
	$(MAKE) -C src install

clean: clean_src clean_test
	rm -rf $(DEPS)
	rm -rf $(IMPL_DEPS)
	rm -f $(SRC_DIR)/spec_parser/spec_parser

clean_src:
	$(MAKE) -C src clean

clean_test:
	$(MAKE) -C test clean
	
