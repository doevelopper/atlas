/*******************************************************************
* @file
 * @version  v0.0.
 * @date     2024/04/18 W 09:55:59
 * @brief    Test Driver
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2023 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_UTDRIVER_TESTDRIVER_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_UTDRIVER_TESTDRIVER_HPP

#include <gtest/gtest.h>
#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>


#define TEST_PV(testsuite, testname, ...)                                                                              \
    class testsuite##Parameterized : public testsuite,                                                                 \
    public ::testing::WithParamInterface<decltype(GTEST_GET_FIRST_(__VA_ARGS__))>                                      \
    {                                                                                                                  \
    };                                                                                                                 \
    INSTANTIATE_TEST_SUITE_P(, testsuite##Parameterized, ::testing::Values(__VA_ARGS__));                              \
    TEST_P(testsuite##Parameterized, testname)

#define ASSERT_ARRAY_NEAR(E, A, N, eps)                                                                                \
    for (size_t i = 0; i < static_cast<unsigned>(N); i++)                                                              \
        ASSERT_NEAR((E)[i], (A)[i], (eps));

#define ASSERT_ARRAY_EQ(E, A, N)                                                                                       \
    for (size_t i = 0; i < static_cast<unsigned>(N); i++)                                                              \
        ASSERT_EQ((E)[i], (A)[i]);

namespace com::github::doevelopper::atlas::utdriver::test
{
    class TestDriver
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        Q_DISABLE_COPY_MOVE(TestDriver)
    public:
        TestDriver() noexcept;
        virtual ~TestDriver() noexcept;

        TestDriver(std::string &suite, unsigned int iteration = 1) noexcept;
        bool setup(int argc, char *argv[]);
        int run(int argc = 0, char *argv[] = nullptr);
        bool teardown();
        void moduleUnderTest(char *argv[]);
        void notYetImplemented();

    protected:
    private:
        std::string_view m_moduleUnderTest;
    };
}

#endif
