/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     02/11/24 W 13:46
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_ACTOR_COORDINATORTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_ACTOR_COORDINATORTEST_HPP

#include <com/github/doevelopper/atlas/actor/Coordinator.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::atlas::actor::test
{
    class CoordinatorTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:
        CoordinatorTest() noexcept;
        CoordinatorTest(const CoordinatorTest&) = default;
        CoordinatorTest(CoordinatorTest&&) = default;
        CoordinatorTest& operator=(const CoordinatorTest&) = default;
        CoordinatorTest& operator=(CoordinatorTest&&) = default;
        virtual ~CoordinatorTest() noexcept;

        void SetUp() override;
        void TearDown() override;

    protected:
        com::github::doevelopper::atlas::actor::Coordinator * m_targetUnderTest;
    private:
    };
}

#endif //COORDINATORTEST_HPP
