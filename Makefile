PWD:=$(shell pwd)
BUILD_DIR?=$(PWD)/build

CXX:=g++-6
CXXFLAGS?=-std=c++1z -fconcepts -msse3 -I$(PWD)/include
LDFLAGS?=-rpath /usr/local/lib -version-info 1:0:1
LIBS?=

OPTFLAGS_DEBUG?=-O2 -g
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

export BUILD_DIR
export CXX
export CXXFLAGS
export LDFLAGS
export LIBS

.PHONY: all src clean

all: dir src

src:
	$(MAKE) -C src

dir: | $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C src clean
