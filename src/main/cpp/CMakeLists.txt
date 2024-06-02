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


find_package(expat REQUIRED)
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost QUIET
        COMPONENTS
        context
        filesystem
        program_options
        exception
        coroutine
        PATHS
            ${CMAKE_BINARY_DIR}/installs
)

if (Boost_FOUND)

    if (QUANTUM_BOOST_USE_SEGMENTED_STACKS)
        add_definitions(-D__QUANTUM_BOOST_USE_SEGMENTED_STACKS)
    elseif (QUANTUM_BOOST_USE_PROTECTED_STACKS)
        add_definitions(-D__QUANTUM_BOOST_USE_PROTECTED_STACKS)
    elseif (QUANTUM_BOOST_USE_FIXEDSIZE_STACKS)
        add_definitions(-D__QUANTUM_BOOST_USE_FIXEDSIZE_STACKS)
    endif()

    if (QUANTUM_BOOST_USE_VALGRIND)
        add_definitions(-DBOOST_USE_VALGRIND)
    endif()

    set(Boost_USE_STATIC_LIBS ${QUANTUM_BOOST_STATIC_LIBS})
    set(Boost_USE_MULTITHREADED ${QUANTUM_BOOST_USE_MULTITHREADED})
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})

    if (QUANTUM_VERBOSE_MAKEFILE)
        message(STATUS "Boost include dir: ${Boost_INCLUDE_DIRS}")
        message(STATUS "Boost library dir: ${Boost_LIBRARY_DIRS}")
        message(STATUS "Boost use static libs: ${Boost_USE_STATIC_LIBS}")
        message(STATUS "Boost is multi-threaded: ${Boost_USE_MULTITHREADED}")
        message(STATUS "Boost libraries: ${Boost_LIBRARIES}")
    endif()

else()
    message(FATAL_ERROR "Boost not found, please define BOOST_ROOT.")
endif()


find_package(log4cxx REQUIRED
        PATHS
        ${CMAKE_BINARY_DIR}/installs
)


add_library(
    ${PROJECT_NAME}.main
        com/github/doevelopper/atlas/launcher/Application.cpp
        com/github/doevelopper/atlas/launcher/Application.hpp
        com/github/doevelopper/atlas/logging/CustomLogger.cpp
        com/github/doevelopper/atlas/logging/CustomLogger.hpp
        com/github/doevelopper/atlas/CompilerDetection.hpp
        com/github/doevelopper/atlas/API_Export.hpp
        com/github/doevelopper/atlas/logging/CustomLoggerPrivate.cpp
        com/github/doevelopper/atlas/logging/CustomLoggerPrivate.hpp
        com/github/doevelopper/atlas/launcher/ApplicationPrivate.cpp
        com/github/doevelopper/atlas/launcher/ApplicationPrivate.hpp
        com/github/doevelopper/atlas/semver/Version.hpp
        com/github/doevelopper/atlas/semver/Version.cpp
        com/github/doevelopper/atlas/storage/BasePtr.cpp
        com/github/doevelopper/atlas/storage/BasePtr.hpp
        com/github/doevelopper/atlas/storage/CircularBuffer.cpp
        com/github/doevelopper/atlas/storage/CircularBuffer.hpp
        com/github/doevelopper/atlas/utils/ShellHandle.cpp
        com/github/doevelopper/atlas/utils/ShellHandle.hpp
        com/github/doevelopper/atlas/utils/FileSystemHandle.cpp
        com/github/doevelopper/atlas/utils/FileSystemHandle.hpp
)

target_compile_features(${PROJECT_NAME}.main
    PUBLIC
        cxx_std_20
    PRIVATE
        $<$<CXX_COMPILER_ID:GNU>:cxx_attributes>
)

