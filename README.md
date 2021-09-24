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

If you want to see a project that uses this library, go to:
[https://github.com/jpschafer/fluffy-succotash](https://github.com/jpschafer/fluffy-succotash)

Otherwise, read below on how to use.

First you need to add the following to your CMakeLists to include the project:
```
# Fetch the Repository
include(FetchContent)
FetchContent_Declare(
        mundy_math
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/jpschafer/mundy-math/archive/refs/heads/main.zip
)

# Make Repository Available to CMake
FetchContent_MakeAvailable(mundy_math)

# Now simply link against  as needed. Eg
add_executable(<your_app_name> main.cpp)

# Link Mundy Math to Executable
target_link_libraries(<your_app_name> mundy_math_lib)
target_include_directories(fluffy_succotash_app PUBLIC ${mundy_math_SOURCE_DIR})
```

The MundyMath Library can then be easily consumed by including it into your cpp class:

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

## Basic Operations

Basic Operations can be done interchangeably on all type combinations of what are supported:

```
MundyMath::add("0b00010100", "0b00010100");
MundyMath::add("0xA", "0xA");
MundyMath::subtract("012", "012");
MundyMath::multiply(5, 5);
MundyMath::divide(5, 5);
```

## Square Root

Square Root function will return the square root of the given integer or double. Results are floored to the nearest integer:

```
MundyMath::squareRoot(49)
```

## Exponentiation

The power function will bring a number to the power given, including negatives, both ints and doubles are supported, if a negative power is used that creates a decimal number (eg. 0.5) then that number will be floored if the input value was an integer, however the double representing the decimal value will be given if a double is used (Depending on how large, you will run the risk of losing accuracy with doubles). 

All Methods return a "Result" Object back, which provides the following methods:
- getResult() - Returns the Result in its internally stored format back (string formats are converted internally to integer)
- getBinary() - Returns the Result in a Binary String
- getOctal() - Returns the Result in an Octal String
- getHexadecimal() - Returns the Result in a Hexadecimal String

You can either store the reference to the object or chain calls to the various output formats like so. 
```
Result result = MundyMath::add(12, 12);
int myInt = MundyMath::add(12, 12).getResult();
```

Note that inputted string values are converted to integers for calculation purposes and stored internally that way in the Result object (unless you directly instantiate the result and pass the string yourself), meaning .getResult() will not give you back the stringified form but the actual C++ simple integer. 

All Octal/Binary/Hexadecimal numbers assume to only represent integers, if you want to use doubles you need to directly use the C++ doubles format, the stringified versions are essentially just another way to represent C++ integers (It does seem kind of silly to be wrapping up a binary number in ASCII doesn't it?)


# Limitations/Caveats
- Exponentiation only support integer positive and minus based powers, partial powers are not supported. 
- The Square Root function will provide a floored valued for the square root of a double or integer that does not create a integer result.  
- Two's Complement is not actively supported due to issues with C++ implementations not guaranteeing it (it's not required by the C++ standard), do not try to use two's complement representation of numbers for conversion, always provide a minus sign with your number, otherwise you may get unexpected results. for example instead of 0xffffff83 please use -07xd

# Design Limitations


- Templates, unfortunately when trying to support a myriad of output formats, like most OO based languages, it's not possible to overload based on the output type, so defining a third template for the output value doesn't work as you can't determine the code at compile time based on the run-time return of a math operation, causing me to have to permutate out all the possible combinations and specifying what I expect the output format to be based on precision. One way this could have been resolved is by enforcing precision to be based on one of the operands, however that is very implementation specific and not ideal in any scenario. It makes me wonder when operands are implemented in compilers, what code they had to write to determine precision conversion without writing out every case. I was able to make input combinations possible with templates, just not output combinations based on assumptions. I possibly could have wrapped my work into a struct, but I am not sure if that would have just added complexity. 

- Basically without the above resolved, if we wish to add more non-string types, it can potentially get hopelessly complicated, part of this issue is due to my very new familiarity with C++, it has a lot of the same C constructs I am familiar with, but I am wholly new to its OO paradigm. It would almost make sense to make a sort of "BigDecimal" type that guarantees precision that is internally stored, and then request the format that we want from the result Object, that would let me take advantage of this, but I am not aware of a BigDecimal implementation with the time constraints involved for the project. 


