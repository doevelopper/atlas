/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     21/06/24 W 20:59
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_TIME_ALARMMOCK_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_TIME_ALARMMOCK_HPP

#include <gmock/gmock.h>

#include <com/github/doevelopper/atlas/time/Alarm.hpp>

namespace com::github::doevelopper::atlas::time::test
{
    class AlarmMock : public ::testing::NiceMock<Alarm>
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        AlarmMock() noexcept;
        AlarmMock(const AlarmMock&) = default;
        AlarmMock(AlarmMock&&) = default;
        AlarmMock& operator=(const AlarmMock&) = default;
        AlarmMock& operator=(AlarmMock&&) = default;
        ~AlarmMock() noexcept override ;

        MOCK_METHOD(bool, cancel, (), (override));
        MOCK_METHOD(State, state, (), (const, override));
        MOCK_METHOD(bool, reschedule_in, (std::chrono::milliseconds), (override));
        MOCK_METHOD(bool, reschedule_for, (Timestamp), (override));

    protected:
    private:
    };
}

#endif
