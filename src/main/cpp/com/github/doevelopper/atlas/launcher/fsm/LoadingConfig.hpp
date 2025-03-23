/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     19/03/25 W 22:10
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2025 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_FSM_LOADINGCONFIG_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_FSM_LOADINGCONFIG_HPP
#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>
namespace com::github::doevelopper::atlas::launcher::fsm
{
    class LoadingConfig
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        LoadingConfig() = default;
        LoadingConfig(const LoadingConfig&) = default;
        LoadingConfig(LoadingConfig&&) = default;
        LoadingConfig& operator=(const LoadingConfig&) = default;
        LoadingConfig& operator=(LoadingConfig&&) = default;
        virtual ~LoadingConfig() = default;
    protected:
    private:
    };
}

#endif //LOADINGCONFIG_HPP
