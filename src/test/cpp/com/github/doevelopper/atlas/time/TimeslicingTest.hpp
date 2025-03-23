/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     22/12/24 W 23:07
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/


#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_TIME_TIMESLICINGTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_TIME_TIMESLICINGTEST_HPP

#include <gtest/gtest.h>

#include <com/github/doevelopper/atlas/time/Timeslicing.hpp>

namespace com::github::doevelopper::atlas::time::test
{

    /// Expected type ID for the type returned from repeat(), poll() and defer().
    constexpr std::array<std::uint8_t, 16> event_type_id =
        {0xB6, 0x87, 0x48, 0xA6, 0x7A, 0xDB, 0x4D, 0xF1, 0xB3, 0x1D, 0xA9, 0x8D, 0x50, 0xA7, 0x82, 0x47};

    /// This clock has to keep global state to implement the TrivialClock trait.
    class SteadyClockMock final
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        using rep        = std::int64_t;
        using period     = std::ratio<1, 1'000>;
        using duration   = std::chrono::duration<rep, period>;
        using time_point = std::chrono::time_point<SteadyClockMock>;

        [[maybe_unused]] static constexpr bool is_steady = true;

        SteadyClockMock() noexcept
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        }
        ~SteadyClockMock() noexcept
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        }

        static time_point& now() noexcept
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
            static time_point g_now_;
            return g_now_;
        }

        static void reset() noexcept
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
            now() = {};
        }

        template <typename Rep, typename Per>
        static void advance(const std::chrono::duration<Rep, Per> dur)
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
            now() += std::chrono::duration_cast<duration>(dur);
        }
    };

    class TimeslicingTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:
        TimeslicingTest() noexcept;
        TimeslicingTest(const TimeslicingTest&) = default;
        TimeslicingTest(TimeslicingTest&&) = default;
        TimeslicingTest& operator=(const TimeslicingTest&) = default;
        TimeslicingTest& operator=(TimeslicingTest&&) = default;
        ~TimeslicingTest() noexcept override;

        void SetUp() override;
        void TearDown() override;
    protected:
    private:
    };
}

#endif
