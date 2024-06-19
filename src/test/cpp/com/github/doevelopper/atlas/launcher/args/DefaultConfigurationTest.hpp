/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     19/06/24 W 20:29
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_DEFAULTCONFIGURATIONTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_DEFAULTCONFIGURATIONTEST_HPP

#include <gtest/gtest.h>

#include <com/github/doevelopper/atlas/launcher/args/DefaultConfiguration.hpp>

namespace com::github::doevelopper::atlas::launcher::args::test
{
    class DefaultConfigurationTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        DefaultConfigurationTest() noexcept;
        DefaultConfigurationTest(const DefaultConfigurationTest&) = default;
        DefaultConfigurationTest(DefaultConfigurationTest&&) = default;
        DefaultConfigurationTest& operator=(const DefaultConfigurationTest&) = default;
        DefaultConfigurationTest& operator=(DefaultConfigurationTest&&) = default;
        ~DefaultConfigurationTest() noexcept override;

        void SetUp() override;
        void TearDown() override;
    protected:
    private:
    };
}

#endif
