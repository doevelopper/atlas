/*******************************************************************
* @file
 * @version  v0.0.
 * @date     2024/04/18 W 09:55:59
 * @brief    Main entry point of application
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2023 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_APPLICATION_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_APPLICATION_HPP

#include <com/github/doevelopper/atlas/semver/Version.hpp>

namespace com::github::doevelopper::atlas::launcher
{
    class ApplicationPrivate;
    class Application
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        Q_DECLARE_PRIVATE(Application)
        Q_DISABLE_COPY_MOVE(Application)
        struct Package
        {
            Package();
            explicit Package(std::string name);
            Package(const std::string& name, const com::github::doevelopper::atlas::semver::Version& version);
            ~Package();
            std::string pkgName();
            std::string root;
            std::string name;
            std::string version;
            std::string arch;
            std::string build;
            std::string tag;
        };
    public:
        Application() noexcept;
        virtual ~Application() noexcept;
        Application([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) noexcept;
    protected:
    private:
        std::unique_ptr<ApplicationPrivate> d_ptr;
        Package package;
    };
}


#endif
