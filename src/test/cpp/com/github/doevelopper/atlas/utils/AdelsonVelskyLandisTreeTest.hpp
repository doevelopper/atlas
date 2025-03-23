/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     22/12/24 W 21:24
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_ADELSONVELSKYLANDISTREETEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_ADELSONVELSKYLANDISTREETEST_HPP

#include <gtest/gtest.h>
#include <com/github/doevelopper/atlas/utils/AdelsonVelskyLandisTree.hpp>

namespace com::github::doevelopper::atlas::utils::test
{
    class AdelsonVelskyLandisTreeTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
        Q_DISABLE_COPY_MOVE(AdelsonVelskyLandisTreeTest)
    public:
        AdelsonVelskyLandisTreeTest() noexcept;
        ~AdelsonVelskyLandisTreeTest() noexcept override;

        void SetUp() override;
        void TearDown() override;
    protected:
        //com::github::doevelopper::atlas::utils::AdelsonVelskyLandisTree * m_targetUnderTest;
    private:
    };
}

#endif
