/*******************************************************************
* @file
 * @version  v0.0.
 * @date     2024/04/18 W 09:55:59
 * @brief    Main entry point of application
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2023 ACME Technology Corp. All rights reserved.
********************************************************************/

#include <log4cxx/helpers/exception.h>
#include <stdexcept>


#include <com/github/doevelopper/atlas/launcher/Application.hpp>
#include <com/github/doevelopper/atlas/launcher/ApplicationPrivate.hpp>

using namespace com::github::doevelopper::atlas::launcher;
using namespace com::github::doevelopper::atlas::semver;

log4cxx::LoggerPtr Application::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.Application"));


// LOG4CXX_IMPL_STATIC_LOGGER(Application, "Application")
// LOG4CXX_IMPL_STATIC_LOGGER(Application::Package, "Application.Package")
//
// // Package implementation
//
// Application::Package::Package()
//     : root("")
//     , name("")
//     , version("")
//     , arch("")
//     , build("")
//     , tag("")
// {
//     LOG4CXX_TRACE(logger, "Created empty package");
// }
//
// Application::Package::Package(std::string name)
//     : root("")
//     , name(std::move(name))
//     , version("")
//     , arch("")
//     , build("")
//     , tag("")
// {
//     LOG4CXX_TRACE(logger, "Created package with name: " << this->name);
// }
//
// Application::Package::Package(const std::string& name, const Version& version)
//     : root("")
//     , name(name)
//     , version(version.toString())
//     , arch("")
//     , build("")
//     , tag("")
// {
//     LOG4CXX_TRACE(logger, "Created package with name: " << this->name << " and version: " << this->version);
// }
//
// Application::Package::~Package()
// {
//     LOG4CXX_TRACE(logger, "Destroyed package: " << name);
// }
//
// std::string Application::Package::pkgName()
// {
//     return name + "-" + version + (tag.empty() ? "" : "-" + tag);
// }
//
// // Application implementation
//
Application::Application() noexcept
    : d_ptr(std::make_unique<ApplicationPrivate>(this))
{
    LOG4CXX_DEBUG(logger, "Application created with default constructor");
//     try {
//         // Perform basic initialization
//         d_ptr->initialize();
//     } catch (const std::exception& e) {
//         LOG4CXX_ERROR(logger, "Initialization failed: " << e.what());
//         // We're in a noexcept constructor, so we can't throw
//         // Just log the error and continue with a partially initialized state
//     } catch (...) {
//         LOG4CXX_ERROR(logger, "Initialization failed with unknown exception");
//     }
}

Application::~Application() noexcept
{
     LOG4CXX_DEBUG(logger, "Application being destroyed");
//     try {
//         // If the application is still running, shut it down
//         if (isRunning()) {
//             LOG4CXX_WARN(logger, "Application is still running during destruction, forcing shutdown");
//             shutdown("Destructor called").wait();
//         }
//     } catch (const std::exception& e) {
//         // Don't let exceptions escape the destructor
//         LOG4CXX_ERROR(logger, "Exception in destructor: " << e.what());
//     } catch (...) {
//         LOG4CXX_ERROR(logger, "Unknown exception in destructor");
//     }
    LOG4CXX_DEBUG(logger, "Application destroyed");
}

Application::Application([[maybe_unused]] int argc, [[maybe_unused]] char** argv) noexcept
    : d_ptr(std::make_unique<ApplicationPrivate>(this, argc, argv))
{
    LOG4CXX_DEBUG(logger, "Application created with arguments");
    // Q_D(Application); // Qt macro to get d-pointer
    // d->doPrivateWork(); // Access private implementation
//     try {
//         // Perform initialization with arguments
//         d_ptr->initialize();
//     } catch (const std::exception& e) {
//         LOG4CXX_ERROR(logger, "Initialization failed: " << e.what());
//         // We're in a noexcept constructor, so we can't throw
//     } catch (...) {
//         LOG4CXX_ERROR(logger, "Initialization failed with unknown exception");
    // }
}

std::future<void> Application::run()
{
//     Q_D(const Application);
//     LOG4CXX_INFO(logger, "Starting application");
//     try {
//         return d_ptr->run();
//     } catch (const std::exception& e) {
//         LOG4CXX_ERROR(logger, "Failed to start application: " << e.what());
//
//         // Create a future with the exception
//         std::promise<void> promise;
//         promise.set_exception(std::current_exception());
//         return promise.get_future();
    // }
}

std::future<void> Application::shutdown(const std::string& reason)
{
//     LOG4CXX_INFO(logger, "Shutting down application: " << reason);
//     try {
//         return d_ptr->shutdown(reason);
//     } catch (const std::exception& e) {
//         LOG4CXX_ERROR(logger, "Failed to shutdown application: " << e.what());
//
//         // Create a future with the exception
//         std::promise<void> promise;
//         promise.set_exception(std::current_exception());
//         return promise.get_future();
//     }
}

Version Application::getVersion() const
{
//     // Implementation depends on your Version class
//     // This is a placeholder
//     return Version();
}
//
std::string Application::getName() const
{
//     // This would typically access a member of ApplicationPrivate
//     // For demonstration, we return a placeholder
//     return "ApplicationName";
}

// std::string Application::getDescription() const
// {
//     // This would typically access a member of ApplicationPrivate
//     // For demonstration, we return a placeholder
//     return "Application Description";
// }
//
bool Application::isRunning() const
{
//     // This would check the state in ApplicationPrivate
//     // For demonstration, we use a naive implementation
//     // In a real implementation, you would access the state in ApplicationPrivate
//     try {
//         // Placeholder for accessing state in ApplicationPrivate
//         return true; // Replace with actual implementation
//     } catch (const std::exception& e) {
//         LOG4CXX_ERROR(logger, "Error checking if application is running: " << e.what());
//         return false;
//     }
}

// Application::Package Application::getPackage() const
// {
//     // Create and return a Package object
//     // This would typically be populated with actual values from ApplicationPrivate
//     return Package(getName(), getVersion());
// }
//
// ApplicationPrivate* Application::d_func() const
// {
//     return d_ptr.get();
// }

// log4cxx::LoggerPtr Application::Package::logger =
//     log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.Package.Application"));
//
// Application::Package::Package()
//     // : root(""), name(""), version(), arch(""), build(""), tag("")
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }
//
// Application::Package::Package(const std::string& name, const Version& version)
//     // : root(""), name(name), version(version), arch(""), build(""), tag("")
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }
//
// Application::Package::~Package()
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }
//
// // std::string Application::Package::pkgName() const
// // {
// //     return name;
// // }
//
// Application::Application() noexcept
//     : d_ptr(std::make_unique<ApplicationPrivate>()) //: Application(0, nullptr) {}
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Q_D(Application);
// }
//
// Application::Application(int argc, char ** argv) noexcept
//     : d_ptr(std::make_unique<ApplicationPrivate>())
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Q_D(Application);
//     // d_ptr->m_package.version = Version(1, 0, 0);
// }
//
// Application::~Application() noexcept
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Q_D ( Application );
// }