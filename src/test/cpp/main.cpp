/*******************************************************************
* @file
 * @version  v0.0.
 * @date     2024/04/18 W 09:55:59
 * @brief    Main entry point of application
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2023 ACME Technology Corp. All rights reserved.
********************************************************************/

#include <cstdlib>
#include <iostream>

#include <com/github/doevelopper/atlas/utdriver/TestDriver.hpp>

using namespace com::github::doevelopper::atlas::logging;
using namespace com::github::doevelopper::atlas::utdriver::test;

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
    char loggersConfiguratorPath[]="TEMP=/opt/log4cxx.xml";
    putenv( loggersConfiguratorPath );
    std::unique_ptr<CustomLogger> loggingService =std::make_unique<CustomLogger>();
    std::unique_ptr<TestDriver> applicationUnderTest = std::make_unique<TestDriver>();

    std::int8_t runStatus = 0;

    try
    {
        applicationUnderTest->setup(argc, argv);
        runStatus = applicationUnderTest->run(argc, argv);
        applicationUnderTest->teardown();

        if (runStatus != EXIT_SUCCESS)
        {
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(),
                "**************************************************************************");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(),
                "========== . FAILURE . ========== . FAILURE . ========== . FAILURE . =====");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(),
                "**************************************************************************");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "                         ▒▒▓▓██████████████▓▓░░");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "                   ░░████████████████████████████▒▒");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "                 ████████████████████████████████████▒▒");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "             ▒▒████████████████████████████████████████▓▓");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "           ▓▓██████████████████████████████████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "         ▓▓██████████████████████████████████████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "       ▒▒██████████████████████████████████████████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "       ██████████    ▓▓██████████████████████████░░  ▓▓████████▒▒");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "     ██████████        ▓▓██████████████████████        ██████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "   ░░██████████          ▓▓██████████████████          ██████████▓▓");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "   ██████████████          ▓▓██████████████          ░░████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "   ██████████████▓▓          ▓▓██████████            ██████████████▒▒");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), " ▒▒████████████████▓▓          ▓▓██████            ██████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), " ▓▓██████████████████▓▓          ▓▓██            ████████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), " ██████████████████████▓▓                      ██████████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), " ████████████████████████▓▓                  ████████████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), " ██████████████████████████▓▓            ░░██████████████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), " ████████████████████████████            ▓▓██████████████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), " ██████████████████████████                ▓▓████████████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), " ████████████████████████                    ▓▓██████████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), " ██████████████████████            ▓▓          ▓▓████████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), " ▓▓██████████████████            ████▓▓          ▓▓██████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), " ░░████████████████            ████████▓▓          ▓▓██████████████▓▓");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "   ██████████████            ████████████▓▓          ▓▓████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "   ▒▒██████████            ████████████████▓▓          ████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "     ██████████          ████████████████████▓▓        ██████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "     ▒▒████████▒▒      ████████████████████████▓▓    ░░████████▓▓");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "       ▓▓████████▓▓▓▓██████████████████████████████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "         ████████████████████████████████████████████████████░░");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "           ████████████████████████████████████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "             ████████████████████████████████████████████░░");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "               ▒▒████████████████████████████████████▓▓");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "                   ▓▓██████████████████████████████");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "                       ▒▒████████████████████▓▓");

            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(),
                "**************************************************************************");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(),
                "========== . FAILURE . ========== . FAILURE . ========== . FAILURE . =====");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(),
                "**************************************************************************");
        }
        else
        {
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "                                   ¶¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "                        ¶¶¶¶    ¶¶¶¶11¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "                        ¶¶1¶¶ ¶¶¶¶1111¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "                       ¶¶111¶¶¶1111111¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "                   ¶¶¶ ¶1111¶¶1111111¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "                   ¶11¶¶111¶¶111111¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "                   ¶11¶1111¶111111¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "                  ¶¶11¶111¶111111¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "                  ¶11¶111¶¶111111¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "                  ¶11¶111¶1111111¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "                 ¶11¶111¶11111111¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "                 ¶1¶111¶¶1111111¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "                ¶1¶¶111¶1111111¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "               ¶¶1¶111¶1111111¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "               ¶¶¶111¶11111111¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "              ¶¶¶11¶¶111111111¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "              ¶¶11¶¶111111¶¶¶1¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "             ¶11¶¶1111111¶111111¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "           ¶¶¶¶¶1111111¶¶11111111¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "          ¶¶¶1111111¶¶1111111111111¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "         ¶¶111111¶¶¶11111111111111111¶¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "         ¶111111¶¶1111111111111111111111¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "         ¶111111¶1111111111¶¶¶1111111111111¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "        ¶11111111111111111¶¶ ¶¶¶¶¶¶¶¶111111¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "       ¶¶111111111111111¶¶¶        ¶111111¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "       ¶11111111111¶¶¶¶¶¶          ¶111111¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "      ¶¶11111111111¶¶             ¶¶11111¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "      ¶111111111111¶              ¶¶11111¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "     ¶¶111111111111¶                ¶¶¶¶¶¶¶¶¶¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "     ¶1111111111111¶                ¶¶¶111111¶¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "     ¶1111111111111¶¶             ¶¶¶111111¶¶¶11¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "    ¶¶1111111111111¶¶¶         ¶¶¶1111111¶¶11111¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "    ¶1111111111111111¶¶¶¶¶¶¶¶¶¶¶111111111¶1111¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "    ¶111111111111111111¶¶¶¶11111111111111¶¶¶¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "   ¶111111111111111111111111111111111111111¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "  ¶111111111111111111111111111111111111111¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "¶¶11111111111111111111111111111111111111¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "111111111111111111111111111111111¶¶¶¶¶¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "111111111111111111111111111111¶¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "1111111111111111111111111111¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "111111111111111111111111111¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "1111111111111111111111111¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "111111111111111111111111¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "1111111111111111111111¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "111111111111111111¶¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "111111111¶¶¶¶¶¶¶¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "111111¶¶¶");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "¶¶¶¶¶¶¶");
        }
    }
    catch (const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    catch (...)
    {
        std::cerr << "Unknown exception occured" << std::endl;
        return (EXIT_FAILURE);
    }

    return (runStatus == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
