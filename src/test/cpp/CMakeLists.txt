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

find_package(GTest QUIET
    PATHS
        ${CMAKE_BINARY_DIR}/installs
)
find_package(GMock QUIET
    PATHS
        ${CMAKE_BINARY_DIR}/installs
)

add_library(${PROJECT_NAME}.test
        main.cpp
        com/github/doevelopper/atlas/utdriver/TestDriver.cpp
        com/github/doevelopper/atlas/utdriver/TestDriver.hpp
        com/github/doevelopper/atlas/utdriver/TestEventListener.cpp
        com/github/doevelopper/atlas/utdriver/TestEventListener.hpp
        com/github/doevelopper/atlas/utdriver/TestEventListenerConfigure.cpp
        com/github/doevelopper/atlas/utdriver/TestEventListenerConfigure.hpp
        com/github/doevelopper/atlas/utdriver/CustomTestEnvironment.cpp
        com/github/doevelopper/atlas/utdriver/CustomTestEnvironment.hpp
)

target_include_directories(${PROJECT_NAME}.test
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/com/github/doevelopper/atlas>
        $<INSTALL_INTERFACE:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/com/github/doevelopper/atlas>
        INTERFACE_POSITION_INDEPENDENT_CODE ON
)

target_link_libraries(${PROJECT_NAME}.test
    PUBLIC
        ${PROJECT_NAME}.main
        GTest::gtest
        GTest::gmock # ????
)

#-----------------------------------------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------------------------------------
#
#                                 EXECUTABLES
#
#-----------------------------------------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------------------------------------

add_executable (
    ${PROJECT_NAME}.test.bin
#        com/github/doevelopper/atlas/semver/VersionTest.hpp
#        com/github/doevelopper/atlas/semver/VersionTest.cpp
#        com/github/doevelopper/atlas/storage/BasePtrTest.cpp
#        com/github/doevelopper/atlas/storage/BasePtrTest.hpp
#        com/github/doevelopper/atlas/storage/CircularBufferTest.cpp
#        com/github/doevelopper/atlas/storage/CircularBufferTest.hpp
#        com/github/doevelopper/atlas/utils/ShellHandleTest.cpp
#        com/github/doevelopper/atlas/utils/ShellHandleTest.hpp
#        com/github/doevelopper/atlas/utils/FileSystemHandleTest.cpp
#        com/github/doevelopper/atlas/utils/FileSystemHandleTest.hpp
#        com/github/doevelopper/atlas/utils/SingletonTest.cpp
#        com/github/doevelopper/atlas/utils/SingletonTest.hpp
#        com/github/doevelopper/atlas/utils/TimeFixtureTest.cpp
#        com/github/doevelopper/atlas/utils/TimeFixtureTest.hpp
#        com/github/doevelopper/atlas/events/obs/SubjectTest.cpp
#        com/github/doevelopper/atlas/events/obs/SubjectTest.hpp
        com/github/doevelopper/atlas/events/pub/PublisherTest.cpp
        com/github/doevelopper/atlas/events/pub/PublisherTest.hpp
        com/github/doevelopper/atlas/events/pub/SubscriberTest.cpp
        com/github/doevelopper/atlas/events/pub/SubscriberTest.hpp
)

target_link_libraries(
    ${PROJECT_NAME}.test.bin
    PUBLIC
        ${PROJECT_NAME}.test
#    PRIVATE
#        googletest
)
