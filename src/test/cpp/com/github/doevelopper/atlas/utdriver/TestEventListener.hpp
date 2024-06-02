/*******************************************************************
* @file
 * @version  v0.0.
 * @date     2024/04/18 W 09:55:59
 * @brief    Test Driver
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2023 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_UTDRIVER_TESTEVENTLISTENER_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_UTDRIVER_TESTEVENTLISTENER_HPP

#include <gtest/gtest.h>
#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::utdriver::test
{
    class TestEventListener : public ::testing::EmptyTestEventListener
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        Q_DISABLE_COPY_MOVE(TestEventListener)

        void OnTestProgramStart(const ::testing::UnitTest & /*unit_test*/) override;
        void OnTestIterationStart(const ::testing::UnitTest & /*unit_test*/, int /*iteration*/) override;
        void OnEnvironmentsSetUpStart(const ::testing::UnitTest & /*unit_test*/) override;
        void OnEnvironmentsSetUpEnd(const ::testing::UnitTest & /*unit_test*/) override;
        void OnTestSuiteStart(const ::testing::TestSuite & /*test_suite*/) override;
        void OnTestCaseStart(const ::testing::TestCase & /*test_case*/) override;
        void OnTestStart(const ::testing::TestInfo & /*test_info*/) override;
        void OnTestDisabled(const ::testing::TestInfo & /*test_info*/) override;
        void OnTestPartResult(const ::testing::TestPartResult & /*test_part_result*/) override;
        void OnTestEnd(const ::testing::TestInfo & /*test_info*/) override;
        void OnTestSuiteEnd(const ::testing::TestSuite & /*test_suite*/) override;
        void OnTestCaseEnd(const ::testing::TestCase & /*test_case*/) override;
        void OnEnvironmentsTearDownStart(const ::testing::UnitTest & /*unit_test*/) override;
        void OnEnvironmentsTearDownEnd(const ::testing::UnitTest & /*unit_test*/) override;
        void OnTestIterationEnd(const ::testing::UnitTest & /*unit_test*/, int /*iteration*/) override;
        void OnTestProgramEnd(const ::testing::UnitTest & /*unit_test*/) override;
    public:
        TestEventListener() noexcept;
        virtual ~TestEventListener() noexcept;
    protected:
    private:
        std::string_view m_moduleUnderTest;
    };
}


#endif
