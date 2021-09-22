cmake_minimum_required(VERSION 3.0)
project(mundy_math)

set(CMAKE_CXX_STANDARD 17)

add_library(mundy_math STATIC MundyMath.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(mundy_math_tests Google_tests/MundyMathTests.cpp)

# Link Mundy Math to Test Executable
target_link_libraries(mundy_math_tests mundy_math)
target_link_libraries(mundy_math_tests gtest gtest_main)

# Include GoogleTest CMake Commands
include(GoogleTest)

# Discover Tests for CTests to Execute
gtest_add_tests(mundy_math_tests)
