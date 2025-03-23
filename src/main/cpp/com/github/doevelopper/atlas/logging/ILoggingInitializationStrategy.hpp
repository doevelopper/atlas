/*******************************************************************
* @file
 * @version  v0.0.
 * @date     02/11/24 W 13:39
 * @brief
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_ILOGGINGINITIALIZATIONSTRATEGY_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_ILOGGINGINITIALIZATIONSTRATEGY_HPP

#include <cstdint>

#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/consoleappender.h>
#include <log4cxx/patternlayout.h>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace com::github::doevelopper::atlas::logging
{
    /**
     * @class ILoggingInitializationStrategy
     * @brief A class to initialize the Log4CXX logging library in various ways.
     *
     * This class provides methods to configure Log4CXX using a configuration file,
     * programmatic setup via a function, or a basic default configuration. It ensures
     * that initialization occurs only once and handles errors appropriately.
     */
    class ILoggingInitializationStrategy
    {
    public:
        /**
         * @enum ConfigType
         * @brief Specifies the type of configuration file used for initialization.
         */
        enum class ConfigType : std::uint8_t
        {
            PROPERTY, ///< Property file configuration (e.g., log4cxx.properties)
            XML,       ///< XML file configuration (e.g., log4cxx.xml)
            ENV,
            CLI
        };
        ILoggingInitializationStrategy() noexcept;
        ILoggingInitializationStrategy(const ILoggingInitializationStrategy&) = delete;
        ILoggingInitializationStrategy(ILoggingInitializationStrategy&&) = default;
        ILoggingInitializationStrategy& operator=(const ILoggingInitializationStrategy&) = delete;
        ILoggingInitializationStrategy& operator=(ILoggingInitializationStrategy&&) = default;
        virtual ~ILoggingInitializationStrategy() noexcept;

        virtual void initialize() const = 0;
    protected:
    private:
    };

}

#endif
