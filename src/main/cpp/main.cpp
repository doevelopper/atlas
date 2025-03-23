/*******************************************************************
* @file
 * @version  v0.0.
 * @date     2024/04/18 W 09:55:59
 * @brief    Main entry point of application
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2023 ACME Technology Corp. All rights reserved.
********************************************************************/

// #include <cstdlib>
#include <iostream>
#include <memory>
#include <log4cxx/logmanager.h>

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
// int main (
//     [[maybe_unused]] int argc,
//     [[maybe_unused]] char ** argv
//     )
// {
//     std::uint_fast64_t runStatus = EXIT_SUCCESS;
//     // "export LOG4CXX_CONFIGURATION=$this_dir/log4cxx.properties\n"
//     // LOG4CXX_CONFIGURATION_WATCH_SECONDS
//     std::unique_ptr<CustomLogger> loggingService = std::make_unique<CustomLogger>();
//
//     if (!log4cxx::LogManager::getLoggerRepository()->isConfigured())
//     {
//         // loggingService =std::make_unique<LoggingService>();
//         // ShoulBeAllLogger->setLevel(log4cxx::Level::getOff());
//     }
//     // auto logger = log4cxx::Logger::getLogger("MyApp");
//     // LOG4CXX_INFO(logger, "Logging initialized successfully.");
//     // LOG4CXX_DEBUG(logger, "This is a debug message.");
//     try
//     {
//         std::unique_ptr<Application> application = std::make_unique<Application>(argc,argv);
//         runStatus = EXIT_SUCCESS;
//     }
//     catch (char const *str)
//     {
//         std::cerr << str << std::endl;
//         runStatus = EXIT_FAILURE;
//     }
//     catch (std::string & str)
//     {
//         std::cerr << str << std::endl;
//         runStatus = EXIT_FAILURE;
//     }
//     catch ( const std::exception & e )
//     {
//         std::cerr << e.what ( ) << std::endl;
//         runStatus = EXIT_FAILURE;
//     }
//     catch ( ... )
//     {
//         std::cerr << "unknown exception" << std::endl;
//         runStatus = EXIT_FAILURE;
//     }
//
//     return (runStatus == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
// }

int main (
    [[maybe_unused]] int argc,
    [[maybe_unused]] char ** argv
    )
{
    std::uint_fast64_t runStatus = EXIT_SUCCESS;

    try
    {
        // Create the application instance using std::make_unique
        std::unique_ptr<Application> application = std::make_unique<Application>(argc, argv);

        // auto logger = log4cxx::Logger::getLogger("MyApp");
        // LOG4CXX_INFO(logger, "<< "Starting " << appName << " version " << appVersion.toString());
        // LOG4CXX_INFO(logger, " << "Description: " << appDescription );

        // Start the application asynchronously
        std::future<void> runFuture = application->run();

        // Check if the application is running
        if (application->isRunning())
        {
            std::cout << "Application is running successfully." << std::endl;

            // Here you could implement wait logic or shutdown conditions
            // For example:
            // runFuture.wait();

            // Or implement a controlled shutdown after some condition:
            // std::future<void> shutdownFuture = application->shutdown("Normal termination");
            // shutdownFuture.wait();
        }
        else
        {
            std::cerr << "Application failed to start." << std::endl;
            runStatus = EXIT_FAILURE;
        }

        // The unique_ptr will automatically destroy the Application object
        // when it goes out of scope at the end of main()
        runStatus = EXIT_SUCCESS;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
        runStatus = EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "Unknown exception caught in main." << std::endl;
        runStatus = EXIT_FAILURE;
    }
    return (runStatus == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}