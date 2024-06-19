/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     19/06/24 W 20:28
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_ABSTRACTCONFIGURATIONMOCK_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_ABSTRACTCONFIGURATIONMOCK_HPP

#include <gmock/gmock.h>

#include <com/github/doevelopper/atlas/launcher/args/AbstractConfiguration.hpp>

namespace com::github::doevelopper::atlas::launcher::args::test
{
    class AbstractConfigurationMock : AbstractConfiguration
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        AbstractConfigurationMock() noexcept;
        AbstractConfigurationMock(const AbstractConfigurationMock&) = default;
        AbstractConfigurationMock(AbstractConfigurationMock&&) = default;
        AbstractConfigurationMock& operator=(const AbstractConfigurationMock&) = default;
        AbstractConfigurationMock& operator=(AbstractConfigurationMock&&) = default;
        ~AbstractConfigurationMock() noexcept override;
    protected:
    private:
    };
}

#endif
