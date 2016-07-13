OUT:=spec_parser

CXX:=g++-6
CXXFLAGS?=-std=c++1z -pthread -msse3 -Ofast -ffast-math -fexpensive-optimizations
LDFLAGS?=
LIBS?=-lpthread

SOURCES:=main.cpp

.PHONY: all $(OUT) clean

all: $(OUT)

$(OUT):
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SOURCES) -o $(OUT) $(LIBS)

clean:
	rm -f $(OUT)
