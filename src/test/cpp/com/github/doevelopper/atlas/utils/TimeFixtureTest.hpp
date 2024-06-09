/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     08/06/24 W 20:22
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_TIMEFIXTURETEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_TIMEFIXTURETEST_HPP

#include <memory>
#include <mutex>

#include <gtest/gtest.h>

#include <com/github/doevelopper/atlas/utils/TimeFixture.hpp>

namespace com::github::doevelopper::atlas::utils::test
{
    class TimeFixtureTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
        Q_DISABLE_COPY_MOVE(TimeFixtureTest)
    public:
        TimeFixtureTest() noexcept;
        ~TimeFixtureTest() noexcept override ;

        void SetUp() override;
        void TearDown() override;
    protected:
        com::github::doevelopper::atlas::utils::TimeFixture * m_targetUnderTest;
    private:
    };
}

#endif
