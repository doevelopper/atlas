/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     19/06/24 W 20:27
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_CONFIGURATIONMOCK_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_CONFIGURATIONMOCK_HPP

#include <gmock/gmock.h>

#include <com/github/doevelopper/atlas/launcher/args/IConfiguration.hpp>

namespace com::github::doevelopper::atlas::launcher::args::test
{
    class ConfigurationMock : IConfiguration
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        ConfigurationMock() noexcept;
        ConfigurationMock(const ConfigurationMock&) = default;
        ConfigurationMock(ConfigurationMock&&) = default;
        ConfigurationMock& operator=(const ConfigurationMock&) = default;
        ConfigurationMock& operator=(ConfigurationMock&&) = default;
        ~ConfigurationMock() noexcept override ;
    protected:
    private:
    };
}
#endif
