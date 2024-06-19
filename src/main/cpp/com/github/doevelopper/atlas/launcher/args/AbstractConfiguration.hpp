/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     18/06/24 W 20:55
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_ABSTRACTCONFIGURATION_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_ABSTRACTCONFIGURATION_HPP

#include <com/github/doevelopper/atlas/launcher/args/IConfiguration.hpp>

namespace com::github::doevelopper::atlas::launcher::args
{
    class AbstractConfiguration : public IConfiguration
    {
    public:

        [[nodiscard]] std::shared_ptr<AbstractOption> options() const override;

    private:

        LOG4CXX_DECLARE_STATIC_LOGGER

    public:

        // AbstractConfiguration(const AbstractConfiguration&) = default;
        // AbstractConfiguration(AbstractConfiguration&&) = default;
        // AbstractConfiguration& operator=(const AbstractConfiguration&) = default;
        // AbstractConfiguration& operator=(AbstractConfiguration&&) = default;

    protected:
        Q_DISABLE_COPY_MOVE(AbstractConfiguration)
        AbstractConfiguration() noexcept;
        ~AbstractConfiguration() noexcept override;
    private:
    };
}

#endif

