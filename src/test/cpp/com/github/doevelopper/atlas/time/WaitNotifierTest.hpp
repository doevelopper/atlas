/*******************************************************************
* @file
 * @version  v0.0.
 * @date     21/06/24 W 20:59
 * @brief
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_TIME_WAITNOTIFIERTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_TIME_WAITNOTIFIERTEST_HPP

#include <gtest/gtest.h>

#include <com/github/doevelopper/atlas/time/WaitNotifier.hpp>

namespace com::github::doevelopper::atlas::time::test
{
    class WaitNotifierTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:
        WaitNotifierTest() noexcept;
        WaitNotifierTest(const WaitNotifierTest&) = default;
        WaitNotifierTest(WaitNotifierTest&&) = default;
        WaitNotifierTest& operator=(const WaitNotifierTest&) = default;
        WaitNotifierTest& operator=(WaitNotifierTest&&) = default;
        ~WaitNotifierTest() noexcept override;

        void SetUp() override;
        void TearDown() override;
    protected:
        // com::github::doevelopper::atlas::time::WaitNotifier * m_targetUnderTest;
        std::unique_ptr<com::github::doevelopper::atlas::time::WaitNotifier> m_targetUnderTest;
    private:
    };
}

#endif

