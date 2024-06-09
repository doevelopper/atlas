/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     08/06/24 W 12:47
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_SINGLETONTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_SINGLETONTEST_HPP

#include <memory>
#include <mutex>

#include <gtest/gtest.h>

#include <com/github/doevelopper/atlas/utils/Singleton.hpp>

namespace com::github::doevelopper::atlas::utils::test
{

    // Define a simple class that uses the Singleton pattern
    class MySingleton : public com::github::doevelopper::atlas::utils::Singleton<MySingleton>
    {
    public:
        int data;
    //
    //     MySingleton() : data(0) {}
    //     void increment() { ++data; }
    };

    class SingletonTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
        Q_DISABLE_COPY_MOVE(SingletonTest)
    public:
        SingletonTest();
        ~SingletonTest() override;

        void SetUp() override;
        void TearDown() override;
    protected:
        MySingleton * m_targetUnderTest;
    private:
    };
}

#endif
