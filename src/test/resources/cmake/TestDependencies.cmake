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

include(ExternalProject)

#if(NOT GTest_FOUND OR NOT GMock_FOUND)
    ExternalProject_Add(googletest
        PREFIX "vendor/google/googletest"
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
        GIT_PROGRESS 1
        CMAKE_ARGS
            -DCMAKE_BUILD_TYPE:STRING=Release
            -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/installs
            $<$<PLATFORM_ID:Windows>:-Dgtest_force_shared_crt:BOOL=ON>
        SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/libs/gtest-src"
        BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/libs/gtest-build"
        CONFIGURE_COMMAND ${CMAKE_COMMAND} -S ${CMAKE_CURRENT_BINARY_DIR}/libs/gtest-src -B ${CMAKE_CURRENT_BINARY_DIR}/libs/gtest-build
            -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/installs -DCMAKE_PREFIX_PATH=${CMAKE_BINARY_DIR}/installs
        BUILD_COMMAND ""
        COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR> --config Release --target install
            #        COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR> --config Debug --target install
        INSTALL_COMMAND ""
        TEST_COMMAND ""
        LOG_CONFIGURE ON
        LOG_BUILD ON
        LOG_INSTALL ON
        UPDATE_COMMAND ""
    )
#endif()

#find_package(benchmark QUIET
#        PATHS
#        ${CMAKE_BINARY_DIR}/installs
#)
#if(NOT benchmark_FOUND)
    ExternalProject_Add(benchmark
        PREFIX "vendor/google/benchmark"
        GIT_REPOSITORY  https://github.com/google/benchmark.git
        GIT_TAG main
        GIT_PROGRESS 1
        SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/libs/benchmark-src"
        BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/libs/benchmark-build"
        CONFIGURE_COMMAND ${CMAKE_COMMAND} -S ${CMAKE_CURRENT_BINARY_DIR}/libs/benchmark-src -B ${CMAKE_CURRENT_BINARY_DIR}/libs/benchmark-build
            -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/installs
            -DBENCHMARK_ENABLE_GTEST_TESTS=OFF -DCMAKE_PREFIX_PATH=${CMAKE_BINARY_DIR}/installs
        BUILD_COMMAND
        COMMAND  ${CMAKE_COMMAND} --build ${CMAKE_CURRENT_BINARY_DIR}/libs/benchmark-build --target install --config Release
        INSTALL_COMMAND ""
        TEST_COMMAND ""
        UPDATE_COMMAND ""
    )
#endif()
