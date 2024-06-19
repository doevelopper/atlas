/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     18/06/24 W 20:50
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_ICONFIGURATION_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_ICONFIGURATION_HPP

#include <com/github/doevelopper/atlas/launcher/args/AbstractOption.hpp>

namespace com::github::doevelopper::atlas::launcher::args
{
    class IConfiguration
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        [[nodiscard]] virtual std::shared_ptr<AbstractOption> options() const = 0;
    protected:
        Q_DISABLE_COPY_MOVE(IConfiguration)
        IConfiguration() noexcept;
        virtual ~IConfiguration() noexcept;
    private:
    };
}

#endif
