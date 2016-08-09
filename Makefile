PWD:=$(shell pwd)
SRC_DIR:=$(PWD)
BUILD_DIR?=$(PWD)/build

DESTDIR?=/usr/local

CXX:=g++-6
CXXFLAGS?=-std=c++1z -fconcepts -msse3 -I$(PWD)/include
LDFLAGS?=-rpath $(DESTDIR)/lib -L$(BUILD_DIR)
LIBS?=

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
export DESTDIR
export CXX
export CXXFLAGS
export LDFLAGS
export LIBS

.PHONY: all src test install clean clean_src clean_test

all: dir src

src:
	$(MAKE) -C src

test: src
	$(MAKE) -C test

dir: | $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $@

install:
	$(MAKE) -C src install

clean: clean_src clean_test

clean_src:
	$(MAKE) -C src clean

clean_test:
	$(MAKE) -C test clean
	
