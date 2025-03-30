/*******************************************************************
* @file
 * @version  v0.0.
 * @date     2024/04/18 W 09:55:59
 * @brief    Main entry point of application
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2023 ACME Technology Corp. All rights reserved.
********************************************************************/

#include <iostream>
#include <memory>
#include <log4cxx/logmanager.h>
#include <log4cxx/logger.h>

#include <com/github/doevelopper/atlas/logging/LoggingInitializer.hpp>
#include <com/github/doevelopper/atlas/logging/LoggingInitializationFactory.hpp>
#include <com/github/doevelopper/atlas/logging/EnvironmentBasedInitializationStrategy.hpp>
#include <com/github/doevelopper/atlas/launcher/Application.hpp>

using namespace com::github::doevelopper::atlas::launcher;
using namespace com::github::doevelopper::atlas::logging;

/*!
 * @brief
 * @param argc number of string arguments passed via argv
 * @param argv array to command line arguments as strings
 *             (an array of character pointers)
 * @return the completion status code (zero indicates success)
 */
int main (
    [[maybe_unused]] int argc,
    [[maybe_unused]] char ** argv
    )
{
    std::uint_fast64_t runStatus = EXIT_SUCCESS;
    
    try 
    {
        // Create the application instance which will initialize logging
        std::unique_ptr<Application> application = std::make_unique<Application>(argc, argv);
        
        // // Get a logger for main application events
        auto mainLogger = log4cxx::Logger::getLogger("com.github.doevelopper.atlas.main");
        LOG4CXX_INFO(mainLogger,  __LOG4CXX_FUNC__ << " Start the application asynchronously...");

        std::future<void> runFuture = application->run();

        // // Check if the application is running
        // if (application->isRunning())
        {
            LOG4CXX_INFO(mainLogger, "Application is running successfully");

            // Here you could implement wait logic or shutdown conditions
            // For example:
            runFuture.wait();

            // Or implement a controlled shutdown after some condition:
            std::future<void> shutdownFuture = application->shutdown("Normal termination");
            shutdownFuture.wait();
        }
        // else
        {
            LOG4CXX_ERROR(mainLogger, "Application failed to start");
            runStatus = EXIT_FAILURE;
        }

        runStatus = EXIT_SUCCESS;
    }
    catch (const std::exception& e) {
        // auto errorLogger = log4cxx::Logger::getLogger("com.github.doevelopper.atlas.main");
        // LOG4CXX_ERROR(errorLogger, "Exception caught in main: " << e.what());
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
        runStatus = EXIT_FAILURE;
    }
    catch (...) {
        // auto errorLogger = log4cxx::Logger::getLogger("com.github.doevelopper.atlas.main");
        // LOG4CXX_ERROR(errorLogger, "Unknown exception caught in main");
        std::cerr << "Unknown exception caught in main." << std::endl;
        runStatus = EXIT_FAILURE;
    }
    
    // Log the application exit status
    // auto mainLogger = log4cxx::Logger::getLogger("com.github.doevelopper.atlas.main");
    // LOG4CXX_INFO(mainLogger, "Atlas application exiting with status: " << runStatus);
    
    // The LogManager shutdown will be handled automatically when the application exits
    
    return (runStatus == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}