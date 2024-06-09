/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     08/06/24 W 21:30
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/


#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_PUB_SUBSCRIBERTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_PUB_SUBSCRIBERTEST_HPP

#include <gtest/gtest.h>
#include <com/github/doevelopper/atlas/events/pub/Subscriber.hpp>

namespace com::github::doevelopper::atlas::events::pub::test
{
    class SubscriberTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:
        SubscriberTest() noexcept;
        SubscriberTest(const SubscriberTest&) = default;
        SubscriberTest(SubscriberTest&&) = default;
        SubscriberTest& operator=(const SubscriberTest&) = default;
        SubscriberTest& operator=(SubscriberTest&&) = default;
        ~SubscriberTest() noexcept override;

        void SetUp() override;
        void TearDown() override;
    protected:
        com::github::doevelopper::atlas::events::pub::Subscriber * m_targetUnderTest;
    private:
    };
}

#endif
