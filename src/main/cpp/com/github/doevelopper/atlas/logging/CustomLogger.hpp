
/*******************************************************************
* @file
 * @version  v0.0.
 * @date     2024/04/18 W 09:55:59
 * @brief    Main entry point of application
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2023 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_CUSTOMLOGGER_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_CUSTOMLOGGER_HPP

#include <cstdint>

#include <string>
#include <typeinfo>

#include <boost/core/demangle.hpp>
#include <boost/type_index.hpp>
#include <log4cxx/logger.h>

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
private:                                                                                                               \
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
protected:                                                                                                             \
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
private:                                                                                                               \
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
    enum class Level : std::uint32_t
    {
        /* user actions malfunctions ....*/
        EMERGENCY    = (1 << 0),    /* system is unusable. A panic condition was reported to all processes. */
        CRITICAL     = (1 << 1),
        FATAL        = (1 << 2),     /* critical conditions */
        ALERT        = (1 << 3),
        ERROR        = (1 << 4),    /* action must be taken immediately. A condition that should be corrected immediately.  */
        WARNING      = (1 << 5),    /* error conditions */
        INFO         = (1 << 6),    /* warning conditions */
        TRACE        = (1 << 7),    /* informational */
        DEBUG        = (1 << 8),     /* debug-level messages. A message useful for debugging programs.  */
        ADVISORY     = (1 << 9),
      /* software malfunctions */
        INHIBIT      = (1 << 10),   /* System should be restarted.  */
        HINDENBUG    = (1 << 11),   /* bug with catastrophic behavior.*/
        MANDELBUG    = (1 << 12),   /* Behavior appear chaotic or even non-deterministic.*/
        BOHRBUG      = (1 << 13),    /*They do not change their behavior and are relatively easily detected.*/
        HEISENBUG    = (1 << 14),    /* Disappear or alter its behavior when one attempts to study it.*/
        SCHRODINBUG  = (1 << 15),   /*Bug that manifests itself in running software after a programmer notices that the code should never have worked in the first place.*/
        HIGGS_BUGSON = (1 << 16)    /*bug that is predicted to exist based upon other observed conditions, but is difficult, if not impossible, to artificially reproduce in a development or test environment. */
    };

    class CustomLoggerPrivate;

    class CustomLogger
    {
       Q_DECLARE_PRIVATE(CustomLogger)
       Q_DEFAULT_COPY_MOVE(CustomLogger)
     public:
        CustomLogger() noexcept;
        virtual ~CustomLogger() noexcept;

        explicit CustomLogger(std::uint32_t loggerWatchDelay);
        void configure();
        void reset ( );
    protected:
    private:
        void loggerConfigure(std::string const & configFilename);
        void addConsoleAppender();
        void addFileAppender(log4cxx::LoggerPtr logger, std::string filename, bool append);
        void addRollingfileAppender(log4cxx::LoggerPtr logger, std::string filename, bool
        append, int bkup_index , std::string filesize);
        std::string getFileExtension ( const std::string & s );
        void loadConfig ( const std::string & configFilename );
        void loadConfigAndWatch ( const std::string & configFilename );
        [[nodiscard]] std::uint32_t periodicalCheck ( ) const;
        void periodicalCheck ( std::uint32_t delay );

        std::shared_ptr<CustomLoggerPrivate> d_ptr;
        std::uint32_t m_loggerConfigWatchDelay{};
    };
}

#endif
