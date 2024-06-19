/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     19/06/24 W 20:26
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_PROGRAMOPTIONTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_PROGRAMOPTIONTEST_HPP

#include <gtest/gtest.h>

#include <com/github/doevelopper/atlas/launcher/args/ProgramOption.hpp>

namespace com::github::doevelopper::atlas::launcher::args::test
{
    class ProgramOptionTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:
        ProgramOptionTest() noexcept;
        ProgramOptionTest(const ProgramOptionTest&) = default;
        ProgramOptionTest(ProgramOptionTest&&) = default;
        ProgramOptionTest& operator=(const ProgramOptionTest&) = default;
        ProgramOptionTest& operator=(ProgramOptionTest&&) = default;
        ~ProgramOptionTest() noexcept override;

        void SetUp() override;
        void TearDown() override;
    protected:
    private:
    };
}

#endif
