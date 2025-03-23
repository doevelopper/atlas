/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     21/06/24 W 20:59
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_TIME_ALARMTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_TIME_ALARMTEST_HPP

#include <gtest/gtest.h>

#include <com/github/doevelopper/atlas/time/AlarmMock.hpp>

namespace com::github::doevelopper::atlas::time::test
{
    class AlarmTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:
        AlarmTest() noexcept;
        AlarmTest(const AlarmTest&) = default;
        AlarmTest(AlarmTest&&) = default;
        AlarmTest& operator=(const AlarmTest&) = default;
        AlarmTest& operator=(AlarmTest&&) = default;
        ~AlarmTest() noexcept override;

        void SetUp() override;
        void TearDown() override;
    protected:
        com::github::doevelopper::atlas::time::test::AlarmMock * m_targetUnderTest;
    private:
    };
}

#endif
