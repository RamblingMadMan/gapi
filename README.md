GAPI
====

Modern C++14 OpenGL function loader and wrapper library

About
=====

OpenGL function loader and wrapper library taking advantage of modern C++ features.

Usage
=====

To use any of the library's features you need to link against it. With GCC this is done with the `-lgapi` flag.

The name will be the same on all platforms, so adapt this to your own compiler/platform.

To use any OpenGL 4.5 function simply include `gapi/functions.hpp` and call any by their identifier within the `gapi::functions` namespace.

e.g.
```c++
#include <gapi/functions.hpp>
#include <gapi/constants.hpp>

auto main() -> int{
	// create context and make current
	
	using namespace gapi;
	using namespace gapi::functions;
	
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glClearDepthf(1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
```

The functions will be loaded upon first use and should have no overhead after the initial loading.

If you want to load an OpenGL function manually, it is done like so:

```c++
#include <gapi/gapi.hpp>

auto main() -> int{
	/* create opengl context and make it current */

	gapi::gl_function<void(gapi::GLenum)> glClear{"glClear"};
}
```

Any functions loaded through `gl_function` that the library already knows the name of will be checked for the correct return type and parameter types. An exception will be thrown if any wrong types are specified.

You can have an OpenGL function be loaded when it is called for the first time by declaring it like so:

```c++
gapi::gl_function<void()> func{deferred_init, "fn_name"};
```

If you want to retrieve the function pointer directly, it can be retrieved like so:

```c++
#include <gapi/gapi.hpp>

auto main() -> int{
	void(*glClear)() = gapi::detail::get_gl_fp("glClear");
}
```

or through the `gl_function` interface:
```c++
#include <gapi/gapi.hpp>

auto main() -> int{
	gapi::gl_function<void(GLenum)> glClear{"glClear"};
	auto fptr = glClear.get();
}
```

The `gl_function` interface will give you a function pointer with the signature specified in the template parameter.

To use any of the constants defined in the OpenGL API (e.g. `GL_COLOR_BUFFER_BIT`), you should include `gapi/constants.hpp`.

Building
========

The build process requires CMake, RapidXML and a C++ compiler with support for C++14.

The file `debian-prereq.sh` should install all dependencies on a debian-based system.

To build, invoke cmake how you normally would.

Here's an example of a release build
```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j8
```
