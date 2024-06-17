/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     17/06/24 W 20:32
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_BARRIERS_RECURSIVEWRITELOCKTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_BARRIERS_RECURSIVEWRITELOCKTEST_HPP

#include <gtest/gtest.h>

#include <com/github/doevelopper/atlas/barriers/RecursiveReadLock.hpp>

namespace com::github::doevelopper::atlas::barriers::test
{
     class RecursiveReadLockTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:
        RecursiveReadLockTest() noexcept;
        RecursiveReadLockTest(const RecursiveReadLockTest&) = default;
        RecursiveReadLockTest(RecursiveReadLockTest&&) = default;
        RecursiveReadLockTest& operator=(const RecursiveReadLockTest&) = default;
        RecursiveReadLockTest& operator=(RecursiveReadLockTest&&) = default;
        ~RecursiveReadLockTest()  noexcept override;

         void SetUp() override;
         void TearDown() override;
    protected:
         com::github::doevelopper::atlas::barriers::RecursiveReadLock * m_targetUnderTest;
    private:
    };
}

#endif
