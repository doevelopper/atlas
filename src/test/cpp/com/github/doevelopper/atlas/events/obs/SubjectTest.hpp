/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     08/06/24 W 21:29
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_OBS_UBJECTTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_OBS_UBJECTTEST_HPP

#include <gtest/gtest.h>
#include <com/github/doevelopper/atlas/events/obs/Subject.hpp>

namespace com::github::doevelopper::atlas::events::obs::test
{
    class SubjectTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:
        SubjectTest() noexcept;
        SubjectTest(const SubjectTest&) = default;
        SubjectTest(SubjectTest&&) = default;
        SubjectTest& operator=(const SubjectTest&) = default;
        SubjectTest& operator=(SubjectTest&&) = default;
        ~SubjectTest() noexcept override;

        void SetUp() override;
        void TearDown() override;
    protected:
        com::github::doevelopper::atlas::events::obs::Subject * m_targetUnderTest;
    private:
    };
}

#endif
