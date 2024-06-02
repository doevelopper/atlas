#[[
       CMakeLists.txt

               Copyright (c) 2014-2024 A.H.L

        Permission is hereby granted, free of charge, to any person obtaining
        a copy of this software and associated documentation files (the
        "Software"), to deal in the Software without restriction, including
        without limitation the rights to use, copy, modify, merge, publish,
        distribute, sublicense, and/or sell copies of the Software, and to
        permit persons to whom the Software is furnished to do so, subject to
        the following conditions:

        The above copyright notice and this permission notice shall be
        included in all copies or substantial portions of the Software.

        THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
        EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
        MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
        NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
        LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
        OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
        WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

]]

#LOG4CXX_CONFIGURATION=${HOME}/developpements/night-owl/src/main/resources/config/nightOwl.xml src/test/cpp/NightOwl.test.bin  && ls -lah  logs/
#LOG4CXX_CONFIGURATION=${HOME}/developpements/night-owl/src/test/resources/config/log4cxx.xml cmake-build-debug-clang17/src/test/cpp/NightOwl.test.bin
#LOG4CXX_CONFIGURATION=${HOME}/developpements/night-owl/src/main/resources/config/nightOwl.xml cmake-build-debug-clang17/src/main/cpp/NightOwl.main.bin

cmake_minimum_required(VERSION 3.28)

project (atlas
        VERSION 1.0.0.0
        DESCRIPTION "CPP"
        HOMEPAGE_URL "https://exemple.com"
        LANGUAGES CXX
)


list(APPEND CMAKE_MODULE_PATH
        ${CMAKE_SOURCE_DIR}/src/main/resources/cmake
        ${CMAKE_SOURCE_DIR}/src/test/resources/cmake
)

option(BUILD_SHARED_LIBS "If enabled, shared libs will be built by default, otherwise static libs" OFF)

set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)
#set(CMAKE_VERBOSE_MAKEFILE ON)


set(CMAKE_CXX_STANDARD 23)

#SET (CMAKE_C_COMPILER                       "/opt/compilers/clang+llvm/bin/clang")
#SET (CMAKE_C_FLAGS_INIT                     "-Wall -std=c17")
#SET (CMAKE_C_FLAGS_DEBUG_INIT               "-g")
#SET (CMAKE_C_FLAGS_MINSIZEREL_INIT          "-Os -DNDEBUG")
#SET (CMAKE_C_FLAGS_RELEASE_INIT             "-O3 -DNDEBUG")
#SET (CMAKE_C_FLAGS_RELWITHDEBINFO_INIT      "-O2 -g")
##
#SET (CMAKE_CXX_COMPILER                     "/opt/compilers/clang+llvm/bin/clang++")
#SET (CMAKE_CXX_FLAGS_INIT                   "-Wall -std=c++23")
#SET (CMAKE_CXX_FLAGS_DEBUG_INIT             "-g")
#SET (CMAKE_CXX_FLAGS_MINSIZEREL_INIT        "-Os -DNDEBUG")
#SET (CMAKE_CXX_FLAGS_RELEASE_INIT           "-O3 -DNDEBUG")
#SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT    "-O2 -g")
#
#SET (CMAKE_AR      "/opt/compilers/clang+llvm/bin/llvm-ar")
#SET (CMAKE_LINKER  "/opt/compilers/clang+llvm/bin/llvm-ld")
#SET (CMAKE_NM      "/opt/compilers/clang+llvm/bin/llvm-nm")
#SET (CMAKE_OBJDUMP "/opt/compilers/clang+llvm/bin/llvm-objdump")
#SET (CMAKE_RANLIB  "/opt/compilers/clang+llvm/bin/llvm-ranlib")
#
#set(CMAKE_FIND_ROOT_PATH "/opt/compilers/clang+llvm")
#set(CMAKE_SYSROOT  "/opt/compilers/clang+llvm")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_CXX_CLANG_TIDY "/opt/compilers/clang+llvm/bin/clang-tidy;-checks=*")
#set(CMAKE_CXX_CPPCHECK "/opt/cmake/bin/cppcheck;--std=c++20")
#set(CMAKE_CXX_CPPLINT "/opt/cpplint/cpplint.py;--linelength=120")

include(Dependencies)
add_subdirectory (src/main/cpp)
include(TestDependencies)
add_subdirectory (src/test/cpp)
#add_subdirectory (src/it)
