/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     02/11/24 W 13:37
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

//
// Created by hroland on 02/11/24.
//

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_ACTOR_COORDINATOR_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_ACTOR_COORDINATOR_HPP

#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::actor
{
    class Coordinator
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        Coordinator() noexcept;
        Coordinator(const Coordinator&) = default;
        Coordinator(Coordinator&&) = default;
        Coordinator& operator=(const Coordinator&) = default;
        Coordinator& operator=(Coordinator&&) = default;
        virtual ~Coordinator() noexcept;
    protected:
    private:
    };
}
#endif
