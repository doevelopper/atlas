/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     08/06/24 W 21:29
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_PUB_PUBLISHERTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_PUB_PUBLISHERTEST_HPP

#include <gtest/gtest.h>
#include <com/github/doevelopper/atlas/events/pub/Publisher.hpp>

namespace com::github::doevelopper::atlas::events::pub::test
{
    class PublisherTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:
        PublisherTest() noexcept;
        PublisherTest(const PublisherTest&) = default;
        PublisherTest(PublisherTest&&) = default;
        PublisherTest& operator=(const PublisherTest&) = default;
        PublisherTest& operator=(PublisherTest&&) = default;
        ~PublisherTest() noexcept override ;

        void SetUp() override;
        void TearDown() override;
    protected:
    private:
        com::github::doevelopper::atlas::events::pub::Publisher * m_targetUnderTest;
    };
}

#endif
