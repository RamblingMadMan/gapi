PWD:=$(shell pwd)
SRC_DIR:=$(PWD)
BUILD_DIR?=$(PWD)/build

DESTDIR?=/usr/local

CXX:=g++-6
CXXFLAGS?=-std=c++1z -fconcepts -msse3 -I$(PWD)/include
LDFLAGS?=-rpath $(DESTDIR)/lib -version-info 1:0:1
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

.PHONY: all src install clean

all: dir src

src:
	$(MAKE) -C src

dir: | $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $@

install:
	$(MAKE) -C src install

clean:
	$(MAKE) -C src clean
