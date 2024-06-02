/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     02/06/24 W 17:02
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_SHELLHANDLE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_SHELLHANDLE_HPP

#include <com/github/doevelopper/atlas/storage/BasePtr.hpp>

namespace com::github::doevelopper::atlas::utils
{
    class ShellHandle
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        Q_DISABLE_COPY_MOVE(ShellHandle)
    public:
        ShellHandle() noexcept;
        virtual ~ShellHandle() noexcept;
        /*!
         * @brief Execute shell command and capture output to string.
         */
        static auto exec(const char* cmd) -> std::string;

    protected:
    private:
    };
}


#endif //SHELLHANDLE_HPP
