/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     02/06/24 W 17:49
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_FILESYSTEMHANDLE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_FILESYSTEMHANDLE_HPP

#include <com/github/doevelopper/atlas/utils/ShellHandle.hpp>

namespace com::github::doevelopper::atlas::utils
{
    class FileSystemHandle
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        Q_DISABLE_COPY_MOVE(FileSystemHandle)
    public:
        FileSystemHandle() noexcept;
        virtual ~FileSystemHandle() noexcept;

        static auto createDirectory(std::string path) -> bool;
        static auto createEmptyFile(const std::string& path) -> bool;
        static auto setFilePermissionsWriteAll(const std::string& path) -> bool;
        static auto setFilePermissionsAllAll(const std::string& path) -> bool;

    protected:
    private:
    };
}

#endif