target_compile_definitions(${PROJECT_NAME}.main
    PRIVATE
        "VERBOSITY=$<IF:$<BOOL:${VERBOSE}>,30,10>"
        "LOG_LEVEL=$<IF:$<BOOL:${LOG_LEVEL}>,true,false>"
        $<$<OR:$<CONFIG:Release>,$<CONFIG:Debug>>: -DRELEASE_LEVEL="SNAPSHOOT"> # SNAPSHOOT ,ALPHA , BETA , CANDIDATE , FINAL.
        $<$<CXX_COMPILER_ID:GNU>: NOMINMAX>
        # -D_GLIBCXX_SANITIZE_VECTOR
        #QNX POSIX XENOMAI PREEMPT_RT
        #        $<IF:QUANTUM_BOOST_USE_SEGMENTED_STACKS,-D__QUANTUM_BOOST_USE_SEGMENTED_STACKS,
        #        $<IF:QUANTUM_BOOST_USE_PROTECTED_STACKS,-D__QUANTUM_BOOST_USE_PROTECTED_STACKS,
        #        $<IF:QUANTUM_BOOST_USE_FIXEDSIZE_STACKS,-D__QUANTUM_BOOST_USE_FIXEDSIZE_STACKS,-D__NONE>>>
        #        $<IF:QUANTUM_BOOST_USE_FIXEDSIZE_STACKS,-D__QUANTUM_BOOST_USE_FIXEDSIZE_STACKS,-D__NONE>
)

