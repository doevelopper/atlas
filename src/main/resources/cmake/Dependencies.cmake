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

#include(FindRapidJSON)
#find_package(RapidJSON QUIET
#    HINTS
#        ${CMAKE_BINARY_DIR}/installs
#)
#if(NOT RapidJSON_FOUND)
    ExternalProject_Add(rapidjson
            PREFIX "vendor/tencent/rapidjson"
            GIT_REPOSITORY "https://github.com/Tencent/rapidjson.git"
            GIT_TAG f9d53419e912910fd8fa57d5705fa41425428c35
            TIMEOUT 10
            CMAKE_ARGS
                -DRAPIDJSON_BUILD_TESTS=OFF
                -DRAPIDJSON_BUILD_DOC=OFF
                -DRAPIDJSON_BUILD_EXAMPLES=OFF
                -DRAPIDJSON_BUILD_CXX17=ON
                -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/installs
                -DCMAKE_PREFIX_PATH=${CMAKE_BINARY_DIR}/installs
            #    CONFIGURE_COMMAND ""
            #    BUILD_COMMAND make
            #    INSTALL_COMMAND make install
            UPDATE_COMMAND ""
    )
#endif()
#

#if(NOT OpenSSL_FOUND)
    ExternalProject_Add(libopenssl
        PREFIX "vendor/openssl/openssl"
        URL
            https://www.openssl.org/source/openssl-1.1.1w.tar.gz
        CONFIGURE_COMMAND
            ./config no-shared no-idea no-mdc2 no-rc5 --prefix=${CMAKE_BINARY_DIR}/installs
        BUILD_COMMAND
            make
        INSTALL_COMMAND
            make install_sw
        BUILD_IN_SOURCE 1
        UPDATE_COMMAND ""
    )
#endif()

#if(NOT Boost_FOUND)
    ExternalProject_Add(Boost
        PREFIX "vendor/boostorg/Boost"
        DEPENDS
            libopenssl
        URL
            https://boostorg.jfrog.io/artifactory/main/release/1.85.0/source/boost_1_85_0.tar.gz
        CONFIGURE_COMMAND
            ./bootstrap.sh --prefix=${CMAKE_BINARY_DIR}/installs
        BUILD_COMMAND
            ./b2 clean
            ./b2 cxxstd=20 -j64 link=static address-model=64 --architecture=x64 variant=release #toolset=clang cxxflags=-fPIC cxxstd=14
        BUILD_IN_SOURCE
            true
        INSTALL_COMMAND
            ./b2 install
        INSTALL_DIR
            ${CMAKE_BINARY_DIR}/installs
        UPDATE_COMMAND ""
    )
#endif()

#find_package(absl QUIET
#    PATHS
#        ${CMAKE_BINARY_DIR}/installs
#)
#if(NOT absl_FOUND)
    ExternalProject_Add(abseilcpp
        PREFIX "vendor/abseil/abseil-cpp"
        GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
        GIT_TAG master
        GIT_PROGRESS 1
        SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/libs/abseil-cpp-src"
        BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/libs/abseil-cpp-build"
        CONFIGURE_COMMAND ${CMAKE_COMMAND} -S ${CMAKE_CURRENT_BINARY_DIR}/libs/abseil-cpp-src -B ${CMAKE_CURRENT_BINARY_DIR}/libs/abseil-cpp-build
            -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/installs -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=TRUE -DBUILD_TESTING:BOOL=OFF
            -DCMAKE_PREFIX_PATH=${CMAKE_BINARY_DIR}/installs
        BUILD_COMMAND
        COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR> --config Release --target install
        INSTALL_COMMAND ""
        TEST_COMMAND ""
        UPDATE_COMMAND ""
    )
#endif()

#find_package(crc32c QUIET
#        PATHS
#        ${CMAKE_BINARY_DIR}/installs
#)
#if(NOT crc32c_FOUND)
    ExternalProject_Add(crc32c
        PREFIX "vendor/google/crc32c"
        GIT_REPOSITORY "https://github.com/google/crc32c.git"
        GIT_TAG "21fc8ef30415a635e7351ffa0e5d5367943d4a94"
        EXCLUDE_FROM_ALL ON
        CMAKE_CACHE_ARGS
            -DCRC32C_BUILD_TESTS:BOOL=OFF
            -DBUILD_SHARED_LIBS:STRING=no
            -DCRC32C_BUILD_BENCHMARKS:BOOL=OFF
            -DCRC32C_USE_GLOG:BOOL=OFF
            -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=ON
            -DCMAKE_BUILD_TYPE:STRING=Release
            -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/installs
            -DCMAKE_PREFIX_PATH=${CMAKE_BINARY_DIR}/installs
        UPDATE_COMMAND ""
    )
#endif()

#find_package(FMT QUIET
#        PATHS
#        ${CMAKE_BINARY_DIR}/installs
#)
#if(NOT FMT_FOUND)
    ExternalProject_Add(libfmt
        PREFIX "vendor/fmtlib/fmt"
        GIT_REPOSITORY
            "https://github.com/fmtlib/fmt.git"
        GIT_TAG
            "10.1.1"
        GIT_CONFIG advice.detachedHead=false
        CMAKE_CACHE_ARGS
            "-DFMT_INSTALL:BOOL=ON"
            "-DFMT_DOC:BOOL=OFF"
            "-DFMT_TEST:BOOL=OFF"
            "-DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/dependencies"
        UPDATE_COMMAND ""
    )
#endif()

