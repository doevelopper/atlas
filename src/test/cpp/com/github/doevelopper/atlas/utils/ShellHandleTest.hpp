/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     02/06/24 W 17:16
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_SHELLHANDLETEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_SHELLHANDLETEST_HPP

#include <memory>

#include <gtest/gtest.h>
#include <com/github/doevelopper/atlas/utils/ShellHandle.hpp>

namespace com::github::doevelopper::atlas::utils::test
{
    class ShellHandleTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
        Q_DISABLE_COPY_MOVE(ShellHandleTest)
    public:
        ShellHandleTest();
        virtual ~ShellHandleTest();

        void SetUp() override;
        void TearDown() override;
    protected:
        com::github::doevelopper::atlas::utils::ShellHandle * m_targetUnderTest;
    private:
    };
}

#endif
