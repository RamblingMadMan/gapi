GAPI
====

Modern C++17 OpenGL function loader and wrapper library

About
=====

OpenGL function loader and wrapper library taking advantage of modern C++ features.

Usage
=====

To use any of the library's features you need to link against it. With GCC this is done with the `-lgapi` flag.

The name will be the same on all platforms, so adapt this to your own compiler/platform.

To use any OpenGL 4.5 function simply include `gapi/functions.hpp` and call any by their identifier within the `gapi::functions` namespace.

If you want to load an OpenGL function manually, it is done like so:

```c++
#include <gapi/gapi.hpp>

auto main() -> int{
	/* create opengl context and make it current */

	gapi::gl_function<void(gapi::GLenum)> glClear{"glClear"};
}
```

or if you want to retrieve the function pointer directly, it can be retrieved like so:

```c++
auto main() -> int{
	void(*glClear)() = gapi::detail::get_gl_fp("glClear");
}
```

Any functions loaded through `gl_function` that the library already knows the name of will be checked for the correct return type and parameter types. An exception will be thrown if the wrong types are specified for the template parameters.

You can have an OpenGL function be initialized when it is called for the first time by declaring it like so:

```c++
gapi::gl_function<void()> func{deferred_init, "name"};
```

Building
========

The build process requires boost-system and a C++ compiler with support for C++17. More specifically, inline variables and fold expressions.

GCC version 6.x is the best bet and most future proof for future commits, but 5.x should work.

To install GCC 6 in Ubuntu 16.04 run the following commands:
```bash
sudo apt-add-repository ppa:ubuntu-toolchain-r/test
sudo apt update && sudo apt install g++-6
```

For linking libtool is also required.

To install libtool on ubuntu run the following command:
```bash
sudo apt install libtool-bin
```

To build simply run `make` from the root source directory.

The library will be built into BUILD_DIR, then within that directory either debug or release.

possible flags that can be set at build time are

##`BUILD_DIR`
The directory that the library will be built into

default: `$(SRC_DIR)/build`

##`BUILD_TYPE`
The type of build to be made

##`OPTFLAGS_DEBUG`
Compiler flags for debug builds

default: `-O2 -g`

##`OPTFLAGS_RELEASE`
Compiler flags for release builds

default: `-O3 -ffast-math -fexpensive-optimizations`

##`CXXFLAGS`
Generic compiler flags

NOTE these flags should rarely be set

default: `-std=c++1z -msse3`

##`LDFLAGS`
libtool linker flags

default: `-rpath $(DESTDIR)`

##`LIBS`
Libraries to be passed to the linker

default: `[EMPTY]`

Installation
============

To install run the following in the source dir:
```bash
make install
```

If you don't specify DESTDIR to something custom then you will need to run `make install` with superuser privilages.