target_compile_options(${PROJECT_NAME}.main
    INTERFACE
        $<$<CXX_COMPILER_ID:GNU>:-Wno-long-long>
        $<$<CXX_COMPILER_ID:GNU>:-Wno-literal-suffix>
        $<$<CXX_COMPILER_ID:Clang>:-Wno-long-long>
        $<$<CONFIG:Debug>:-g3 -O0 -fstack-protector>
        $<$<CONFIG:Release>:-g0 -O2>
    PUBLIC
        #        $<$<BOOL:${LOG_LEVEL}>:LOG_LEVEL $<$<CONFIG:Debug>:_DEBUG>>
        $<$<CXX_COMPILER_ID:GNU>:-fdiagnostics-color=always>
        $<$<CXX_COMPILER_ID:Clang>:-fcolor-diagnostics>
        $<$<CXX_COMPILER_ID:GNU>: -fmax-errors=5>
        $<$<CXX_COMPILER_ID:Clang,AppleClang>: -ferror-limit=5 -fdeclspec -Wno-empty-body >
        $<IF:$<COMPILE_LANGUAGE:CXX>,-Wold-style-cast,>

        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -W -Wextra -Weffc++ -Wall -pedantic-errors -Wconversion -Wsign-conversion>

        #        $<$<COMPILE_LANGUAGE:CXX>:
        #            -Werror=reorder
        ##            -Werror=non-virtual-dtor
        ##            -Werror=array-bounds
        ##            -Werror=implicit-function-declaration
        ##            -Werror=incompatible-pointer-types
        ##            -Werror=int-conversion
        ##            -Werror=int-to-pointer-cast
        ##            -Werror=logical-op
        ##            -Werror=sizeof-pointer-div
        ##            -Werror=shadow
        ##            -Werror=sign-compare
        ##            -Werror=undef
        ##            -Werror=unused-result
        ##            -Werror=switch-default
        ##            -Werror=format-security
        ##            -Werror=address
        ##            -Werror=sequence-point
        ##            -Werror=missing-field-initializers
        ##            -Werror=aggressive-loop-optimizations
        ##            -Werror=implicit-function-declaration
        ##            -Wunused-value
        ##            -Wuninitialized
        #            -fmax-errors=1
        ###            -Werror=return-type
        ##            -fstack-usage
        ###            -Wstack-usage=
        ##            -fshort-enums
        ##            -Wsuggest-attribute=format
        ##            -Wsuggest-final-types
        ##            -Wsuggest-final-methods
        ##            -Wsuggest-override
        ##            -Wnoexcept
        ##            -Wnon-virtual-dtor
        ##            -Wctor-dtor-privacy
        ##            -Wredundant-decls
        ##            -Wextra-semi
        ##            -Wredundant-decls
        ##            -Wimplicit-fallthrough=5
        ##            -Wnull-dereference
        ##            -Wduplicated-cond
        ##            -Wduplicated-branches
        ##            -Wstrict-null-sentinel
        ##            -Wzero-as-null-pointer-constant
        #            -Wundef>
        #
        #        $<$<CXX_COMPILER_ID:Clang>:
        #            -Weverything
        #            -Wno-deprecated # gtest
        #            -Wno-deprecated-declarations  # gtest: fopen, strncpy, chdir, ...
        #            -Wno-language-extension-token
        #            -Wno-missing-noreturn
        #            -Wno-shift-sign-overflow
        #            -Wno-undef
        #            -Wno-unused-parameter>
        #
        #        $<$<CXX_COMPILER_ID:Clang>:
        #            -Weverything
        #            -Wpedantic -pedantic-errors
        #            -fstrict-aliasing
        #            -Wno-c++98-compat
        #            -Wno-c++98-compat-pedantic
        #            -Wno-c++98-compat-bind-to-temporary-copy
        #            -Wno-c++98-compat-local-type-template-args>
        #
        #        $<$<CXX_COMPILER_ID:GNU>:
        #            -Wall -Wextra -Wpedantic
        #            -pedantic-errors
        #            -fstrict-aliasing
        #            -Wconversion -Wsign-conversion
        #            -Wold-style-cast -Wfloat-equal
        #            -Wlogical-op -Wundef
        ##            -Wshadow
        #            -Wwrite-strings
        #            -Wpointer-arith -Wcast-qual
        #            -Wformat=2 -Wswitch-default
        #            -Wmissing-include-dirs -Wcast-align
        #            -Wswitch-enum  -Wdisabled-optimization
        #            -Winvalid-pch
        #            -Wmissing-declarations -Woverloaded-virtual
        #            $<$<NOT:$<VERSION_LESS:CXX_COMPILER_VERSION,5.0>>:
        #            -Wdouble-promotion -Wtrampolines
        #            -Wuseless-cast -Wvector-operation-performance>
        #            $<$<NOT:$<VERSION_LESS:CXX_COMPILER_VERSION,6.0>>:
        #            -Wshift-overflow=2 >
        #            $<$<NOT:$<VERSION_LESS:CXX_COMPILER_VERSION,7.0>>:
        #            -Walloc-zero -Walloca>
        #            $<$<NOT:$<VERSION_LESS:CXX_COMPILER_VERSION,8.0>>:
        #            -Wcast-align=strict>>
        #        $<$<CONFIG:Release>:${MY_RELEASE_OPTIONS}>
        #        $<$<CONFIG:Release>:-ffunction-sections>
        #        $<$<CONFIG:Release>:-fdata-sections>
        #        $<$<CONFIG:Release>:-Wl,--gc-sections>
        #
        #        $<$<CONFIG:Debug>:${MY_DEBUG_OPTIONS}>
        #        $<$<CONFIG:Debug>:-O0>
        #        $<$<CONFIG:Debug>:-ggdb>
        #        $<$<CONFIG:Debug>: -O0 -g -D_DEBUG -D_FORTIFY_SOURCE=2 -fno-strict-aliasing -fno-omit-frame-pointer>
        #
        #        $<$<CONFIG:Release>:API_DECLS>
        #        $<$<CONFIG:Release>:LOG4CXX_STATIC>
        #        $<$<CONFIG:Release>:APR_DECLARE_STATIC>
        #        $<$<OR:$<CONFIG:Release>,$<CONFIG:PROF>>:DISABLE_VAR>
        #
        #        $<$<COMPILE_LANGUAGE:CXX>:-DNDEBUG -O3 -pipe -Wpedantic>
        #        $<$<COMPILE_LANGUAGE:CXX>:-fmax-errors=5 -Werror=shadow -fdiagnostics-parseable-fixits>
        #        $<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor -Woverloaded-virtual -Wuseless-cast -Wlogical-op -Wduplicated-branches>
        #
        #        $<$<CONFIG:Coverage>:-O0  -fprofile-arcs -ftest-coverage --coverage>
        #        $<$<CONFIG:Profile>:-fsanitize=memory -fsanitize-memory-track-origins=2 -fno-omit-frame-pointer -fsanitize=null>
        #        $<$<CONFIG:Profile>:-fsanitize=unreachable -fstack-check -fvtable-verify=std>
        ##        $<IF:$<CONFIG:Debug>: helper_debug.cpp,helper_release.cpp>
        #        $<$<OR:$<CONFIG:Release>,$<CONFIG:Profile>>: DISABLE_VAR>
        #        $<$<CONFIG:Coverage>: -O0  ${CPP_COVERAGE_FLAGS}>
        #        $<$<CONFIG:Profile>: ${CHECK_MEMORY_FLAGS}>
)

