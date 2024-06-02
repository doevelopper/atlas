/*******************************************************************
* @file
 * @version  v0.0.
 * @date     2024/04/18 W 09:55:59
 * @brief    Main entry point of application
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2023 ACME Technology Corp. All rights reserved.
********************************************************************/

#include <com/github/doevelopper/atlas/launcher/Application.hpp>
#include <com/github/doevelopper/atlas/launcher/ApplicationPrivate.hpp>

using namespace com::github::doevelopper::atlas::launcher;
using namespace com::github::doevelopper::atlas::semver;

log4cxx::LoggerPtr Application::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.Application"));

Application::Package::Package()
    // : root(""), name(""), version(), arch(""), build(""), tag("")
{

}

Application::Package::Package(const std::string& name, const Version& version)
    // : root(""), name(name), version(version), arch(""), build(""), tag("")
{

}

Application::Package::~Package()
{

}

// std::string Application::Package::pkgName() const
// {
//     return name;
// }

Application::Application() noexcept
    : d_ptr(std::make_unique<ApplicationPrivate>()) //: Application(0, nullptr) {}
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(Application);
}

Application::Application(int argc, char ** argv) noexcept
    : d_ptr(std::make_unique<ApplicationPrivate>())
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D(Application);
    // d_ptr->package.version = Version(1, 0, 0);
}

Application::~Application() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Q_D ( Application );
}