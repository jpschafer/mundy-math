![CMake Status](https://github.com/jpschafer/mundy-math/actions/workflows/cmake.yml/badge.svg)


# Mundy Math
Reusable Arithmetic Library written in C++. For SENG 560. This library provides the following functions:

- Addition
- Subtraction
- Multiplciation
- Division
- Square Root
- Exponentiation (Power)

It also supports the following types interchangeably:

- int
- double
- binary (string based)
- octal (string based)
- hexadecimal (string based)

# Requirements
- C++17 Standards Supported Compiler
  - GCC is recommended for Unix Based Systems (Mac, Linux)
  - MinGW is recommended for Windows
- [CMake](https://cmake.org) 
- 
# How is it Reusable?
This project is made reusable in the way that it is consumed by another project. Instead of compiling the .a library and providing different versions of that. It is recommended that this project is consumed via the use of FetchContent() in a CMakeList, making it compiled with your project as a static library on demand, so it will run on any environment you are using. This also makes it easy to pull new updates as you can either just reference the main zip download off of github to always get bleeding edge updates, or you can specify a specific hash like so:

```
main branch:
https://github.com/jpschafer/mundy-math/archive/refs/heads/main.zip
specific commit:
https://github.com/jpschafer/mundy-math/archive/5ce3291703697697ebad04a63e9e461075e0511c.zip
```

Because of this, this is not semantically versioned by any means, it follows a more CI/CD style approach to getting updates, where each update is a commit itself (the commit hash is the version "number"). Any changes done on the main branch have to first pass a build before being merged, meaning main should never be in a "broken" state. 

# How is this Tested
This project uses Google Tests as its C++ unit testing framework. Tests are done on each of the functions, as well as testing done to ensure conversion between types from the Result object are correct and re-usable in another Result object. 

Google tests are auto-discovered in the CMakeLists definition for CTests to run as a part of the build and return results. This entire testing process is also managed as a CI/CD pipeline. You can check the Readme here at the top to see if the build is currently passing tests and is compileable. 

# How to Use

The MundyMath Library can be easily consumed by including it into your cpp class:

```
#include "MundyMath.h"
```

If you have folders deeper than the root of your project you may have to do the following:

```
#include "../MundyMath.h"
```

Once included you can easily start running some methods, the formats for the string types are as follows:
- binary: 0b111111(0b<binary_num>)
- octal: 0111111 (0<octal_num>)
- Hexadecimal: 0x111111 (0x<hex_num>)

See below for examples:

```
MundyMath::add("0b00010100", "0b00010100").getResult()
MundyMath::add("0xA", "0xA").getResult()
MundyMath::subtract("012", "012")
```

Note that inputted string values are converted to integers for calculation purposes and stored internally that way in the Result object (unless you directly instantiate the result and pass the string yourself), meaning .getResult() will not give you back the stringified form but the actual C++ simple integer. 

All Octal/Binary/Hexadecimal numbers assume to only represent integers, if you want to use doubles you need to directly use the C++ doubles format, the stringified versions are essentially just another way to represent C++ integers (It does seem kind of silly to be wrapping up a binary number in ASCII doesn't it?)


# Limitations/Caveats
- Exponentiation only support integer positive and minus based powers, partial powers are not supported. 
- The Square Root function will provide a floored valued for the square root of a double or integer that does not create a integer result.  
