/*******************************************************************
* @file
 * @version  v0.0.
 * @date     2024/04/18 W 09:55:59
 * @brief    Test Driver
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2023 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_UTDRIVER_TESTEVENTLISTENERCONFIGURE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_UTDRIVER_TESTEVENTLISTENERCONFIGURE_HPP

#include <gtest/gtest.h>
#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::utdriver::test
{
    class TestEventListenerConfigure final : public testing::TestEventListener
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        Q_DISABLE_COPY_MOVE(TestEventListenerConfigure)
    public:
        class Delegate
        {
            testing::TestEventListener *delegateEventListener;
            //                Q_DISABLE_COPY_MOVE(Delegate);
            LOG4CXX_DECLARE_STATIC_LOGGER
            public:
            Delegate() = delete;
            explicit Delegate(testing::TestEventListener *eventListener);
            virtual ~Delegate();

            Delegate showProgramStartEnd();
            Delegate showIterationsStartEnd();
            Delegate showTestCases();
            Delegate showTestNames();
            Delegate showTestSuite();
            Delegate showSuccesses();
            Delegate showFailures();
            Delegate showInlineFailures();
            Delegate showEnvironment();
            Delegate showSkip();
            TestEventListenerConfigure *build();

        protected:
        private:
            bool m_showProgramStartEnd = false;
            bool m_showIterationsStartEnd = false;
            bool m_showTestCases = false;
            bool m_showTestNames = false;
            bool m_showTestSuite = false;
            bool m_showSuccesses = false;
            bool m_showFailures = false;
            bool m_showInlineFailures = false;
            bool m_showEnvironment = false;
            bool m_showSkip = false;
        };

        TestEventListenerConfigure() = delete;
        virtual ~TestEventListenerConfigure() noexcept; // override ; //If the base destructor is not virtual then the compile crashes

        TestEventListenerConfigure(std::string &suite, unsigned int iteration = 1) noexcept;

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

    protected:
    private:
        //        TestEventListenerConfigure(std::unique_ptr<testing::TestEventListener> eventListener,
        TestEventListenerConfigure(testing::TestEventListener *eventListener, bool showProgramStartEnd,
                                      bool showIterationsStartEnd, bool showTestCases, bool showTestNames,
                                      bool showTestSuite, bool showSuccesses, bool showFailures,
                                      bool showInlineFailures, bool showEnvironment, bool showSkip);
        std::unique_ptr<testing::TestEventListener> m_eventListener;
        const bool m_showProgramStartEnd = false;
        const bool m_showIterationsStartEnd = false;
        const bool m_showTestCases = false;
        const bool m_showTestNames = false;
        const bool m_showTestSuite = false;
        const bool m_showSuccesses = false;
        const bool m_showFailures = false;
        const bool m_showInlineFailures = false;
        const bool m_showEnvironment = false;
        const bool m_showSkip = false;
    };
}


#endif