target_include_directories(${PROJECT_NAME}.main
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
        $<TARGET_PROPERTY:log4cxx,INTERFACE_INCLUDE_DIRECTORIES>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/com/github/doevelopper/atlas>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/com/github/doevelopper/atlas>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        $<INSTALL_INTERFACE:include/com/github/doevelopper/atlas>

        #        $<BUILD_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/com/github/doevelopper/night/owl>
        #        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/com/github/doevelopper/night/owl>
        #        $<INSTALL_INTERFACE:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/com/github/doevelopper/night/owl>
        #        $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>
        #        $<INSTALL_INTERFACE:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/com/github/doevelopper/night/owl>
        #    INTERFACE
        #        $<BUILD_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/com/github/doevelopper/night/owl>
        #        $<INSTALL_INTERFACE:include>

    SYSTEM
    PUBLIC
        ${CMAKE_INSTALL_INCLUDEDIR}
        ${CMAKE_INSTALL_INCLUDEDIR}/com/github/doevelopper/atlas
)

target_link_libraries(${PROJECT_NAME}.main
        PUBLIC
        ${Boost_LIBRARIES}
        Boost::context
        Boost::exception
        Boost::filesystem
        Boost::program_options
        Threads::Threads #${CMAKE_THREAD_LIBS_INIT}
        $<$<PLATFORM_ID:Linux>:rt>
        $<$<PLATFORM_ID:Linux>:pthread>
        OpenSSL::Crypto
        OpenSSL::SSL

        #        $<$<PLATFORM_ID:Linux>:log4cxx>
        $<$<CONFIG:Coverage>:${CPP_COVERAGE_FLAGS}>
        #        $<$<OR:$<CXX_COMPILER_ID:Clang>, $<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:${BLD_FLAGS}>
        #    STATIC
        #        fmt::fmt
        INTERFACE
        ${CMAKE_BINARY_DIR}/installs/lib/liblog4cxx.a
        ${CMAKE_BINARY_DIR}/installs/lib/libaprutil-1.a
        ${CMAKE_BINARY_DIR}/installs/lib/libexpat.a#EXPAT::EXPAT #
        ${CMAKE_BINARY_DIR}/installs/lib/libapr-1.a
)

set_target_properties( ${PROJECT_NAME}.main
        PROPERTIES
        #    LINK_FLAGS
        #        -m64
        VERSION
        ${PROJECT_VERSION}
        SOVERSION
        "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
)

#-----------------------------------------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------------------------------------
#
#                                 EXECUTABLES
#
#-----------------------------------------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------------------------------------

add_executable(
    ${PROJECT_NAME}.main.bin
        main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}.main.bin
    PUBLIC
        ${PROJECT_NAME}.main
)
