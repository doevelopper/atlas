/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     02/11/24 W 13:39
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_SECURITY_ALGORITHM_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_SECURITY_ALGORITHM_HPP

#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::security
{
    class Algorithm
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        Algorithm() = default;
        Algorithm(const Algorithm&) = default;
        Algorithm(Algorithm&&) = default;
        Algorithm& operator=(const Algorithm&) = default;
        Algorithm& operator=(Algorithm&&) = default;
        virtual ~Algorithm() = default;
    protected:
    private:
    };

}

#endif
