/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     29/05/24 W 20:00
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_STORAGE_BASEPTRTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_STORAGE_BASEPTRTEST_HPP

#include <memory>

#include <gtest/gtest.h>

#include <com/github/doevelopper/atlas/storage/BasePtr.hpp>

namespace com::github::doevelopper::atlas::storage::test
{

    struct MockCopyPolicy
    {
        template <typename Dest, typename Src>
        static void copy(Dest& dest, const Src& src)
        {
            // Implement the copy behavior here
            // For example, you can copy members directly or perform deep copying
            dest.value = src.value;
        }
    };

    // A struct to test custom deleter
    struct CustomDeleter_
    {
        void operator()(int* ptr)
        {
            delete ptr;
        }
    };

    template <typename T>
    struct CustomDeleter
    {
        void operator()(T* ptr)
        {
            delete ptr;
        }
    };

    class BasePtrTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        BasePtrTest();
        BasePtrTest(const BasePtrTest&) = default;
        BasePtrTest(BasePtrTest&&) = default;
        BasePtrTest& operator=(const BasePtrTest&) = default;
        BasePtrTest& operator=(BasePtrTest&&) = default;
        ~BasePtrTest() override;

        void SetUp() override;
        void TearDown() override;

    protected:
        // com::github::doevelopper::atlas::storage::BasePtr * m_targetUnderTest;
        using Ptr = com::github::doevelopper::atlas::storage::BasePtr<int, std::default_delete<int>, std::unique_ptr<int, std::default_delete<int>>>;

        Ptr m_targetUnderTest1;
        Ptr m_targetUnderTest2;
    private:
    };
}
#endif
