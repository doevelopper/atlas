/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     02/06/24 W 16:21
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_STORAGE_CIRCULARBUFFERTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_STORAGE_CIRCULARBUFFERTEST_HPP

#include <memory>

#include <gtest/gtest.h>
#include <com/github/doevelopper/atlas/storage/CircularBuffer.hpp>

namespace com::github::doevelopper::atlas::storage::test
{
    template <typename T>
    class CircularBufferTest  : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        CircularBufferTest() noexcept;
        // CircularBufferTest(const CircularBufferTest&) = default;
        // CircularBufferTest(CircularBufferTest&&) = default;
        // CircularBufferTest& operator=(const CircularBufferTest&) = default;
        // CircularBufferTest& operator=(CircularBufferTest&&) = default;
        ~CircularBufferTest() override;

        void SetUp() override;
        void TearDown() override;

    protected:
        // com::github::doevelopper::atlas::storage::CircularBuffer<T> m_targetUnderTest;
        std::unique_ptr<com::github::doevelopper::atlas::storage::CircularBuffer<int>> m_targetUnderTest;
    private:
    };

    TYPED_TEST_SUITE(CircularBufferTest, int, float);
}

#endif
