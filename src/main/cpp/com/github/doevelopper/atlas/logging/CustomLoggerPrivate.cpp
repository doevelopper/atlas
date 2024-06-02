
/*******************************************************************
* @file
 * @version  v0.0.
 * @date     2024/04/18 W 09:55:59
 * @brief    Main entry point of application
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2023 ACME Technology Corp. All rights reserved.
********************************************************************/


#include <com/github/doevelopper/atlas/logging/CustomLoggerPrivate.hpp>

using namespace com::github::doevelopper::atlas::logging;

CustomLoggerPrivate::CustomLoggerPrivate() noexcept
{
}

CustomLoggerPrivate::~CustomLoggerPrivate() noexcept
{

}

CustomLoggerPrivate::CustomLoggerPrivate(std::uint32_t delay)
{
}

bool CustomLoggerPrivate::initLogger()
{
    return (this->checkLogManagerStatus());
}

bool CustomLoggerPrivate::checkLogManagerStatus()
{
 //     // LOG4CXX_TRACE(LOG,"Logger::checkLogManagerStatus");
 //     // Check that we have not accidentally triggered configuration.
 //     // Paranoia due to "When the LogManager class is loaded into memory the
 //
 //     // default initialization procedure is initiated" in LogManager Doxygen.
    return (log4cxx::LogManager::getLoggerRepository()->isConfigured());
}
