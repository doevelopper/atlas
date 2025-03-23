/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     22/12/24 W 23:07
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/


#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_TIME_TIMESLICINGEVENTTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_TIME_TIMESLICINGEVENTTEST_HPP

#include <gtest/gtest.h>
#include <com/github/doevelopper/atlas/time/TimeSlicingEvent.hpp>

namespace com::github::doevelopper::atlas::time::test
{
    class TimeSlicingEventTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:
        TimeSlicingEventTest() noexcept;
        TimeSlicingEventTest(const TimeSlicingEventTest&) = default;
        TimeSlicingEventTest(TimeSlicingEventTest&&) = default;
        TimeSlicingEventTest& operator=(const TimeSlicingEventTest&) = default;
        TimeSlicingEventTest& operator=(TimeSlicingEventTest&&) = default;
        ~TimeSlicingEventTest() noexcept override;

        void SetUp() override;
        void TearDown() override;
    protected:
    private:
    };
}

#endif
