/*******************************************************************
* @file
 * @version  v0.0.
 * @date     2024/04/18 W 09:55:59
 * @brief    Test Driver
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2023 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_UTDRIVER_CUSTOMTESTENVIRONMENT_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_UTDRIVER_CUSTOMTESTENVIRONMENT_HPP

#include <gtest/gtest.h>
#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::utdriver::test
{
    class CustomTestEnvironment : public ::testing::Environment
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        Q_DISABLE_COPY_MOVE(CustomTestEnvironment)
    public:
        CustomTestEnvironment() noexcept;
        virtual ~CustomTestEnvironment() noexcept;

        void SetUp() override;// Override this to define how to set up the environment.
        void TearDown() override;// Override this to define how to tear down the environment.

    protected:
    private:
        std::string_view m_moduleUnderTest;
    };
}


#endif
