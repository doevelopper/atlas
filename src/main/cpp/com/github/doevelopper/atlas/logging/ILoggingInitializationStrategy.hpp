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
#include <iostream>
#include <memory>
#include <typeinfo>
#include <boost/core/demangle.hpp>
#include <boost/type_index.hpp>

#include <apr-1/apr.h>
#include <log4cxx/appender.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/consoleappender.h>
#include <log4cxx/fileappender.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/logger.h>
#include <log4cxx/logmanager.h>
#include <log4cxx/logstring.h> // has typedefed string type used in log4cxx
// #include <log4cxx/net/socketappender.h>
#include <stdexcept>
#include <string>
#include <log4cxx/nt/nteventlogappender.h>
#include <log4cxx/nt/outputdebugstringappender.h> // NT OUTPUTDEBUGSTRING Appender
#include <log4cxx/patternlayout.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/rolling/fixedwindowrollingpolicy.h>
#include <log4cxx/rolling/rollingfileappender.h>
#include <log4cxx/rolling/rollingpolicy.h>
#include <log4cxx/rolling/rollingpolicybase.h>
#include <log4cxx/rolling/sizebasedtriggeringpolicy.h>
#include <log4cxx/rolling/triggeringpolicy.h>
#include <log4cxx/simplelayout.h>
#include <log4cxx/xml/domconfigurator.h>

#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/consoleappender.h>
#include <log4cxx/patternlayout.h>
#include <com/github/doevelopper/atlas/API_Export.hpp>



/*!
 * @ingroup LoggingService
 * @brief Define static logger as private member.
 * @attention
 * <ul>
 *   <li>May change the scope of attributes to private in not define in private section.</li>
 * </ul>
 * @retval None.
 * @see
 * @since
 */

#define LOG4CXX_DECLARE_STATIC_LOGGER                                                                                  \
    private:                                                                                                           \
    \
        static log4cxx::LoggerPtr logger;

/*!
 * @ingroup LoggingService
 * @brief Define static logger as protected member.
 * @attention
 * <ul>
 *   <li>May change the scope of attributes to protected if not define in private section.</li>
 * </ul>
 * @retval None.
 */

#define LOG4CXX_DECLARE_STATIC_TEST_LOGGER                                                                             \
    protected:                                                                                                         \
    \
        static log4cxx::LoggerPtr logger;


#define LOG4CXX_DEFINE_CLASS_LOGGER_BY_ID(i)                                                                           \
    (boost::core::demangle(typeid(i).name()))

#define LOG4CXX_DEFINE_CLASS_LOGGER(name)                                                                              \
    log4cxx::Logger::getLogger(std::string(boost::core::demangle(name)));
/*!
 * @ingroup LoggingService
 * @brief Define logger as private member.
 * @param[in,out] name name of logguer to  be used within the class
 */

#define LOG4CXX_DECLARE_CLASS_LOGGER(name)                                                                             \
    private:                                                                                                           \
        \
        log4cxx::LoggerPtr name;

#define DEFAULT_LOGGER()                                                                                               \
    log4cxx::Logger::getRootLogger()

#define DEFINE_LOGGER                                                                                                  \
    std::string logger {boost::typeindex::type_id<decltype(*this)>().pretty_name()};

/*!
 * @ingroup LoggingService
 * @brief Mcrot for ease tracing entry end exit of function.
 */
#define LOG_FUNCTION(x) LOG4CXX_TRACE(logger, __FUNCTION__ << "(" << x << ")");


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
