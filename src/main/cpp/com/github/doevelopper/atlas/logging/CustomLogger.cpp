
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
#include <filesystem>

#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>
#include <com/github/doevelopper/atlas/logging/CustomLoggerPrivate.hpp>

using namespace com::github::doevelopper::atlas::logging;

CustomLogger::CustomLogger() noexcept
    : d_ptr(new CustomLoggerPrivate())
    , m_loggerConfigWatchDelay(100000UL)
{
    Q_D(CustomLogger);
    this->configure();
}

CustomLogger::~CustomLogger() noexcept
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);
    Q_D(CustomLogger);

    if (log4cxx::LogManager::getLoggerRepository()->isConfigured())
    {
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "---- END LOGGING -----");
    }

    log4cxx::LogManager::shutdown();
}

CustomLogger::CustomLogger(std::uint32_t loggerWatchDelay)
    : d_ptr(new CustomLoggerPrivate(loggerWatchDelay))
    , m_loggerConfigWatchDelay(loggerWatchDelay)
{
    Q_D(CustomLogger);
}

void CustomLogger::configure()
{
    Q_D(CustomLogger);

    if ( log4cxx::LogManager::getLoggerRepository ( )->isConfigured ( ) )
    {
        // throw std::logic_error ( "t initialisation, found that log4cxx configuration" );
        // LOG_CA_FUNC(std::cout) <<  "initialisation, found that log4cxx configuration";
    }

    std::string initialDisplayMessage = std::string("----START LOGGING-----");

    if (const char* wwatchDelay = std::getenv("LOG4CXX_CONFIGURATION_WATCH_SECONDS"))
    {
        try
        {
            periodicalCheck (static_cast<std::uint32_t>( std::stoi( std::string(wwatchDelay))));
        }
        catch(const std::invalid_argument& e)
        {
            std::cerr << "Invalid Arg: " << e.what() << std::endl;
        }
        catch(const std::out_of_range& e)
        {
            std::cerr << "Out of range: " << e.what() << std::endl;
        }
    }

    if (const char* env_p = std::getenv("LOG4CXX_CONFIGURATION"))
    {
        if ( ::access ( env_p, R_OK ) == 0 )
        {
#if APR_HAS_THREADS

            // this->loadConfigAndWatch(log4cxx::File( configurationPath.c_str( )).getPath( ));
            this->loadConfigAndWatch ( env_p );
#else

            // this->loadConfig(log4cxx::File( configurationPath.c_str( )).getPath( ));
            this->loadConfig ( env_p );
#endif
        }
    }
    else
    {
        // std::cerr << "LOG4CXX_CONFIGURATION not defined. Configuring default..." << std::endl;
        this->addConsoleAppender();
        initialDisplayMessage.append(std::string("Internal logging system configured."));
    }

    log4cxx::LogManager::getLoggerRepository()->getRootLogger()->info(initialDisplayMessage);
    LOG4CXX_TRACE(
        log4cxx::Logger::getRootLogger(),
        "Logging service initialized with " << log4cxx::Logger::getRootLogger()->getAllAppenders().size() << " appenders");
}

void CustomLogger::reset()
{
    LOG4CXX_TRACE ( log4cxx::Logger::getRootLogger ( ), __LOG4CXX_FUNC__ );
    log4cxx::LogManager::resetConfiguration ( );
    log4cxx::BasicConfigurator::resetConfiguration ( );
}

void CustomLogger::loggerConfigure(std::string const& configFilename)
{
    if (log4cxx::LogManager::getLoggerRepository()->isConfigured())
    {
        if (std::filesystem::path(configFilename).extension().compare(".xml") == 0)
        {
#if APR_HAS_THREADS
            log4cxx::xml::DOMConfigurator::configureAndWatch(configFilename, static_cast<long>(m_loggerConfigWatchDelay));
#else
            log4cxx::xml::DOMConfigurator::configure(configFilename);
#endif
        }
        else
        {
#if APR_HAS_THREADS
            log4cxx::PropertyConfigurator::configureAndWatch(configFilename, static_cast<long>(m_loggerConfigWatchDelay));
#else
            log4cxx::PropertyConfigurator::configure(configFilename);
#endif
        }
    }
    else
    {
        LOG4CXX_WARN(log4cxx::Logger::getRootLogger(), "log4cxx configuration detected.");
    }
}