#find_package(expat QUIET
#    PATHS
#        ${CMAKE_BINARY_DIR}/installs
#)
#if(NOT expat_FOUND)
    ExternalProject_Add(libexpat
        PREFIX "vendor/libexpat/expat"
        GIT_REPOSITORY https://github.com/libexpat/libexpat.git
        GIT_TAG master
        GIT_PROGRESS 1
        SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/libs/libexpat-cpp-src"
        BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/libs/libexpat-cpp-build"
        CONFIGURE_COMMAND ${CMAKE_COMMAND} -S ${CMAKE_CURRENT_BINARY_DIR}/libs/libexpat-cpp-src/expat -B ${CMAKE_CURRENT_BINARY_DIR}/libs/libexpat-cpp-build
            -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/installs -DBUILD_SHARED_LIBS=OFF -DEXPAT_BUILD_EXAMPLES=OFF -DEXPAT_BUILD_TESTS=OFF -DEXPAT_SHARED_LIBS=OFF
            -DCMAKE_PREFIX_PATH=${CMAKE_BINARY_DIR}/installs
        BUILD_COMMAND
        COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR> --config Release --target install
        INSTALL_COMMAND ""
        TEST_COMMAND ""
        UPDATE_COMMAND ""
    )
#endif()

#find_package(apr QUIET
#    PATHS
#        ${CMAKE_BINARY_DIR}/installs
#)
#if(NOT apr_FOUND)
    ExternalProject_Add(libapr
#        DEPENDS
#            libexpat
        PREFIX "vendor/apache/apr"
        GIT_REPOSITORY https://github.com/apache/apr.git
        GIT_TAG 1.7.x
        GIT_PROGRESS 1
        BUILD_IN_SOURCE 1
        CONFIGURE_COMMAND
            ./buildconf && ./configure --enable-threads --enable-posix-shm --enable-allocator-uses-mmap --enable-allocator-guard-pages --enable-pool-concurrency-check --enable-other-child --prefix=${CMAKE_BINARY_DIR}/installs
        BUILD_COMMAND
        COMMAND make clean && make install
        INSTALL_COMMAND ""
        TEST_COMMAND ""
        UPDATE_COMMAND ""
    )
#endif()

#find_package(apr-util QUIET
#    PATHS
#        ${CMAKE_BINARY_DIR}/installs
#)
#if(NOT apr-util_FOUND)
    ExternalProject_Add(libapr-util
        DEPENDS
            libapr
        PREFIX "vendor/apache/apr-util"
        GIT_REPOSITORY https://github.com/apache/apr-util.git
        GIT_TAG 1.7.x
        GIT_PROGRESS 1
        BUILD_IN_SOURCE 1
        CONFIGURE_COMMAND
            ./buildconf --with-apr=${CMAKE_BINARY_DIR}/vendor/apache/apr/src/libapr --prefix=${CMAKE_BINARY_DIR}/installs &&  ./configure --prefix=${CMAKE_BINARY_DIR}/installs --with-apr=${CMAKE_BINARY_DIR}/installs --with-openssl=${CMAKE_BINARY_DIR}/installs --with-expat=${CMAKE_BINARY_DIR}/installs
        UPDATE_COMMAND ""
    )
#endif()

#find_package(log4cxx QUIET
#    PATHS
#        ${CMAKE_BINARY_DIR}/installs
#)
#if(NOT log4cxx_FOUND)
    ExternalProject_Add(liblog4cxx
        PREFIX "vendor/apache/log4cxx"
#        DEPENDS
#            libfmt
#            libapr-util
#            Boost
        GIT_REPOSITORY
            https://github.com/apache/logging-log4cxx.git
        GIT_TAG
            master
#            rel/v1.1.0
        BUILD_IN_SOURCE
            TRUE
        CMAKE_ARGS
            -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/installs -DBUILD_TESTING=off -DBUILD_SHARED_LIBS=off -DAPU_STATIC=yes -DAPR_STATIC=yes -DCMAKE_PREFIX_PATH=${CMAKE_BINARY_DIR}/installs
        BUILD_COMMAND
            cmake --build . --target install --config Release
        INSTALL_COMMAND ""
        UPDATE_COMMAND ""
    )
#endif()

#find_package(xerces-c QUIET
#    PATHS
#        ${CMAKE_BINARY_DIR}/installs
#)
#if(NOT xerces-c_FOUND)
    ExternalProject_Add(libxerces
        PREFIX "vendor/apache/xerces-c"
        GIT_REPOSITORY https://github.com/apache/xerces-c.git
        GIT_TAG master
        GIT_PROGRESS 1
        BUILD_IN_SOURCE 1
        CONFIGURE_COMMAND
            ./reconf && ./configure --prefix=${CMAKE_BINARY_DIR}/installs/
        UPDATE_COMMAND ""
    )
#endif()


#find_package(benchmark QUIET
#    PATHS
#        ${CMAKE_BINARY_DIR}/installs
#)
#if(NOT benchmark_FOUND)
#endif()
#

##ExternalProject_Add(curl
##    URL
##        "https://github.com/curl/curl/releases/download/curl-8_4_0/curl-8.4.0.tar.gz"
###        URL_MD5 "45f468aa42c4af027c4c6ddba58267f0" # md5sum curl_7.74.0.tar.gz
##    BUILD_IN_SOURCE
##        1
###    SOURCE_DIR
###        ${CMAKE_BINARY_DIR}/curl
###    CONFIGURE_COMMAND
###        ${CMAKE_BINARY_DIR}/curl/configure --prefix=${CMAKE_BINARY_DIR}/dependencies
##    CONFIGURE_COMMAND
##        ./configure --prefix=${CMAKE_BINARY_DIR}/dependencies --with-openssl
##    BUILD_COMMAND
##        make
##    INSTALL_COMMAND
##        make install
##)
##
