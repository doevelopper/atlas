/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     19/03/25 W 22:11
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2025 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_FSM_SHUTTINGDOWN_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_FSM_SHUTTINGDOWN_HPP
#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>
namespace com::github::doevelopper::atlas::launcher::fsm
{
    class ShuttingDown
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        ShuttingDown() = default;
        ShuttingDown(const ShuttingDown&) = default;
        ShuttingDown(ShuttingDown&&) = default;
        ShuttingDown& operator=(const ShuttingDown&) = default;
        ShuttingDown& operator=(ShuttingDown&&) = default;
        virtual ~ShuttingDown() = default;
    protected:
    private:
    };
}

#endif //SHUTTINGDOWN_HPP
