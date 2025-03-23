/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     19/03/25 W 22:12
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2025 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_FSM_ERROR_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_FSM_ERROR_HPP
#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>
namespace com::github::doevelopper::atlas::launcher::fsm
{
    class Error
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        Error() = default;
        Error(const Error&) = default;
        Error(Error&&) = default;
        Error& operator=(const Error&) = default;
        Error& operator=(Error&&) = default;
        virtual ~Error() = default;
    protected:
    private:
    };
}


#endif //ERROR_HPP
