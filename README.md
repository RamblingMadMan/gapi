GAPI
====

Modern C++14 OpenGL function loader and wrapper library

About
=====

OpenGL function loader and wrapper library taking advantage of modern C++ features.

Usage
=====

To use any of the library's features you need to link against it. With GCC this is done with the
```bash
-lgapi
```
The name will be the same on all platforms, so adapt this to your own.

To use any OpenGL 4.5 function simply include `gapi/functions.hpp` and call any by their identifier within the `gapi::functions` namespace.

If you want to load an OpenGL function manually, it is done like so:

```c++
#include <gapi/gapi.hpp>

auto main() -> int{
	/* create opengl context */

	gapi::gl_function<void(gapi::GLenum)> glClear{"glClear"};
}
```

Any functions that the library already knows the name of will be checked for the correct return type and parameter types. An exception will be thrown if the wrong types are specified for the template parameters.

You can have an OpenGL function be initialized when it is called for the first time by declaring it like so:

```c++
gapi::gl_function<void()> func{deferred_init, "name"};
```
