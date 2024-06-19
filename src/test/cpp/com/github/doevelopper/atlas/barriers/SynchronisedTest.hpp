/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     18/06/24 W 21:50
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_BARRIERS_SYNCHRONISEDTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_BARRIERS_SYNCHRONISEDTEST_HPP

#include <mutex>
#include <thread>
#include <string>

#include <gtest/gtest.h>

#include <com/github/doevelopper/atlas/barriers/Synchronised.hpp>

namespace com::github::doevelopper::atlas::barriers::test
{
    template<typename T>
    class SynchronisedTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:
        SynchronisedTest() noexcept;
        SynchronisedTest(const SynchronisedTest&) = default;
        SynchronisedTest(SynchronisedTest&&) = default;
        SynchronisedTest& operator=(const SynchronisedTest&) = default;
        SynchronisedTest& operator=(SynchronisedTest&&) = default;
        ~SynchronisedTest() noexcept override;

        void SetUp() override;
        void TearDown() override;
    protected:
    private:
    };

    TYPED_TEST_SUITE(SynchronisedTest, ::testing::Types<int, float, std::string>);
}

/*
#include <gtest/gtest.h>
#include "synchronised.h"

class SynchronisedTestFixture : public ::testing::ParametrizedTest {
protected:
  Synchronised<int> s;
};

INSTANTIATE_TEST_CASE_P(
  SynchronisedTest,
  SynchronisedTestFixture,
  ::testing::Values(
    std::make_tuple(0),
    std::make_tuple(42),
    std::make_tuple(-1)
  )
);

TEST_P(SynchronisedTestFixture, DefaultConstruction) {
  EXPECT_TRUE(s.value == 0);
}

TEST_P(SynchronisedTestFixture, MoveConstruction) {
  Synchronised<int> s1(42);
  Synchronised<int> s2 = std::move(s1);
  EXPECT_TRUE(s2.value == 42);
}

TEST_P(SynchronisedTestFixture, Locking) {
  Locked l = s.lock();
  EXPECT_TRUE(l.value == 0);
  l.drop();
}

TEST_P(SynchronisedTestFixture, LockingConst) {
  LockedView lv = s.lock();
  EXPECT_TRUE(lv.value == 0);
  lv.drop();
}

TEST_P(SynchronisedTestFixture, Wait) {
  std::condition_variable cv;
  std::unique_lock<std::mutex> lk(s.mutex);
  s.wait(cv, [&]{ return true; });
  lk.unlock();
}

TEST_P(SynchronisedTestFixture, Drop) {
  Locked l = s.lock();
  l.drop();
  EXPECT_TRUE(s.value == 0);
}

TEST_P(SynchronisedTestFixture, LockedView) {
  LockedView lv = s.lock();
  EXPECT_TRUE(lv.value == 0);
  lv.drop();
}

TEST_P(SynchronisedTestFixture, Locked) {
  Locked l = s.lock();
  EXPECT_TRUE(l.value == 0);
  l.drop();
}

TEST_P(SynchronisedTestFixture, LockedCopy) {
  Locked l = s.lock();
  Locked l2 = l;
  EXPECT_TRUE(l2.value == 0);
  l2.drop();
}

TEST_P(SynchronisedTestFixture, LockedMove) {
  Locked l = s.lock();
  Locked l2 = std::move(l);
  EXPECT_TRUE(l2.value == 0);
  l2.drop();
}

TEST_P(SynchronisedTestFixture, LockedDrop) {
  Locked l = s.lock();
  l.drop();
  EXPECT_TRUE(s.value == 0);
}
 */
#endif
