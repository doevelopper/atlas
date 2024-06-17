/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     17/06/24 W 20:31
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_BARRIERS_RECURSIVEREADWRITEMUTEXTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_BARRIERS_RECURSIVEREADWRITEMUTEXTEST_HPP

#include <gtest/gtest.h>

#include <com/github/doevelopper/atlas/barriers/RecursiveReadWriteMutex.hpp>

namespace com::github::doevelopper::atlas::barriers::test
{
    class RecursiveReadWriteMutexTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:
        RecursiveReadWriteMutexTest() noexcept;
        RecursiveReadWriteMutexTest(const RecursiveReadWriteMutexTest&) = default;
        RecursiveReadWriteMutexTest(RecursiveReadWriteMutexTest&&) = default;
        RecursiveReadWriteMutexTest& operator=(const RecursiveReadWriteMutexTest&) = default;
        RecursiveReadWriteMutexTest& operator=(RecursiveReadWriteMutexTest&&) = default;
        ~RecursiveReadWriteMutexTest() noexcept override;

        void SetUp() override;
        void TearDown() override;
    protected:
        com::github::doevelopper::atlas::barriers::RecursiveReadWriteMutex * m_targetUnderTest;
    private:
    };
}

#endif