void CustomLogger::addConsoleAppender()
{
    log4cxx::PatternLayoutPtr layout(new log4cxx::PatternLayout(LOG4CXX_STR("%d{yyyy-MM-dd HH:mm:ss.SSS} %Y [%-6p] %y - [%15.15t] - %-35c{1.} -- %Y %m%y%n")));
    log4cxx::ConsoleAppenderPtr consoleAppender(new log4cxx::ConsoleAppender(layout));
    log4cxx::helpers::Pool pool;
    log4cxx::File file;
    consoleAppender->activateOptions(pool);
    log4cxx::BasicConfigurator::configure(consoleAppender);
    log4cxx::Logger::getRootLogger()->setLevel(/*LOG_LEVEL*/ true ? log4cxx::Level::getTrace() : log4cxx::Level::getInfo());
    log4cxx::LogManager::getLoggerRepository()->setConfigured(true);
}

void CustomLogger::addFileAppender(log4cxx::LoggerPtr logger, std::string filename, bool append)
{
    log4cxx::PatternLayoutPtr layout(new log4cxx::PatternLayout(LOG4CXX_STR("%d{yyyy-MM-dd HH:mm:ss.SSS} [%-6p] - [%15.15t] - %-35c{1.} -- %m%n")));
    // log4cxx::PatternLayout *playout = new log4cxx::PatternLayout(layout);
    // log4cxx::FileAppender *appender = new log4cxx::FileAppender(log4cxx::LayoutPtr(playout),
    // filename, append); log4cxx::helpers::Pool pool; appender->activateOptions(pool);
    // logger->addAppender(appender);
}

void CustomLogger::addRollingfileAppender(log4cxx::LoggerPtr logger, std::string filename, bool append, int bkup_index,
 std::string filesize)
{
    // logDir+"/"+filename+".log";
    log4cxx::LogString size("200MB");
    log4cxx::PatternLayoutPtr layout(new log4cxx::PatternLayout(LOG4CXX_STR("%d{yyyy-MM-dd HH:mm:ss.SSS} [%-6p] - [%15.15t] - %-35c{1.} -- %m%n")));
    log4cxx::rolling::RollingFileAppenderPtr  appender;// = new |(layout,filename,append);
    appender->setMaxBackupIndex(bkup_index);
    appender->setMaxFileSize(filesize);
    log4cxx::helpers::Pool pool;
    appender->setBufferSize(1024);
    appender->setBufferedIO(false);
    appender->activateOptions(pool);
    logger->addAppender(appender);
}

std::string CustomLogger::getFileExtension(const std::string& s)
{
    LOG4CXX_TRACE ( log4cxx::Logger::getRootLogger ( ), __LOG4CXX_FUNC__ );
    size_t i = s.rfind ( '.', s.length ( ) );

    if ( i != std::string::npos ) { return ( s.substr ( i + 1, s.length ( ) - i ) ); }

    return ( "" );
}

void CustomLogger::loadConfig(const std::string& configFilename)
{
    if ( log4cxx::LogManager::getLoggerRepository ( )->isConfigured ( ) )
    {
        if ( ! configFilename.empty ( ) )
        {
            if ( configFilename.find ( ".xml" ) != std::string::npos )
            {
                log4cxx::xml::DOMConfigurator::configure ( configFilename );

                // log4cxx::xml::DOMConfigurator::configure( log4cxx::File( configFilename ).getPath( ) );
            }
            else
            {
                log4cxx::PropertyConfigurator::configure ( configFilename );
            }
        }
    }
    else
    {
        LOG4CXX_WARN ( log4cxx::Logger::getRootLogger ( ), "log4cxx configuration detected." );
    }
}

void CustomLogger::loadConfigAndWatch(const std::string& configFilename)
{
    if ( log4cxx::LogManager::getLoggerRepository ( )->isConfigured ( ) )
    {
        if ( ! configFilename.empty ( ) )
        {
            if ( configFilename.find ( ".xml" ) != std::string::npos )
            {
                log4cxx::xml::DOMConfigurator::configureAndWatch ( configFilename, static_cast< std::uint32_t > ( this->m_loggerConfigWatchDelay) );
            }
            else
            {
                log4cxx::PropertyConfigurator::configureAndWatch ( configFilename,  static_cast< std::uint32_t > ( this->m_loggerConfigWatchDelay) );
            }
        }
    }
    else
    {
        LOG4CXX_WARN ( log4cxx::Logger::getRootLogger ( ), "log4cxx configuration detected." );
    }
}

std::uint32_t CustomLogger::periodicalCheck() const
{
    // LOG4CXX_TRACE ( log4cxx::Logger::getRootLogger ( ), __LOG4CXX_FUNC__ );

    return ( this->m_loggerConfigWatchDelay );
}

void CustomLogger::periodicalCheck(std::uint32_t delay)
{
  // LOG4CXX_TRACE ( log4cxx::Logger::getRootLogger ( ), __LOG4CXX_FUNC__ );
  this->m_loggerConfigWatchDelay = delay;
}
