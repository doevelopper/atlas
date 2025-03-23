/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     02/11/24 W 13:46
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_SECURITY_ALGORITHMTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_SECURITY_ALGORITHMTEST_HPP

#include <com/github/doevelopper/atlas/security/Algorithm.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::atlas::security::test
{
    class AlgorithmTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:
        AlgorithmTest() noexcept;
        AlgorithmTest(const AlgorithmTest&) = default;
        AlgorithmTest(AlgorithmTest&&) = default;
        AlgorithmTest& operator=(const AlgorithmTest&) = default;
        AlgorithmTest& operator=(AlgorithmTest&&) = default;
        virtual ~AlgorithmTest() noexcept;

        void SetUp() override;
        void TearDown() override;

    protected:
        com::github::doevelopper::atlas::security::Algorithm * m_targetUnderTest;
    private:
    };
}


#endif //ALGORITHMTEST_HPP
